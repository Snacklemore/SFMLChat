//
// Created by Chapo on 06.01.2019.
//

#ifndef SOCKREFAC_CLIENTCLASS_H
#define SOCKREFAC_CLIENTCLASS_H

#include <SFML/Network.hpp>

#include <iostream>
#include <algorithm>
#include <SFML/System/Thread.hpp>
#include <queue>
#include <SFML/System/Mutex.hpp>
#include <SFML/Graphics/Text.hpp>
#include "MessageObject.h"
#include "ClientObject.h"
inline bool containsStr(std::string source,std::string searchStr)
{
    return source.find(searchStr) != std::string::npos;
}

class ClientClass {
public:
    ClientClass(){

    }
    void createThreads(){
        ClientSendingThread = new sf::Thread(&ClientClass::ClientSendingLoop,this);
        ClientReceivingThread = new sf::Thread(&ClientClass::ClientRec,this);
        //ClientDisplayThread = new sf::Thread(&ClientClass::ClientDisplay,this);
    }
    void destroyThreads()
    {
        ClientReceivingThread->terminate();
        ClientSendingThread->terminate();
        delete ClientSendingThread;
        delete ClientReceivingThread;
    }
    bool startClient();//former Client(), not threaded
    void ClientSendingLoop();//threaded
    void ClientRec();//threaded
    bool isOwnMessage(std::string msg)
    {
        return containsStr(msg, *nameTagCopy);
    }
    void ClientDisplay();//threaded
    std::string* buildNameTag(int num);
    void GetInput();//looped in main
    std::string *nameTagCopy;
    sf::Mutex globalMutex;
    sf::Thread* ClientSendingThread = 0;
    sf::Thread* ClientReceivingThread = 0;
    //sf::Thread* ClientDisplayThread = 0;
    sf::TcpSocket socket;
    bool quit = false;
    std::queue<MessageObject> msgQueue;
    std::queue<MessageObject> msgQueueInc;

private:



};


#endif //SOCKREFAC_CLIENTCLASS_H
