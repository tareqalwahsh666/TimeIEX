
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

#include"application_scene_manager.hpp"

using namespace APPLICATION_BASE;

/// adding scenes to the scenes map
std::map<std::string,std::unique_ptr<Scene>> SceneManager::scenes; // this map contains scenes that can be loaded and rendered to the window




std::atomic<SceneManager*> SceneManager::instancePtr = nullptr;
std::mutex SceneManager::instancePtrMutex;

SceneManager* SceneManager::getInstance(void)
{
    if(instancePtr==nullptr)
    {
        std::lock_guard<std::mutex> lock(instancePtrMutex); // prevent threads from editing this at once
        if(instancePtr==nullptr)
        {
            instancePtr = new SceneManager;
        }
    }
    return instancePtr;
}