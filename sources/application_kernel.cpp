
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
    std::cout << "Hello from the kernel\ns";
}

ApplicationKernel::ApplicationKernel(void) // application kernel class constuctor
{
    
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