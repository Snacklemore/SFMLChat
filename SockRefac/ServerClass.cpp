//
// Created by Chapo on 06.01.2019.
//


#include "ServerClass.h"

std::string *ServerClass::buildNameTag(int num) {
    if ( num == 1)
    {
        std::cin.clear();
        std::cin.sync();
        const int inputSize = 256;
        char inputBuf[inputSize] ={0};
        char nameBuf[inputSize] ={0};
        std::string* nametag = new std::string(": ");
        std::cout << "Please enter nickname";
        std::cin.getline(nameBuf,inputSize);
        *nametag = (std::string)nameBuf + *nametag;
        std::transform(nametag->begin(),nametag->end(),nametag->begin(), ::tolower);
        std::cout << *nametag << std::endl;
        return  nametag;
    }else if (num == 2)
    {
        std::string* serverstr = new std::string("Server: ");
        return serverstr;


    }
    return nullptr;
}

void ServerClass::sendDataToAllClients() {
    while (!quit)
    {
        globalMutex.lock();

        if(clientList.empty())
        {
            globalMutex.unlock();
            continue;
        }


        std::string msgSend;

        if(msgQueue.empty())
        {
            globalMutex.unlock();
            continue;
        }

        msgSend=msgQueue.front().getMsgData();
        std::string MSGroomtype= msgQueue.front().Room;
        msgQueue.pop();

        globalMutex.unlock();

        if(MSGroomtype == "SERVER"){
            for(std::vector<ClientObject>::iterator it = clientList.begin();it != clientList.end();++it)
            {
                ClientObject& client = *it;
                sf::Packet packetSend;
                if(!msgSend.empty())
                {
                    packetSend << msgSend;
                    client.clientSocket->send(packetSend);
                }
            }
        } else
            {
            //msgSend wont store all necessary data here, only clientname, roomlocation needs to get form msgQueue
            //grab msg, check msg for sender and location, send message to clients matching the location.
            //privat chatrooms are unigue locations
            for(std::vector<ClientObject>::iterator it = clientList.begin();it != clientList.end();++it)
            {
                ClientObject& client = *it;
                std::string CLIENTRoomType = client.Room;

                sf::Packet packetSend;
                if(!msgSend.empty())
                {
                    if (CLIENTRoomType == MSGroomtype)
                    {
                        packetSend << msgSend;
                        client.clientSocket->send(packetSend);
                    }


                }
            }
        }

        msgSend.clear();

    }

}

void ServerClass::startServer() {
    sendDataThread->launch();
    nameTagCopy = buildNameTag(2);
    listener.listen(5001);
    test.add(listener);




    sf::TcpSocket *sockPtr = nullptr;
    std::vector<ClientObject>::iterator it_;
    while (!quit) {


        if (test.wait()) {

            if (test.isReady(listener)) {
                sf::TcpSocket *client = new sf::TcpSocket;
                if (listener.accept(*client) == sf::Socket::Done) {
                    sf::Packet packet;
                    client->receive(packet);//recieving name
                    std::string s;
                    packet >> s;
                    std::string clientJoin = *nameTagCopy + s + "joined the Server!";
                    MessageObject clientJoined(clientJoin);
                    clientJoined.Room= "SERVER";
                   //
                    ClientObject CO(clientList.size(), client);
                    CO.Room = "mainRoom";
                    CO.name = s;

                    clientList.emplace_back(CO);
                    msgQueue.push(clientJoined);

                    test.add(*client);

                    std::cout << "New client connected: " + s + "with IP:" << client->getRemoteAddress() << std::endl;
                } else {
                    delete client;
                }
            } else {
                //not rdy all clients
                for (std::vector<ClientObject>::iterator it = clientList.begin(); it != clientList.end(); ++it) {

                    /*
                     *A and B want to chat privately, A sends private ChatRequest to B, B gets prompt to accept.
                     * B accepts the request. A and B get flagged as inside private chat room, therefore
                     * A wont receive any messages except they are from B, and B wont receive any messages except
                     * they are from A.
                     * same for other chat rooms, msg send from one room will only be send to clients in that specific
                     * room
                    */
                    ClientObject &client = *it;// ClientObject needs attribute to recognize where msg was send from, main room or privat chat room
                    if (test.isReady(*client.clientSocket)) {
                        sf::Packet packet;
                        if (client.clientSocket->receive(packet) == sf::Socket::Done) {
                            //write to msg:
                            //queue
                            std::string msg;
                            packet >> msg;
                            if (!msg.empty()) {
                                //get the name of client who send the msg
                                //std::string CLIENTName = msgSend.substr(msgSend.find(':'));
                                //get the message text
                                std::string strhlp = msg;
                                strhlp.erase(0, strhlp.find(
                                        ':'));//message w/out nametag, 1. char contains = ':' 2.char contains whitespace followed by actual message
                                strhlp.erase(0, 2);//cut white space and :
                                if (strhlp[0] != '#') {
                                    std::cout << "ServerLog:" << msg << std::endl;
                                    MessageObject msgO(msg);
                                    msgO.Room = client.Room;//same for MessageObject, need a way to send it to right client
                                    msgQueue.push(msgO);
                                } else {
                                    //Tokenize command message
                                    std::vector<std::string> cmdTokens;
                                    std::stringstream check1(msg);
                                    std::string intermediate;
                                    while (getline(check1,intermediate,' '))
                                    {
                                        cmdTokens.push_back(intermediate);
                                    }
                                    //cmdTokens is now filled with:
                                    //1. Token: nametag
                                    //2. Token: Command
                                    //3. Token: arguments

                                    if (cmdTokens[1].find("changeRoom") != std::string::npos)
                                    {
                                        if (cmdTokens.size() == 2){
                                            client.Room = "mainRoom";
                                        } else{
                                            client.Room = cmdTokens[2];
                                        }


                                    }else
                                        std::cout << "command not found" << std::endl;
                                }

                            }


                        } else if (client.clientSocket->receive(packet) == sf::Socket::Disconnected) {

                            sockPtr = client.clientSocket;
                            it_ = it;

                        }
                    }

                }
                if (sockPtr != nullptr) {

                    std::cout << it_->name +"disconnected from server"<< std::endl;
                    std::string clientDisconnect = *nameTagCopy + it_->name + "left the Server!";
                    MessageObject clientDisc(clientDisconnect);
                    clientDisc.Room= "SERVER";
                    if(clientList.size() > 1)
                        msgQueue.push(clientDisc);

                    test.remove(*sockPtr);
                    sockPtr->disconnect();
                    delete sockPtr;
                    clientList.erase(it_);
                    std::cout << "client disc" << std::endl;
                    std::cout << clientList.size() << " clients left" << std::endl;
                    sockPtr = nullptr;
                }

            }
        }

    }
}
