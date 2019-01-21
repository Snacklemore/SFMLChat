//
// Created by Chapo on 16.01.2019.
//

#ifndef SOCKREFAC_MESSAGEWIDGET_H
#define SOCKREFAC_MESSAGEWIDGET_H
#include "TextField.h"

class MessageWidget {
public:
    MessageWidget(){

    }
    void setText();
    std::string getText();
    void setName();
    void setWindowSize(sf::Vector2f size);
    void setPos(sf::Vector2f pos);
    sf::Vector2f getPos();

    TextField * owner;//unique pointer on owner Textfield, Owner
private:
    std::string widgetName;
    sf::RectangleShape window;
    sf::Text messageText;
};


#endif //SOCKREFAC_MESSAGEWIDGET_H
