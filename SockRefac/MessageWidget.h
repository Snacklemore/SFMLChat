//
// Created by Chapo on 16.01.2019.
//

#ifndef SOCKREFAC_MESSAGEWIDGET_H
#define SOCKREFAC_MESSAGEWIDGET_H

#include <SFML/Graphics.hpp>
#include <iostream>
class TextField;

class MessageWidget {
public:
    MessageWidget(sf::Vector2f size,sf::Vector2f pos,std::string name,std::string text){
        _window.setSize(size );
        _window.setPosition(pos);
        _widgetName = name;
       _window.setOutlineColor(sf::Color::Green);
        _window.setFillColor(sf::Color::Black);
        _window.setOutlineThickness(1);

        _messageText.setPosition(pos.x+4,pos.y+1);
        if (!font.loadFromFile("arial.ttf"))
        {
            // error...

        }
        //now check if text is getting ouf bounds.
        _messageText.setString(text);


        _messageText.setFont(font);
        _messageText.setCharacterSize(16);
        _messageText.setFillColor(sf::Color::Red);
        ///////////////////////////////////////////////////////
        ///////////PUT THIS IN DEDICATED TextWrapper FUNCTION//////
        ///////////////////////////////////////////////////////
        //trimmer which adds a newline when out of bounds also trimming the bounding box

        //check each character if in window
        sf::Vector2f pos1 = _messageText.findCharacterPos(text.size());
        if(!_window.getGlobalBounds().contains(pos1))
        {
            for(int i=text.size();i>0;i--)
            {
                if(_window.getGlobalBounds().contains(_messageText.findCharacterPos((size_t)i)))
                {

                    text.insert(i,"\n");
                    size.y = size.y +14;
                    _window.setSize(size);
                    _messageText.setString(text);
                    if (_window.getGlobalBounds().contains(_messageText.findCharacterPos(text.size())))
                    {
                        break;
                    } else
                         i = text.size();

                }
            }

        }



    }


    void setText(std::string str) {
        _messageText.setString(str);

    }
    sf::RectangleShape* getWindow() {
        sf::RectangleShape *ptr = &_window;
        return ptr;
    }

    sf::Text* getDrawText() {
        return &_messageText;
    }

    std::string getText() {
        return std::__cxx11::string();
    }

    void setName(std::string str) {

    }

    void setWindowSize(sf::Vector2f size) {

    }

    void setPos(sf::Vector2f pos) {

    }

    sf::Vector2f getPos() {
        return sf::Vector2f();
    }

    TextField* _owner;//unique pointer on owner Textfield, Owner
private:
    sf::Font font;
    std::string _widgetName;
    sf::RectangleShape _window;
    sf::Text _messageText;
};


#endif //SOCKREFAC_MESSAGEWIDGET_H
