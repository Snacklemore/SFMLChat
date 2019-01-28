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
    ClientClass clientOB;
    clientOB.createThreads();
    clientOB.startClient();
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");



   //ClientObj.startClient();//replace startClient with appropriate login in sfml window
   /////////////////////////////////////////////////////////////////////////////////////
   /*1. Login Builder
    *
    * //////////////////////////////////////////////////////////////////////////////////
    */// run the program as long as the window is open

    sf::Event event;
    TextField editField2(window,event,0,0);
    TextField editField(window,event,10,550);
    editField2.setNonEditable();
    editField2.setPosition(sf::Vector2f(10,120));
    editField2.setSize(sf::Vector2f(500,320));
    editField2.createStandardWidget();

    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop

        while (window.pollEvent(event))
        {

            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
            {

                window.close();


            }



            editField.processEvents();
            editField2.processEvents();


        }
        clientOB.globalMutex.lock();
        clientOB.msgQueue.push(MessageObject(editField.getOutput()));
        editField.clearOutput();

        if(!clientOB.msgQueueInc.empty()){
            editField2.setText(clientOB.msgQueueInc.front().getMsgData());
            clientOB.msgQueueInc.pop();
        }

        clientOB.globalMutex.unlock();

        window.clear();
        editField.update();
        editField2.update();

        window.display();



    }
    clientOB.destroyThreads();
    return 0;






}