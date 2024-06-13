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

#include"button.hpp"

using namespace APPLICATION_GUI;



void Button::buttonChangeState(sf::IntRect rect)
{
        this->button.setPosition(this->buttonPos);
        this->button.setScale(this->buttonScale);
        this->button.setTextureRect(rect);
}

std::string Button::handleButton(sf::Window& window,bool mouseLBPressed)
{
    float xScale = (float)((double)window.getSize().x/(double)this->windowOldSize.x);
    float yScale = (float)((double)window.getSize().y/(double)this->windowOldSize.y);
    sf::FloatRect newGlobalBounds = sf::FloatRect(
        this->button.getGlobalBounds().left * xScale,this->button.getGlobalBounds().top * yScale,
        this->button.getGlobalBounds().width * xScale,this->button.getGlobalBounds().height * yScale
    );
    if(
        sf::Mouse::getPosition(window).x  >= (int)(newGlobalBounds.left) and
        sf::Mouse::getPosition(window).y  >= (int)(newGlobalBounds.top) and
        sf::Mouse::getPosition(window).x <= (int)(newGlobalBounds.left + newGlobalBounds.width)
        and
        sf::Mouse::getPosition(window).y <= (int)(newGlobalBounds.top + newGlobalBounds.height)

    )
    {
        if(mouseLBPressed)
        {
            this->buttonChangeState(
                            sf::IntRect(
                                        this->buttonFrameSize.x*2,0,
                                        this->buttonFrameSize.x,
                                        this->buttonFrameSize.y 
                            )
            );
            return "pressed";
        }
        else
        {
            this->buttonChangeState(
                            sf::IntRect(
                                        this->buttonFrameSize.x,0,
                                        this->buttonFrameSize.x,
                                        this->buttonFrameSize.y 
                            )
            );
            return "active";
        }

    }
    else
    {
        this->buttonChangeState(
            sf::IntRect(
                        0,0,
                        this->buttonFrameSize.x,
                        this->buttonFrameSize.y 
                        )
        );
        return "idle";
    }
}

/// constructor over load for create the class instance without arguments
Button::Button(void)
{
}

Button::Button(
            sf::Vector2i frameSize, // the size of the frame that is loaded from the texture
            sf::Texture& texture,
            sf::Vector2f aButtonPos,
            sf::RenderWindow& aWindow
        )
: button()
{
    this->windowOldSize = aWindow.getSize();
    this->buttonFrameSize = frameSize;
    this->button.setTexture(texture);
    this->buttonPos = aButtonPos;
}