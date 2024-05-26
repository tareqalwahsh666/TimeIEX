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

#ifndef __APPLICATION_KERNEL__
#define __APPLICATION_KERNEL__

namespace APPLICATION_BASE // a namespace contains the framework that runs the program.
{

    class ApplicationKernel // builds the main window and runs the program because it contains the main loop of the program
    //                      // It's singleon class. This class can have one instance onlys
    //                      // It's not thread safe
    {

        // >>>>public section<<<<
        public:

            void run(void); // this function runs the program

            // This class can't be cloned or assigned
            ApplicationKernel(const ApplicationKernel&) = delete;
            void operator= (const ApplicationKernel&)   = delete;

            static ApplicationKernel* getInstance(void); // returns the class instance address



        // >>>> private section<<<<
        private:

            ApplicationKernel(void); // the class constructor is private because it's a singleton class

            static ApplicationKernel* instancePtr; // This pointer contains this class instance adderss in memory

            


    };
}



#endif
