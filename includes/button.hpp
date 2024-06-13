
/*
-----------TimeIEX---------------------------------------------------------------------------------------
----This software is a program that provides timer, interval timer, smart time manager and stopwatch.----
----Copyright (C) 2024  tareqalwahsh666(tareqaldebs)                                                 ----
----                                                                                                 ----
----This program is free software: you can redistribute it and/or modify                             ----
----it under the terms of the GNU General Public License as published by                             ----
----the Free Software Foundation, either version 3 of the License, or                            	 ----
----(at your option) any later version.                                                              ----
----                                                                                             	 ----
----This program is distributed in the hope that it will be useful,                              	 ----
----but WITHOUT ANY WARRANTY; without even the implied warranty of                               	 ----
----MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                                	 ----
----GNU General Public License for more details.                                                 	 ----
----                                                                                             	 ----
----  You should have received a copy of the GNU General Public License                          	 ----
----   along with this program.  If not, see https://www.gnu.org/licenses/gpl-3.0.txt            	 ----
---------------------------------------------------------------------------------------------------------
*/

#include"common.hpp"

#ifndef __BUTTON_HPP__
#define __BUTTON_HPP__

namespace APPLICATION_GUI
{

    class Button
    {
    public:
        Button(void); // constructor overload
        Button(
            sf::Vector2i frameSize, // the size of the frame that is loaded from the texture
            sf::Texture& texture,
            sf::Vector2f buttonPos,
            sf::RenderWindow& aWindow
        );
        std::string handleButton(sf::Window& window,bool mouseLBPressed);
        inline void setScale(float xFactor,float yFactor)
        {
            this->buttonScale = sf::Vector2f(xFactor,yFactor);
        }
        inline void setPos(float x,float y)
        {
            this->buttonPos = sf::Vector2f(x,y);
        }
        inline void setTexture(sf::Texture& texture,sf::Vector2i frameSize)
        {
            this->button.setTexture(texture);
            this->buttonFrameSize = frameSize;
        }
        inline void drawButton(sf::RenderWindow* window)
        {
            window->draw(this->button);
        }
        
    private:

        sf::Sprite button;


        sf::Vector2i buttonFrameSize;
        sf::Vector2f buttonPos;
        sf::Vector2f buttonScale = sf::Vector2f(1.f,1.f);
        
        sf::Vector2u windowOldSize;


        void buttonChangeState(sf::IntRect rect); // this methode for internal use
    };

}

#endif