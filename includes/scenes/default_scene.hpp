
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

#ifndef __DEFAULT_SCENE_HPP__
#define __DEFAULT_SCENE_HPP__

#include"common.hpp"
#include"scene.hpp"

class DefaultScene : public APPLICATION_BASE::Scene
{
public:
    DefaultScene(void)
    {
        
    }
    void initialize(sf::RenderWindow& primaryWindow)                       final;
    void handleWindowEvents(sf::RenderWindow& primaryWindow,sf::Event& event)   final;
    void handleUserInputs(sf::RenderWindow& primaryWindow,sf::Event& event)     final;
    void processATick(sf::Time deltaTime)       final;
    void playSounds(void)                       final;
    void drawToScreen(sf::RenderWindow& primaryWindow)                     final;
private:

};

#endif