//
// Created by Chapo on 09.01.2019.
//

#ifndef SOCKREFAC_TEXTFIELD_H
#define SOCKREFAC_TEXTFIELD_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Cursor.h"
#include "MessageWidget.h"

//TODO: STILL NEEDS A WAY TO SHRINK EDIT BOX WHEN DELETING MESSAGE WITH BACKSPACE
// Something like: Shrink box when lines = 1, that way we going to need to count \n in string decreasing lines per \n
class TextField {
public:
    sf::RenderWindow &m_window;
    sf::Event &m_event;
    TextField(sf::RenderWindow &window,sf::Event &event,float x,float y):m_window(window),m_event(event)
    {
        TextBox.setSize(sf::Vector2f(500.f, 25.f));
        TextBox.setPosition(sf::Vector2f(x,y));
        baseSize = sf::Vector2f(500.f, 25.f);
        basePos = sf::Vector2f(x,y);
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
       _cursor= new Cursor(sf::milliseconds(100000),font,sf::Color::Red);
       sf::Vector2f pos = TextBox.getPosition();
       pos.x = pos.x +1;
       pos.y = pos.y +21;
       _cursor->setPosition(pos);

        if (!font.loadFromFile("arial.ttf"))
        {
            // error...

        }

    }

    bool isTextOutside();
    void clearOutput();
    std::string getOutput();
    void setNonEditable();
    void processEvents();
    void update();
    void setSize(sf::Vector2f size);
    void addWidget(MessageWidget *widget);
    void deleteWidget(MessageWidget *widget);
    MessageWidget* getWidget(int index);
    void setActive();
    bool isActivated();
    void growEditBox();
    void setText(std::string stri);
    void setPosition(sf::Vector2f pos);
    sf::Vector2f getPos();
    size_t getCursor();

private:
    std::vector<MessageWidget*> messageWidgetList;
    sf::Vector2f baseSize;
    sf::Vector2f basePos;
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
