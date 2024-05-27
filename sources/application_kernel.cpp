
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

#include"application_kernel.hpp"

using namespace APPLICATION_BASE;


void ApplicationKernel::run(void)
{
    // Testing scene manager
    SceneManager* scene_manager = SceneManager::getInstance(); /// manages scenes


    /// Application Main Loop
    while(this->primaryWindow.isOpen())
    {
        /// load the currents scene if not loaded
        scene_manager->loadCurrentSceneIfNotLoaded(this->primaryWindow);
        // HandleWindowEvents
        sf::Event event; // object that stores window events
        scene_manager->getCurrentScene()->handleWindowEvents(primaryWindow,event);
        // handleUserInput
        scene_manager->getCurrentScene()->handleUserInputs(primaryWindow,event);
        // ProcessATick
        //scene_manager->getCurrentScene()->processATick()
        // play Sounds
        scene_manager->getCurrentScene()->playSounds();
        ///// Draw to screen some stuff
        scene_manager->getCurrentScene()->drawToScreen(primaryWindow);
    }
}

ApplicationKernel::ApplicationKernel(void) // application kernel class constuctor
{
    // Initializing primaryWindowContextSettings
    this->primaryWindowContextSettings.antialiasingLevel = 0;
    this->primaryWindowContextSettings.depthBits = 24;
    this->primaryWindowContextSettings.stencilBits = 8;
    this->primaryWindowContextSettings.majorVersion = OPENGL_MAJOR_VERSION;
    this->primaryWindowContextSettings.minorVersion = OPENGL_MINOR_VERSION;

    // Creating primaryWindow or main window
    primaryWindow.create
    (
        sf::VideoMode
            (
                DEFAULT_SCREEN_WIDTH,
                DEFAUTL_SCREEN_HEIGHT
            ),
        DEFAULT_WINDOW_TITLE,
        DEFAULT_WINDOW_STYLE,
        primaryWindowContextSettings

    );
    
}

ApplicationKernel* ApplicationKernel::instancePtr = nullptr; // initialize instancePtr pointer

ApplicationKernel* ApplicationKernel::getInstance(void)
{
    if(instancePtr==nullptr) // the is no instance created create one and store it's address in a pointer
    {
        instancePtr = new ApplicationKernel;
    }
    return instancePtr; // return the instnace address from the pointer
}