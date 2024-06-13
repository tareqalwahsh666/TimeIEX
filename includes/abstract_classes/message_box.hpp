
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

/* Errors that is handled here :
    0x0 0x1 0x2 0x3 0x4 0x5 
    6 error are gaurded here
*/




#include<SFML/Graphics.hpp>
#include<iostream>
#include<functional>
#include"common.hpp"

#ifndef __MESSAGE_BOX_ABSTRACT_HPP__
#define __MESSAGE_BOX_ABSTRACT_HPP__

#define MESSAGE_BOXE_BASE_VARIABLES \
    sf::RenderWindow window;\
    sf::Sprite windowBackground;\
    sf::Texture windowBackgroundTexture;\
    sf::Font ASCII;\
    sf::Text title;\
    sf::Text text;\

#define DIALOG_ANSWER unsigned short
#define DIALOG_TYPE   unsigned short

/// Message Box Icons
#define MB_ICON_FATAL_ERROR 0x0
#define MB_ICON_ERROR       0x1
#define MB_ICON_WARNING     0x2
#define MB_ICON_INFORMATION 0x3
#define MB_ICON_QUESTION    0x4


namespace MESSAGE_BOXES_ABSTRACTS
{
    class MessageBoxBase
    {
    public:
        virtual DIALOG_ANSWER createDialog(void) = 0;


        virtual inline void loadBackgroundFromFile(std::string path)
        {
            APPLICATION_DEBUG::gaurdLoadProcess(
                this->windowBackgroundTexture.loadFromFile(path),path,"MessageBoxError : 0x0");//// <==== Error id 0x0
            this->windowBackground.setTexture(this->windowBackgroundTexture);
            this->windowBackground.setPosition(0.f,0.f);
        }

        virtual inline sf::RenderWindow& getWindow(void)
        {
            return this->window;
        }
        virtual inline sf::Sprite& getWindowBackground(void)
        {
            return this->windowBackground;
        }
        virtual void makeWindowDragable(void)
        {
            sf::Vector2i mouseDeltaPos = sf::Mouse::getPosition() - this->window.getPosition();
            sf::Vector2i mousePreviousPos = sf::Mouse::getPosition();
            while(sf::Mouse::isButtonPressed(sf::Mouse::Left) and 
                sf::Mouse::getPosition(this->window).x >= 0 and
                sf::Mouse::getPosition(this->window).y >= 0 and
                sf::Mouse::getPosition(this->window).x <= (int)this->window.getSize().x and
                sf::Mouse::getPosition(this->window).y <= (int)this->window.getSize().y
                )
            {
                if(sf::Mouse::getPosition()!=mousePreviousPos)
                {
                    this->window.setPosition(sf::Mouse::getPosition() - mouseDeltaPos);
                    mousePreviousPos = sf::Mouse::getPosition();
                }
            }
        }

        virtual inline void loadFont(void)
        {
            APPLICATION_DEBUG::gaurdLoadProcess( // <== Error ID : 0x1
                this->ASCII.loadFromFile("assets/fonts/ASCII.ttf"),"assets/fonts/ASCII.ttf","MessageBoxError : 0x1"
            );
            this->title.setFont(this->ASCII);
            this->text.setFont(this->ASCII);
            this->title.setStyle(sf::Text::Bold);
        }

        virtual inline sf::Font& getFont(void)
        {
            return this->ASCII;
        }





        void virtual inline setTitle(sf::String aTitle,long unsigned int maxCharacterCount,sf::Vector2f pos,unsigned int characterSize)
        {
            if(aTitle.getSize()>maxCharacterCount)
            {
                aTitle.erase(maxCharacterCount-1,aTitle.getSize()-maxCharacterCount);
            }
            
            this->title.setString(aTitle);
            this->title.setCharacterSize(characterSize);
            this->title.setPosition(pos);
        }
        
        virtual sf::Text& getTitle(void)
        {
            return this->title;
        }




        void virtual setText(sf::String aText,long unsigned int maxCharacterCount,sf::Vector2f pos,unsigned int characterSize)
        {
            aText.insert(0," ");
            try
            {
                if(aText.getSize()==1) /// <== Error ID 0x2
                    throw std::runtime_error(" Message Box Text : You enterd an empty text  MessageBoxError : 0x2");
                if(aText.getSize()>maxCharacterCount)
                {
                    aText.erase(maxCharacterCount,aText.getSize()-1); // <== Error ID 0x3
                    throw std::runtime_error(" Message Box Text You entered a very large string MessageBoxError : 0x3");
                }
            }
            catch(const std::exception& except)
            {
                std::cout << "Runtime Error : " << except.what() << std::endl;
            }
            
            this->text.setString(aText);
            this->text.setCharacterSize(characterSize);
            this->text.setPosition(pos);
        }
        virtual sf::Text& getText(void)
        {
            return this->text;
        }





        virtual ~MessageBoxBase(void) = default;
    protected:
        MESSAGE_BOXE_BASE_VARIABLES
    };

    class MessageBoxIconsBase
    {
    public:
        virtual void loadIcon(DIALOG_TYPE ICON_ID)
        {
            switch(ICON_ID)
            {
                case MB_ICON_FATAL_ERROR:
                    this->loadIconFromAFile("fatal_error");
                    break;
                case MB_ICON_ERROR:
                    this->loadIconFromAFile("error");
                    break;
                case MB_ICON_WARNING:
                    this->loadIconFromAFile("warning");
                    break;
                case MB_ICON_INFORMATION:
                    this->loadIconFromAFile("information");
                    break;
                case MB_ICON_QUESTION:
                    this->loadIconFromAFile("question");
                    break;
                default: // <=== Error 0x4
                    std::cerr << "unable to find Icon , MessageBoxError : 0x4 " << std::hex << ICON_ID << std::endl;
                    break;
            }
            this->messageBoxIcon.setPosition(sf::Vector2f(7.f,22.f));
        }
        virtual sf::Sprite& getMessageBoxIcon(void)
        {
            return this->messageBoxIcon;
        }
    protected:
        sf::Sprite messageBoxIcon;
    private:
        sf::Texture messageBoxIconTexture;

        virtual void loadIconFromAFile(std::string iconName)
        {
            std::string path = "assets/message_box/icons/_icon.png";
            path.insert(25,iconName);
            APPLICATION_DEBUG::gaurdLoadProcess( // <== error 0x5
                this->messageBoxIconTexture.loadFromFile(path),path,"MessageBoxError : 0x5"
            );
            this->messageBoxIcon.setTexture(this->messageBoxIconTexture);
        }
    };

}

#endif