#include <iostream>
#include <list>
#include <SFML/Network.hpp>
#include <queue>

/////////////////////////////////////////////////////////////////
//basic chat with sfml, one socket for server, one socket for client
//threaded sending and receiving,nametag for client, servertag for server
//no reconnecting to server -.-
bool containsStr(std::string source,std::string searchStr)
{
    return source.find(searchStr) != std::string::npos;
}


/////////////////////////////////////////////////////////////////
class ClientObject{
public:
    ClientObject(int nameid,sf::TcpSocket *cSocket){
        nameID = nameid+3*11;
        clientSocket = cSocket;

    }
    int nameID;
    std::string name;
    std::string Room;
    sf::TcpSocket* clientSocket;
};
class MessageObject{
public:
    MessageObject(std::string data)
    {
        msgData = data;
    }
    std::string Room;
    ClientObject *CObject= nullptr;
    std::string getMsgData(){
        return msgData;
    }
    void setMsgData(std::string val){
        msgData = val;
    }
    void setSender(std::string val)
    {
        sender = val;
    }
private:
    std::string msgData;
    std::string sender;
};

//const unsigned short PORT = 5000;
//const std::string IPADDRESS("127.0.0.1");//change to suit your needs

std::string msgSend;

std::queue<MessageObject> msgQueue;
std::queue<MessageObject> msgQueueInc;
sf::TcpSocket socket;

sf::Mutex globalMutex;

bool quit = false;
std::vector<ClientObject> clientList;
std::string* nameTagCopy;
bool ClientBool,ServerBool;
bool isClient()
{
    return ClientBool;
}
bool isServer()
{
    return ServerBool;
}
void ClientSendingLoop(void)//need a third loop for incoming messages also threaded consuming from a shared res
{
    static std::string oldMsg;
    while (!quit) {
        globalMutex.lock();
        if(msgQueue.empty())
        {
            globalMutex.unlock();
            continue;
        }
        globalMutex.unlock();

        sf::Packet packetSend;
        globalMutex.lock();
        packetSend << *nameTagCopy+msgQueue.front().getMsgData();
        msgQueue.pop();
        globalMutex.unlock();


        socket.send(packetSend);
        //globalMutex.lock();
        // msgSend.clear();
        //globalMutex.unlock();

        /*
        std::string msg;
        sf::Packet packetReceive;


        socket.receive(packetReceive);
        //std::string teststr = rmNameTag(msg);
        if ((packetReceive >> msg) && oldMsg != msg && !msg.empty() )
        {
            std::cout << msg << std::endl;
            oldMsg = msg;
        }
        if(containsStr(msg,"exit"))
        {
            if (isServer())
            {
                std::cout << "server Closing Connecntion"<< std::endl;
                sf::Packet exitPacket;
                exitPacket << "exit";
                if (socket.send(exitPacket))
                    socket.disconnect();

                quit = true;
            }else if(isClient())
            {

                std::cout << "Server shutdown connection" << std::endl;
                socket.disconnect();
                quit = true;
            }
        }



void Server()//not threaded selector to check for incoming, write them to buffer,eg. message queue+new thread for sending queue to clients
{
    sf::TcpListener listener;
    unsigned short PORT;
    std::string porthlp;
    std::cin.clear();
    std::cin.sync();
    std::cout << "\nEnter Port, please";
    nameTagCopy=buildNameTag(2);
    getline(std::cin,porthlp);
    PORT = std::stoi(porthlp);


    listener.listen(PORT);
    ServerBool=true;
    ClientBool=false;
    while (!quit)
    {


        if (test.wait())
        {
            std::cout << clientList.size() << std::endl;
            if (test.isReady(listener))
            {
                sf::TcpSocket* client = new sf::TcpSocket;
                if (listener.accept(*client)==sf::Socket::Done)
                {
                    //globalMutex.lock();
                    clientList.emplace_back(ClientObject(clientList.size(),client));
                    //globalMutex.unlock();
                    test.add(*client);

                    std::cout << "New client connected: " << socket.getRemoteAddress() << std::endl;
                } else
                {
                    delete client;
                }
            } else
            {
                //not rdy all clients
                for(std::vector<ClientObject>::iterator it = clientList.begin();it != clientList.end();++it)
                {
                    ClientObject& client = *it;
                    if(test.isReady(*client.clientSocket))
                    {
                        sf::Packet packet;
                        if (client.clientSocket->receive(packet)== sf::Socket::Done)
                        {
                            //write to msg:
                            //queue
                            std::string msg;
                            packet >> msg;
                            std::cout <<"ServerLog:"<< msg << std::endl;
                            MessageObject msgO(msg);
                            //globalMutex.lock();
                            msgQueue.push(msgO);
                           // globalMutex.unlock();
                        }
                    }
                }
            }
        }
    }
        //now we need another thread to send data collected on the messagequeue to all clients connected AND to specicifig clients only. fmlwhatmidoing
}*/
    }
}
void ClientRec(){
    while (!quit){
        sf::Packet packetRec;
        socket.receive(packetRec);
        std::string dataMsg;
        packetRec >> dataMsg;
        if (dataMsg.empty())
            continue;
        MessageObject msgObj(dataMsg);

        globalMutex.lock();
        msgQueueInc.push(msgObj);
        globalMutex.unlock();


    }
}
bool isOwnMessage(std::string msg)
{
    return containsStr(msg, *nameTagCopy);
}
void ClientDisplay(){
    while (!quit){
        globalMutex.lock();
        if(msgQueueInc.empty())
        {
            globalMutex.unlock();
            continue;
        }
        globalMutex.unlock();



        globalMutex.lock();
        if(isOwnMessage(msgQueueInc.front().getMsgData()) )
        {
            msgQueueInc.pop();
            globalMutex.unlock();
            continue;
        }
        std::cout << msgQueueInc.front().getMsgData() << std::endl;
        msgQueueInc.pop();
        globalMutex.unlock();
    }
}

