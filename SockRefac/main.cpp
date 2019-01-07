#include <iostream>
#include <list>
#include <SFML/Network.hpp>
#include <queue>
#include "ClientClass.h"//CLIENT REWORK DONE



int main(int argc, char* argv[])
{
    for(int i = 1; i < argc; ++i) {
        std::string currentArg = argv[i];
        if (currentArg == "--server") {
            std::cout << "Starting server "<< std::endl;
            ServerClass serverObject;
            serverObject.startThread();
            serverObject.startServer();
            return 0;
        }

    }
    ClientClass ClientObj;
    ClientObj.createThreads();
    ClientObj.startClient();

}
