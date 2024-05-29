
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

/// This abstract class was made to make scenes modules be able to reach application_kernel class

// This module will be included multiple time from several source file
#ifndef __APPLICATION_KERNEL_ABSTRACT_HPP__
#define __APPLICATION_KERNEL_ABSTRACT_HPP__

#include"common.hpp"

namespace APPLICATION_BASE_ABSTRACTS // a namespace contains the framework abstract that runs the program.
{

    class ApplicationKernelAbstract
    {

    public:

        virtual sf::Event& getPrimaryWindowEvents(void)              =0; // gets primaryWindow Events
        virtual sf::RenderWindow* getPrimaryWindow(void)             =0; // getting primaryWindow
        virtual sf::RenderWindow* getMainWindow(void)                =0;
        static ApplicationKernelAbstract* getInstance(void)            ; // returns the class instance address
        virtual ~ApplicationKernelAbstract()                         = default;
    };

}

#endif