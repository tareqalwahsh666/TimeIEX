/*
-----------TimeIEX---------------------------------------------------------------------------------------
----This software is a program that provides timer, interval timer, smart time manager and stopwatch.----
----Copyright (C) 2024  tareqalwahsh666                                                              ----
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

#include"scenes/default_scene.hpp"


void DefaultScene::initialize(sf::RenderWindow& primaryWindow)
{
    primaryWindow.setTitle("TimeIEX 0.0.0.3pre-alpha @2024 tareqalwahsh(tareq aldebs)");
    primaryWindow.setSize
        (
            sf::Vector2u(800,600)
        );
}

void DefaultScene::handleWindowEvents(sf::RenderWindow& primaryWindow,sf::Event& event)
{
    while(primaryWindow.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            primaryWindow.close();
            break;
        
        default:
            break;
        }
    }
}

void DefaultScene::handleUserInputs(sf::RenderWindow& primaryWindow,sf::Event& event)
{
    while(primaryWindow.pollEvent(event))
    {
        switch(event.type)
        {
            case sf::Event::KeyPressed:
                switch (event.key.code)
                {
                case sf::Keyboard::Escape:
                    primaryWindow.close();
                    break;
                
                default:
                    break;
                }
                break;
            case sf::Event::KeyReleased:
                break;
            default:
                break;
        }
    }
}

void DefaultScene::processATick(sf::Time deltaTime)
{
    std::cout << "Frameddd " << deltaTime.asMicroseconds() << std::endl; 
}

void DefaultScene::playSounds(void)
{

}

void DefaultScene::drawToScreen(sf::RenderWindow& primaryWindow)
{
    primaryWindow.clear(sf::Color::Green);
    primaryWindow.display();
}


