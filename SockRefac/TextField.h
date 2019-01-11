//
// Created by Chapo on 09.01.2019.
//

#ifndef SOCKREFAC_TEXTFIELD_H
#define SOCKREFAC_TEXTFIELD_H


#include <SFML/Graphics.hpp>
#include "Cursor.h"

class TextField {
public:
    sf::RenderWindow &m_window;
    sf::Event &m_event;
    TextField(sf::RenderWindow &window,sf::Event &event,float x,float y):m_window(window),m_event(event)
    {
        TextBox.setSize(sf::Vector2f(500.f, 25.f));
        TextBox.setPosition(sf::Vector2f(x,y));
        text.setPosition(sf::Vector2f(x,y));
        text.setFont(font);
        text.setCharacterSize(16);
        text.setFillColor(sf::Color::Red);
        text.setString(str);
        TextBox.setOutlineColor(sf::Color::Green);
        TextBox.setFillColor(sf::Color::Black);
        TextBox.setOutlineThickness(1);
        outPutStr = " ";
        isActive= false;
        editable = true;
       _cursor= new Cursor(sf::milliseconds(400),font,sf::Color::Red);
       _cursor->setPosition(sf::Vector2f(0,0));
        if (!font.loadFromFile("arial.ttf"))
        {
            // error...

        }

    }
    void clearOutput();
    std::string getOutput();
    void setNonEditable();
    void processEvents();
    void update();
    void setActive();
    bool isActivated();

    void setText(std::string stri);
    void setPosition(sf::Vector2f pos);
    sf::Vector2f getPos();
    size_t getCursor();

private:
    Cursor* _cursor;
    bool editable;
    bool isActive;
    sf::Font font;
    size_t cursorpos=0;
    sf::RectangleShape TextBox;
    std::string str;
    std::string outPutStr;
    sf::Text text;
};


#endif //SOCKREFAC_TEXTFIELD_H
