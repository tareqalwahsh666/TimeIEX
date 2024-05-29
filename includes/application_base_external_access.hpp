
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

// this module provides an access to the application base from external modules like scene modules

#ifndef __APPLICATION_BASE_EXTERNAL_ACCESS_HPP__
#define __APPLICATION_BASE_EXTERNAL_ACCESS_HPP__

#include"abstract_classes/application_kernel.hpp"
#include"abstract_classes/application_scene_manager.hpp"

namespace APPLICATION_BASE_EXTERNAL
{

    class ExternalAccess /// makes scenes modules access application base
    {

    public:

        static void makeAnAccess // used in application kernel class
        (
            APPLICATION_BASE_ABSTRACTS::ApplicationKernelAbstract* ApplicationKernel
        );

        static void makeAnAccess /// used in scene manager class
        (
            APPLICATION_BASE_ABSTRACTS::SceneManagerAbstract* SceneManager
        );

        static APPLICATION_BASE_ABSTRACTS::ApplicationKernelAbstract& accessApplicationKernel(void); // These will be used in..
        static APPLICATION_BASE_ABSTRACTS::SceneManagerAbstract& accessSceneManager(void);           // in scene modules

    private:
        static APPLICATION_BASE_ABSTRACTS::ApplicationKernelAbstract* ApplicationKernelPtr; // pointer has application kernel object
        //                                                                               // address in memory
        static APPLICATION_BASE_ABSTRACTS::SceneManagerAbstract* SceneManagerPtr; // pointer has scene manager object address in mem
    };

};


#endif