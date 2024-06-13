
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

//// Don't forget to finish this module

#include"common.hpp"
#include"button.hpp"
#include"abstract_classes/message_box.hpp"



#ifndef __MESSAGE_BOX_HPP__
#define __MESSAGE_BOX_HPP__

/// regular Dialog answers
#define MB_NULL     0x0
#define MB_EXIT     0x1
#define MB_RESIZE   0x2
#define MB_OK       0x3
#define MB_CANCEL   0x4
#define MB_YES      0x5
#define MB_NO       0x6
#define MB_RIGHT    0x7
#define MB_MIDDLE   0x8
#define MB_LEFT     0x9

///////// Dialog boxes or message box returns 
#define MB_GENERIC  0x0
#define MB_ALERT    0x1
#define MB_CONFIRM  0x2
#define MB_INQUIRE  0x3
#define MB_ABOUT    0x4

/// Message Box Icons
#define MB_ICON_FATAL_ERROR 0x0
#define MB_ICON_ERROR       0x1
#define MB_ICON_WARNING     0x2
#define MB_ICON_INFORMATION 0x3
#define MB_ICON_QUESTION    0x4

// Generic dialogbox macros
#define MB_BUTTONS_TYPE std::string
#define MB_INDEX    0x3
#define MB_BUTTON_LEFT     0x0
#define MB_BUTTON_MIDDLE   0x1
#define MB_BUTTON_RIGHT    0x2






namespace MESSAGE_BOXES
{

    class About : public MESSAGE_BOXES_ABSTRACTS::MessageBoxBase
    {
    public:
        About(sf::String aTitle,sf::String aText)
        {
            this->loadBackgroundFromFile("assets/message_box/dialog_box_no_icon.png");
            this->loadFont();
            this->setTitle(aTitle,20,sf::Vector2f(10.f,25.f),30);this->setText(aText,216,sf::Vector2f(10.f,55.f),20);
            this->getWindow().create(
                sf::VideoMode(400,200),
                "...",
                sf::Style::None 
            );
            this->getWindow().setPosition(sf::Vector2i(sf::VideoMode::getDesktopMode().width / 3,sf::VideoMode::getDesktopMode().height / 3));
        }   
        DIALOG_ANSWER createDialog(void) final;
    };

    class GenericMessageBoxBase : public MESSAGE_BOXES_ABSTRACTS::MessageBoxBase, public MESSAGE_BOXES_ABSTRACTS::MessageBoxIconsBase
    {
    protected:
        GenericMessageBoxBase(sf::String aTitle,sf::String aText, DIALOG_TYPE dialog_type, DIALOG_TYPE message_box_icon)
        {
            this->loadBackgroundFromFile("assets/message_box/genericMB.png");
            this->loadFont();
            this->setTitle(aTitle,11,sf::Vector2f(185.f,25.f),30);this->setText(aText,92,sf::Vector2f(185.f,55.f),20);
            this->getWindow().create(
                sf::VideoMode(400,200),
                ".f..",
                sf::Style::None 
            );
            this->getWindow().setPosition(sf::Vector2i(sf::VideoMode::getDesktopMode().width / 3,sf::VideoMode::getDesktopMode().height / 3));
            this->__dialog_type = dialog_type;
            this->loadIcon(message_box_icon);
        }

        /// 
        DIALOG_TYPE __dialog_type; /// <== contains what type of message box we will use
    };

    /*
    //dialogTypes avaliable: 
    -->MB_ALERT returns MB_OK or MB_EXIT
    -->MB_CONFIRM returns MB_OK or MB_CANCEL or MB_EXIT
    -->MB_INQUIRE return MB_YES or MB_NO or MB_EXIT 
    */
    class MessageBox : protected GenericMessageBoxBase 
    {
    public:
        MessageBox(sf::String aTitle,sf::String aText, DIALOG_TYPE dialog_type, DIALOG_TYPE message_box_icon)
        :GenericMessageBoxBase(aTitle,aText,dialog_type,message_box_icon)
        {

        }

        DIALOG_ANSWER createDialog(void) final;
    };

    class CustomeMessageBox : protected GenericMessageBoxBase
    {
    public:
        
        CustomeMessageBox(sf::String aTitle,sf::String aText, DIALOG_TYPE message_box_icon,std::string argButtonsPaths[MB_INDEX])
        : GenericMessageBoxBase(aTitle,aText,MB_GENERIC,message_box_icon)
        {
            this->buttonsPaths[MB_BUTTON_LEFT] = argButtonsPaths[MB_BUTTON_LEFT];
            this->buttonsPaths[MB_BUTTON_MIDDLE] = argButtonsPaths[MB_BUTTON_MIDDLE];
            this->buttonsPaths[MB_BUTTON_RIGHT] = argButtonsPaths[MB_BUTTON_RIGHT];
        }
        DIALOG_ANSWER createDialog(void) final;
    private:
        std::string buttonsPaths[MB_INDEX];
    };

}

#endif