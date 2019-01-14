//
// Created by Chapo on 06.01.2019.
//
//flagged all functions using std::cout as subject to change, genereal behaviour should stay the same

#include "ClientClass.h"
void ClientClass::ClientSendingLoop() {//probably no rework needed here

    static std::string oldMsg;
    while (!quit) {
        globalMutex.lock();
        if (msgQueue.empty()) {
            globalMutex.unlock();
            continue;
        }
        if(msgQueue.front().getMsgData() == " " || msgQueue.front().getMsgData().empty()) {
            msgQueue.pop();
            globalMutex.unlock();
            continue;
        }
        globalMutex.unlock();

        sf::Packet packetSend;
        globalMutex.lock();
        packetSend << *nameTagCopy + msgQueue.front().getMsgData();
        msgQueue.pop();
        globalMutex.unlock();


        socket.send(packetSend);

    }
}

void ClientClass::ClientRec() {
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

void ClientClass::ClientDisplay() {//needs rework
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

std::string *ClientClass::buildNameTag(int num) {//rework needed
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

void ClientClass::GetInput() {
    std::string s;

    getline(std::cin,s);
    // if(s == "exit")
    //    quit = true;
    globalMutex.lock();
    msgQueue.push(MessageObject(s));
    globalMutex.unlock();

}

bool ClientClass::startClient() {//needs rework
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

    if(socket.connect(IPADDRESS, PORT) == sf::Socket::Done)
    {
        sf::Packet namePack;
        std::string *nameStr=nameTagCopy;
        namePack << *nameStr;
        socket.send(namePack);

        std::cout << "Connected to " << socket.getRemoteAddress() << std::endl;
        ClientReceivingThread->launch();
        ClientSendingThread->launch();
        //ClientDisplayThread->launch();
        /*while (!quit){
            GetInput();
        }*/

        return true;
    }
    std::cout << "Connection fail, remote Host not reachable, terminating now" << std::endl;
   getline(std::cin,IPADDRESS);
    return false;
}
