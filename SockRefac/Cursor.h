//
// Created by Chapo on 11.01.2019.
//

#ifndef SOCKREFAC_CURSOR_H
#define SOCKREFAC_CURSOR_H


#include <SFML/Graphics.hpp>

class Cursor{
public:
    Cursor(sf::Time delay, sf::Font& font, sf::Color color = sf::Color::White)
    {
            _cursor.setFillColor(color);
            _show = true;
            unsigned size=30;
            std::string ch = "|";
            _cursor.setString(ch);
            _cursor.setCharacterSize(16);
            _cursor.setPosition(0,0);
            _font = font;
    }

            void setPosition(const sf::Vector2f& pos){_cursor.setPosition(pos);}
            void update(){
        if(_clock.getElapsedTime() >= _delay)
        {
            _show = !_show;
            _clock.restart();
        }
    }
    /*void draw(sf::RenderTarget& target,sf::RenderStates state) const override
    {
        if (_show)
            target.draw(_cursor,state);
    }*/

private:
    sf::Font _font;
    sf::Clock _clock;
    const sf::Time _delay;
    bool _show;
    sf::Text _cursor;
};


#endif //SOCKREFAC_CURSOR_H
