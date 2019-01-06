//
// Created by Chapo on 06.01.2019.
//

#ifndef SOCKREFAC_CLIENTOBJECT_H
#define SOCKREFAC_CLIENTOBJECT_H


#include <SFML/Network/TcpSocket.hpp>
#include <string>

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

#endif //SOCKREFAC_CLIENTOBJECT_H
