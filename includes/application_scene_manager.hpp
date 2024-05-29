
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

#ifndef __APPLICATION_SCENE_MANAGER_HPP__
#define __APPLICATION_SCENE_MANAGER_HPP__

#include "common.hpp"
#include"abstract_classes/scene.hpp"
#include "scenes/default_scene.hpp"
#include "abstract_classes/application_scene_manager.hpp"
#include "application_base_external_access.hpp"

namespace APPLICATION_BASE // a namespace contains the framework that runs the program.
{

    /// This class is singleton

    class SceneManager : public APPLICATION_BASE_ABSTRACTS::SceneManagerAbstract
    {
    private:
        // constructor
        SceneManager(void)   // the constructor is private
        ////: scenes(),      // when this constructor is called this scenes map will be created too
          :currentScene() /// a smart pointer that contains the current scene
        {
            /// adding scenes to the scenes map
            this->scenes["DefaultScene"] = std::make_unique<DefaultScene>();
        }

        // >>>>>Public Section<<<<<
    public:
        inline std::unique_ptr<Scene> &getCurrentScene(void)
        {
            return this->currentScene;
        }

        inline void changeCurrentSceneTo(std::string scene_name) /// <--- used from scenes
        final{
            std::string previousSceneName = this->current_scene_name;     /// storing previous scene name
            this->currentScene->onExit(); /// do some stuff when quiting from a scene to free allocated memory
            scenes.at(previousSceneName) = std::move(this->currentScene); /// returning the ownership back to the previous scene...
            ////                                                     // to the smart pointer which is located in a...
            ///                                                      // container in scenes map this container key is a...
            ///                                                      // the name of the previous scene
            this->current_scene_name = scene_name;
            this->currentSceneLoaded = false;
        }

        inline void restart(void) // <-- used in scenes to restart the current scene
        final{
            this->currentScene->onExit(); /// do some stuff when quiting from a scene to free allocated memory
            scenes.at(this->current_scene_name) = std::move(this->currentScene);
            this->currentSceneLoaded = false;
        }



        inline void loadCurrentSceneIfNotLoaded() // <---- used in application kernel
        {
            if (!this->currentSceneLoaded) // if current is not loaded load it
            {
                this->currentScene = std::move /// moving ownership of the currents scene instance from a unique smart...
                //                             //                                 pointer that is located in a container of scenes map data structure ...
                //                             //                                 to the current scene unique smart pointer
                    (
                        this->scenes.at(this->current_scene_name)
                    );
                this->currentScene->initialize();
                this->currentSceneLoaded = true; /// current scene loaded successfully
            }
        }

        SceneManager(const SceneManager &) = delete;
        void operator=(const SceneManager &) = delete;

        static SceneManager *getInstance(void); // return class instance address in memory

        // >>>>>Private Section<<<<<
    private:
        std::string current_scene_name = "DefaultScene";
        bool currentSceneLoaded = false; // when current scene is loaded this variable value will be true
        //                               // when current scene isn't loaded the scene manager will load it and...
        //                               // make this variable value true

        std::unique_ptr<Scene> currentScene; // will be using unique ptr because we need only one owner of the Scene instnace

        //template<typename T>
        static std::map<
            std::string,
            std::unique_ptr<Scene>>
            scenes; // this map contains scenes that can be loaded and rendered to the window

        

        static std::atomic<SceneManager *> instancePtr; // contains this class instance address in memory
        static std::mutex instancePtrMutex;
    };
}

#endif