std::string* buildNameTag(int num){//1client2server
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
        std::string* serverstr = new std::string("server: ");
        return serverstr;


    }
    return nullptr;

}
void sendDataToAllClients(){//call only on serverside
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
        msgSend.clear();

    }
}

bool Client()//set name then fork to multiuser
{
    std::string IPADDRESS,porthlp;
    unsigned short PORT;
    std::cin.clear();
    std::cin.sync();
    std::cout << "\nEnter IP, please:";

    getline(std::cin, IPADDRESS);
    std::cout << "\nEnter Port, please";

    getline(std::cin,porthlp);
    PORT = std::stoi(porthlp);
    nameTagCopy=buildNameTag(1);
    ClientBool = true;
    ServerBool = false;
    if(socket.connect(IPADDRESS, PORT) == sf::Socket::Done)
    {
        sf::Packet namePack;
        std::string *nameStr=nameTagCopy;
        namePack << *nameStr;
        socket.send(namePack);

        std::cout << "Connected to " << socket.getRemoteAddress() << std::endl;
        return true;
    }
    return false;

}

void GetInput()
{
    std::string s;

    getline(std::cin,s);
   // if(s == "exit")
    //    quit = true;
    globalMutex.lock();
    msgQueue.push(MessageObject(s));
    globalMutex.unlock();
}


int main(int argc, char* argv[])
{
    sf::SocketSelector test;
    sf::Thread* thread = 0;
    sf::Thread* thread1 = 0;
    sf::Thread* thread2 = 0;
    sf::Thread* thread3 = 0;
    //sf::Thread* thread4 = 0;
    sf::TcpListener listener;


    char who;
    std::cout << "Do you want to be a server (s) or a client (c) ? ";
    std::cin  >> who;

    if (who == 's') {
        thread1 = new sf::Thread(&sendDataToAllClients);
        thread1->launch();
        //Server();

        unsigned short PORT;
        std::string porthlp;
        //std::cin.clear();
        //std::cin.sync();
        //std::cout << "\nEnter Port, please";
        nameTagCopy = buildNameTag(2);
        //getline(std::cin,porthlp);
        PORT = 5001; //std::stoi(porthlp);


        listener.listen(PORT);//selector needs a port to listen, AND THEN ADD HIM U FKING MORRON

        test.add(listener);
        sf::TcpSocket *sockPtr = nullptr;
        std::vector<ClientObject>::iterator it_;
        ServerBool = true;
        ClientBool = false;
        while (!quit) {


            if (test.wait()) {

                if (test.isReady(listener)) {
                    sf::TcpSocket *client = new sf::TcpSocket;
                    if (listener.accept(*client) == sf::Socket::Done) {
                        sf::Packet packet;
                        client->receive(packet);//recieving name
                        std::string s;
                        packet >> s;
                        ClientObject CO(clientList.size(), client);
                        CO.Room = "mainRoom";
                        CO.name = s;

                        clientList.emplace_back(CO);

                        test.add(*client);

                        std::cout << "New client connected: " + s +"with IP:" << client->getRemoteAddress() << std::endl;
                    } else {
                        delete client;
                    }
                } else {
                    //not rdy all clients
                    for (std::vector<ClientObject>::iterator it = clientList.begin(); it != clientList.end(); ++it)
                    {

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
                                    strhlp.erase(0,strhlp.find(':'));//message w/out nametag, 1. char contains = ':' 2.char contains whitespace followed by actual message
                                    strhlp.erase(0,2);//cut white space and :
                                    if(strhlp[0] != '#')
                                    {
                                        std::cout << "ServerLog:" << msg << std::endl;
                                        MessageObject msgO(msg);
                                        msgO.Room = client.Room;//same for MessageObject, need a way to send it to right client
                                        msgQueue.push(msgO);
                                    } else
                                    {

                                        if (strhlp.find("changeRoom sub") != std::string::npos)
                                            client.Room = "SubRoom";
                                        else if (strhlp.find("changeRoom main"))
                                            client.Room = "mainRoom";
                                        else{
                                            std::cout << "Command not found" << std::endl;
                                        }
                                    }

                                }


                            } else if (client.clientSocket->receive(packet) == sf::Socket::Disconnected) {

                                sockPtr = client.clientSocket;
                                it_ = it;

                            }
                        }

                    }
                    if(sockPtr != nullptr)
                    {
                        test.remove(*sockPtr);
                        sockPtr->disconnect();
                        clientList.erase(it_);
                        std::cout << "client disc" << std::endl;
                        std::cout << clientList.size()<<" clients left" << std::endl;
                        sockPtr = nullptr;
                    }

                }
            }
        }
    }

    else
        Client();

    thread = new sf::Thread(&ClientSendingLoop);
    thread->launch();
    thread2 = new sf::Thread(&ClientRec);
    thread2->launch();
    thread3 = new sf::Thread(&ClientDisplay);
    thread3->launch();
    globalMutex.lock();
    std::cout << clientList.size()<< std::endl;

    std::cout << "\nEnter \"exit\" to quit or message to send: ";
    globalMutex.unlock();
    while(!quit)
    {
        GetInput();
    }

    if(thread)
    {
        thread->wait();
        delete thread;
    }
    return 0;
}