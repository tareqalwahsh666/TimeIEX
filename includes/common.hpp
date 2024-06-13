
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
#ifndef __COMMON_HPP__ // <===== Prevents multiple inclusion error
#define __COMMON_HPP__

#define DEFAULT_SCREEN_WIDTH 640
#define DEFAUTL_SCREEN_HEIGHT 480
#define OPENGL_MAJOR_VERSION 2
#define OPENGL_MINOR_VERSION 1
#define DEFAULT_WINDOW_TITLE "TimeIEX"
#define DEFAULT_WINDOW_STYLE sf::Style::Titlebar | sf::Style::Close

#include<iostream>
#include<cmath>
#include<memory>
#include<map>
#include<atomic>
#include<mutex>
#include<string>
#include<exception>
#include<cassert>
#include<functional>

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>

namespace APPLICATION_DEBUG
{
    static inline void gaurdLoadProcess(bool process,std::string name,std::string error_code)
    {
        if(!process)
        {
            std::cerr << "Failed to load " << name << " :: Error Code :: " << error_code << std::endl;
        }
    }
}

#endif