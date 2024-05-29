
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

#ifndef __SCENE_HPP__
#define __SCENE_HPP__


namespace APPLICATION_BASE // a namespace contains the framework that runs the program.
//                         // for example: Scene_Manager, Application kernel, Resource manager
{
    
    class Scene // This is an abstarct class which you can inherit it to make a Scene for your program to excute
    {

        /// >>>>>Public Section<<<<<
        public:

        
            virtual void initialize //This function loads the required resources for the scene and loads some important variabes
                ( 
                    void
                )=0;

            virtual void onExit(void) = 0; // This what to do when quiting from the scene

            virtual void handleWindowEvents
                (
                    void
                )=0;

            virtual void handleUserInputs // handle user input like keyboard key pressed or mouse button pressed
                (
                    void
                )=0;

            virtual void processATick
                (
                    sf::Time deltaTime // contains how much time did the programs loop to do a frame
                )=0;

            virtual void playSounds // Plays some sound effects or music
                (
                    void // This methodes doesn't take any argument
                )=0;

            virtual void drawToScreen
                (
                    void
                )=0;
            virtual ~Scene() = default;
    };




}

#endif