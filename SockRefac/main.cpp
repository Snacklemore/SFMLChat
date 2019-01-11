#include <iostream>
#include <list>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <queue>

#include "ClientClass.h"//CLIENT REWORK DONE
#include "ServerClass.h"//SERVER REWORK DONE
#include "TextField.h"


class LoginPrompt{
public:
    LoginPrompt(){

    }

private:
};

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
    sf::Font font;
    if (!font.loadFromFile("arial.ttf"))
    {
        // error...
        std::cout <<"error loading fontfile" << std::endl;
    }
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

    ClientClass ClientObj;
    ClientObj.createThreads();


   //ClientObj.startClient();//replace startClient with appropriate login in sfml window
   /////////////////////////////////////////////////////////////////////////////////////
   /*1. Login Builder
    *
    * //////////////////////////////////////////////////////////////////////////////////
    */// run the program as long as the window is open

    sf::Event event;
    //TextField editField2(window,event,0,0);
    TextField editField(window,event,10,550);


    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop

        while (window.pollEvent(event))
        {

            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();


            editField.processEvents();
            //editField2.processEvents();


        }

        window.clear();
        editField.update();
        //editField2.update();

        window.display();



    }

    return 0;




}