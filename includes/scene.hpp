
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

#include"common.hpp"

#ifndef __SCENE_HPP__
#define __SCENE_HPP__


namespace APPLICATION_BASE // a namespace contains the framework that runs the program.
//                         // for example: Scene_Manager, Application kernel, Resource manager
{
    
    class Scene // This is an abstarct class which you can inherit it to make a Scene for your program to excute
    {

        /// >>>>>Public Section<<<<<
        public:

            virtual void Initialize //This function loads the required resources for the scene and loads some important variabes
                ( 
                    sf::RenderWindow& primaryWindow/*<=== The main window that runs the program*/
                )=0;

            virtual void handleWindowEvents
                (
                    sf::RenderWindow& primaryWindow, // reference to the main window
                    sf::Event& event                 // reference to the object that contain main window event...
                    //                               // For example: window closed event and window resized.
                )=0;

            virtual void handleUserInput // handle user input like keyboard key pressed or mouse button pressed
                (
                    sf::Event& event
                )=0;

            virtual void ProcessATick
                (
                    sf::Time deltaTime // contains how much time did the programs loop to do a frame
                )=0;

            virtual void playSounds // Plays some sound effects or music
                (
                    void // This methodes doesn't take any argument
                )=0;

            virtual void drawToScreen
                (
                    sf::RenderWindow& primaryWindow
                )=0;
                
    };




}

#endif