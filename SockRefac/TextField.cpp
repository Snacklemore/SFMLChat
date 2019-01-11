//
// Created by Chapo on 09.01.2019.
//

#include "TextField.h"

void TextField::setText(std::string stri) {
    text.setString(stri);
}

sf::Vector2f TextField::getPos() {
    return TextBox.getPosition();
}

size_t TextField::getCursor() {
    return cursorpos;
}

void TextField::setPosition(sf::Vector2f pos) {
    TextBox.setPosition(pos);
    text.setPosition(pos);
}

void TextField::processEvents() {
    if (m_event.type == sf::Event::MouseButtonPressed)
    {
        if (m_event.mouseButton.button == sf::Mouse::Left)
        {
            setActive();
        }
    }
    if(isActive){
        if (editable)
        {
            if( m_event.type == sf::Event::TextEntered)
            {
                // Handle ASCII characters only
                if (m_event.text.unicode < 128 && m_event.text.unicode != 8)
                {
                    int textSize = str.size();
                    unsigned short unicode = m_event.text.unicode;
                    //need edit field inside a box
                    // 1. should be able to delete and backspace, confirming with enter or submit button


                    str += static_cast<char>(m_event.text.unicode);
                    cursorpos+=1;
                    sf::Vector2f pos = text.findCharacterPos(cursorpos);
                    //sf::Vector2f pos(_cursor->_Cursor.getPosition().x + 6,_cursor->_Cursor.getPosition().y);
                    _cursor->setPosition(pos);
                    text.setFont(font);
                    text.setCharacterSize(16);
                    text.setFillColor(sf::Color::Red);
                    text.setString(str);



                }
            }
            if(m_event.type == sf::Event::KeyPressed)
            {
                if (m_event.key.code == sf::Keyboard::Enter)
                {
                    //Put message on msgQueue
                    //text.setString(" ");
                    outPutStr = str;
                    str.clear();
                    cursorpos = 0;

                    //

                }
                if (m_event.key.code == sf::Keyboard::BackSpace)
                {

                    if (cursorpos > 0)
                    {
                        //std::string string = text.getString();
                        str.erase(cursorpos - 1);
                        cursorpos -=1;
                        text.setString(str);
                    }
                }
        }



        }


    }


}

void TextField::update() {
    m_window.draw(TextBox);
    m_window.draw(text);
    _cursor->update();
    if(_cursor->_show){

        m_window.draw(_cursor->_Cursor);
    }


}

void TextField::setActive() {

    isActive= TextBox.getGlobalBounds().contains(sf::Mouse::getPosition(m_window).x, sf::Mouse::getPosition(m_window).y);//mousePos,func for checking mouse pos


}

bool TextField::isActivated() {
    return isActive;
}

void TextField::setNonEditable() {
    editable = false;

}

std::string TextField::getOutput() {
    return outPutStr;
}

void TextField::clearOutput() {
    outPutStr.clear();

}
