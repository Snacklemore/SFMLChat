#include <iostream>
#include <list>
#include <SFML/Network.hpp>
#include <queue>
#include "ClientClass.h"//CLIENT REWORK DONE



int main(int argc, char* argv[])
{
    ClientClass ClientO;

   ClientO.createThreads();
    ClientO.startClient();
}