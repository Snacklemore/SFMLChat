//
// Created by Chapo on 06.01.2019.
//

#ifndef SOCKREFAC_SERVERCLASS_H
#define SOCKREFAC_SERVERCLASS_H

#include <iostream>
#include <SFML/Network.hpp>

#include <iostream>
#include <algorithm>
#include <SFML/System/Thread.hpp>
#include <queue>
#include <SFML/System/Mutex.hpp>
#include "MessageObject.h"
#include "ClientObject.h"
#include <sstream>

class ServerClass {
public:
    ServerClass(){

    }
    void startThread(){
        sendDataThread = new sf::Thread(&ServerClass::sendDataToAllClients, this);
    }
    std::string* buildNameTag(int num);
    void sendDataToAllClients();
    void startServer();
    unsigned short PORT = 5001;
private:
    sf::Thread* sendDataThread = 0;
    bool quit= false;
    std::string* nameTagCopy;
    std::vector<ClientObject> clientList;
    std::queue<MessageObject> msgQueue;
    sf::Mutex globalMutex;
    sf::SocketSelector test;
    sf::TcpListener listener;
};


#endif //SOCKREFAC_SERVERCLASS_H
