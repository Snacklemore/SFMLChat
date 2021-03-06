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

    pos.x = pos.x +1;
    pos.y = pos.y +21;
    _cursor->setPosition(pos);
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
                if (m_event.text.unicode < 128 && m_event.text.unicode != 8 && m_event.text.unicode != 13)
                {
                    int textSize = str.size();
                    unsigned short unicode = m_event.text.unicode;



                    str += static_cast<char>(m_event.text.unicode);
                    cursorpos+=1;
                    sf::Vector2f pos = text.findCharacterPos(str.size());
                    if(isTextOutside())
                    {
                        str +='\n';
                        growEditBox();
                        cursorpos = 0;
                        _cursor->line+=1;

                    }
                    pos.y = pos.y + 21;

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

                    outPutStr = str;
                    str.clear();
                    cursorpos = 0;
                    _cursor->setPosition(TextBox.getPosition());
                    TextBox.setSize(baseSize);
                    TextBox.setPosition(basePos);
                    text.setPosition(basePos);
                    text.setString(str);

                    //

                }
                if (m_event.key.code == sf::Keyboard::BackSpace)
                {
                        if(!str.empty()){
                            std::string::iterator it=str.end();
                            it--;
                            str.erase(it);
                            sf::Vector2f pos = text.findCharacterPos(str.size());
                            pos.y = pos.y + 21;

                            _cursor->setPosition(pos);
                            cursorpos -=1;
                            text.setString(str);
                        }



                }
        }



        }


    }


}

void TextField::update() {//manage drawing of attached widgets

    m_window.draw(TextBox);
    m_window.draw(text);//CHCEK IF LIST EMPTY FKING MORRON GODAMDINT IAJJL *`?!=$!"
    if(!messageWidgetList.empty()){
        m_window.draw(*messageWidgetList[0]->getWindow());
        m_window.draw(*messageWidgetList[0]->getDrawText());
    }

    _cursor->update();
    if(isActive && editable){

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

bool TextField::isTextOutside() {
    sf::Vector2f pos = text.findCharacterPos(2056);
    pos.x = pos.x+21;
    return !TextBox.getGlobalBounds().contains(pos);

}

void TextField::growEditBox() {
    if(isTextOutside())
    {

        sf::Vector2f oldPos = TextBox.getPosition();
        oldPos.y = oldPos.y -19;
        TextBox.setPosition(oldPos);
        text.setPosition(oldPos);
        sf::Vector2f size = TextBox.getSize();
        size.y = size.y + 19;
        TextBox.setSize(size);
    }

}

void TextField::setSize(sf::Vector2f size) {
    TextBox.setSize(size);

}

void TextField::addWidget(MessageWidget *widget){
    messageWidgetList.push_back( widget);

}

void TextField::deleteWidget(MessageWidget *widget)
{

    for (std::vector<MessageWidget*>::iterator it = messageWidgetList.begin();it != messageWidgetList.end();it++)
    {
       if (*it == widget)
       {
           messageWidgetList.erase(it);
       }
    }


}

MessageWidget *TextField::getWidget(int index) {
    return messageWidgetList[index];
}

MessageWidget *TextField::createStandardWidget() {
    MessageWidget* rtnWidget;
    if(messageWidgetList.empty())
    {
        sf::Vector2f ownerPos = TextBox.getPosition();
        ownerPos.x = ownerPos.x + 10;
        ownerPos.y = ownerPos.y + 10;
        size_t listSize = messageWidgetList.size();
        sf::Vector2f onwerScale = TextBox.getSize();
        onwerScale.x = onwerScale.x-100;
        onwerScale.y = onwerScale.y-270;
        rtnWidget = new MessageWidget(onwerScale,ownerPos,"widget1","GLorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut labore et dolore magna aliquyam erat, sed diam voluptua. At vero eos et accusam et justo duo dolores et ea rebum. Stet clita kasd gubergren, no sea takimata sanctus est Lorem ipsum dolor sit amet. Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy "); //scaling according to text needs to be done in constructor of MessageWidget
        rtnWidget->_owner = this;
        addWidget(rtnWidget);
        return rtnWidget;
    } else
    {

    }


}
