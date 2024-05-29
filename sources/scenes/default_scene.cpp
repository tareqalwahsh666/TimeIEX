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

#include"scenes/default_scene.hpp"



void DefaultScene::initialize(void)
{
    this->primaryWindow = APPLICATION_BASE_EXTERNAL::ExternalAccess::accessApplicationKernel().getPrimaryWindow();
    this->primaryWindow->setTitle
        (
            "TimeIEX 0.0.0.4pre-alpha @2024 tareqalwahsh(tareq aldebs)"
        );
    this->primaryWindow->setSize
        (
            sf::Vector2u(800,600)
        );
}

void DefaultScene::onExit(void)
{
    
}

void DefaultScene::handleWindowEvents(void)
{
    while(this->primaryWindow->pollEvent(
        APPLICATION_BASE_EXTERNAL::ExternalAccess::accessApplicationKernel().getPrimaryWindowEvents()
    ))
    {
        switch (APPLICATION_BASE_EXTERNAL::ExternalAccess::accessApplicationKernel().getPrimaryWindowEvents().type)
        {
        case sf::Event::Closed:
            this->primaryWindow->close();
            break;
        
        default:
            break;
        }
    }
}

void DefaultScene::handleUserInputs(void)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        this->primaryWindow->close();
    }
}

void DefaultScene::processATick(sf::Time deltaTime)
{
    std::cout << "Frameddd " << deltaTime.asMicroseconds() << std::endl; 
}

void DefaultScene::playSounds(void)
{

}

void DefaultScene::drawToScreen(void)
{
    this->primaryWindow->clear(sf::Color::Green);
    this->primaryWindow->display();
}


