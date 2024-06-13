
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


// errors that are gaurded here
/* 15 error are gaurded here
    0x6     0x7     0x8     0x9     0xA     
    0xB     0xC     0xD     0xE     0xF 
    0x10    0x11    0x12    0x13    0x14
*/


#include"message_box.hpp"
#include"common.hpp"

#define RIGHT       2
#define MIDDLE      1
#define LEFT        0
#define BUTTON_SIZE 56,28
#define RIGHT_POS   330.f,162.f
#define MIDDLE_POS  268.f,162.f
#define LEFT_POS    206.f,162.f




using namespace MESSAGE_BOXES;

struct Internel // the methodes of this struct are only used in this module --They are for internal use only 
{
private:

    sf::Sprite *messageBoxIcon = nullptr;
    bool dontDrawIcon = true;
    bool debugMode = false;

    sf::Texture* buttonsTextures[3]     = {nullptr,nullptr,nullptr}; // 0 left button 1 middle button 2 right button
    APPLICATION_GUI::Button* buttons[3] = {nullptr,nullptr,nullptr};
    bool areButtonsEnabled[3] = {false,false,false};
    bool areButtonsPressed[3] = {false,false,false};
    sf::RenderWindow* window =nullptr; sf::Sprite* windowBackground =nullptr;
    sf::Text* title =nullptr;sf::Text* text = nullptr;
    void makeWindowDragable(void); // This gives the user the ability to move the dialogBox or messageBox
    inline sf::RenderWindow& getWindow(void){return *this->window;}
    inline sf::Sprite& getWindowBackground(void){return *this->windowBackground;}
    inline sf::Text& getTitle(void){return *this->title;}
    inline sf::Text& getText(void){return *this->text;}
    void initializeButton(int buttonIndex,std::string ButtonName,std::string errorCode)
    {
        areButtonsEnabled[buttonIndex] = true;
        buttonsTextures[buttonIndex] = new sf::Texture;
        std::string path = "assets/message_box/buttons/_button.png"; path.insert(27,ButtonName);
        APPLICATION_DEBUG::gaurdLoadProcess(
            buttonsTextures[buttonIndex]->loadFromFile(path),
            path,
            errorCode);
        sf::Vector2f pos;
        switch (buttonIndex)
        {
        case RIGHT:
            pos = sf::Vector2f(RIGHT_POS);
            break;
        case MIDDLE:
            pos = sf::Vector2f(MIDDLE_POS);
            break;
        case LEFT:
            pos = sf::Vector2f(LEFT_POS);
            break;
        default: ///// <==== error 0x6
            std::cerr << "Button ID " << buttonIndex << " Doesn't exsist MessageBoxError :  0x6\n";
            break;
        }
        this->buttons[buttonIndex] = new APPLICATION_GUI::Button(
            sf::Vector2i(BUTTON_SIZE),
            *this->buttonsTextures[buttonIndex],
            pos,
            this->getWindow()
        );
    }
public:

    void initializeButton(std::string buttonPath,int buttonIndex,std::string errorCode)
    {
        areButtonsEnabled[buttonIndex] = true;
        buttonsTextures[buttonIndex] = new sf::Texture;
        APPLICATION_DEBUG::gaurdLoadProcess(
            buttonsTextures[buttonIndex]->loadFromFile(buttonPath),
            buttonPath,
            errorCode);
        sf::Vector2f pos;
        switch (buttonIndex)
        {
        case RIGHT:
            pos = sf::Vector2f(RIGHT_POS);
            break;
        case MIDDLE:
            pos = sf::Vector2f(MIDDLE_POS);
            break;
        case LEFT:
            pos = sf::Vector2f(LEFT_POS);
            break;
        default: ///// <==== error 0x7
            std::cerr << "Button ID " << buttonIndex << " Doesn't exsist MessageBoxError :  0x7\n";
            break;
        }
        this->buttons[buttonIndex] = new APPLICATION_GUI::Button(
            sf::Vector2i(BUTTON_SIZE),
            *this->buttonsTextures[buttonIndex],
            pos,
            this->getWindow()
        );
    }

    Internel(sf::RenderWindow& aWindow,sf::Sprite& aWindowBackground,sf::Text& aTitle,sf::Text& aText)
    {
        this->window = &aWindow; this->windowBackground = &aWindowBackground;
        this->title = &aTitle; this->text = &aText;
    }/// gets where is the window
    
    //                                   By left clicking with mouse on the message_box_bodys 
    DIALOG_ANSWER createDialog(DIALOG_TYPE dialog_type); // this creates the dialog box or message box this 
    void setIcon(sf::Sprite& iconSprite)
    {
        this->dontDrawIcon = false;
        this->messageBoxIcon = &iconSprite;
    }
};

DIALOG_ANSWER About::createDialog(void)
{
    Internel internel(this->getWindow(),this->getWindowBackground(),this->getTitle(),this->getText());
    return internel.createDialog(MB_ABOUT); 
}

DIALOG_ANSWER MessageBox::createDialog(void)
{
    Internel internel(this->getWindow(),this->getWindowBackground(),this->getTitle(),this->getText());
    internel.setIcon(this->messageBoxIcon);
    return internel.createDialog(this->__dialog_type);
}

DIALOG_ANSWER CustomeMessageBox::createDialog(void)
{
    Internel internel(this->getWindow(),this->getWindowBackground(),this->getTitle(),this->getText());
    if(!this->buttonsPaths[MB_BUTTON_LEFT].empty())
        internel.initializeButton(this->buttonsPaths[MB_BUTTON_LEFT],LEFT,"MessageBoxError : 0x8");
    if(!this->buttonsPaths[MB_BUTTON_MIDDLE].empty())
        internel.initializeButton(this->buttonsPaths[MB_BUTTON_MIDDLE],MIDDLE,"MessageBoxError : 0x9");
    if(!this->buttonsPaths[MB_BUTTON_RIGHT].empty())
        internel.initializeButton(this->buttonsPaths[MB_BUTTON_RIGHT],RIGHT,"MessageBoxError : 0xA");
    internel.setIcon(this->messageBoxIcon);
    return internel.createDialog(MB_GENERIC);
}


DIALOG_ANSWER Internel::createDialog(DIALOG_TYPE dialog_type)
{

    DIALOG_TYPE leftButtonReturn;
    DIALOG_TYPE middleButtonReturn;
    DIALOG_TYPE rightButtonReturn;

    switch(dialog_type)
    {
        case MB_ALERT:
            this->getWindow().setTitle("Alert DialogBox");
            break;
        case MB_CONFIRM:
            this->getWindow().setTitle("Confirm DialogBox");
            break;
        case MB_INQUIRE:
            this->getWindow().setTitle("Inquire DialogBox");
        break;
        case MB_GENERIC:
            this->getWindow().setTitle("Generic DialogBox");
            break;
        case MB_ABOUT:
            this->getWindow().setTitle("About MessageBox");
            break;
        default: // <=== Error 0xB
            this->getWindow().setTitle("Error MessageBox type this type is not allowed MessageBoxError :  0xB");
            break;
    }



    switch (dialog_type)
    {
    case MB_ALERT:
        rightButtonReturn = MB_OK; // right button is enabled
        middleButtonReturn = MB_NULL;
        leftButtonReturn = MB_NULL;
        this->initializeButton(RIGHT,"ok","MessageBoxError : 0xC"); // <===     Error 0xC
        break;
    case MB_CONFIRM:
        rightButtonReturn = MB_CANCEL; // right and middle button are enabled
        middleButtonReturn = MB_OK;
        leftButtonReturn = MB_NULL;
        this->initializeButton(RIGHT,"cancel","MessageBoxError : 0xD"); // <=== Error 0xD
        this->initializeButton(MIDDLE,"ok","MessageBoxError : 0xE");  // <===   Error 0xE
        break;
    case MB_INQUIRE:
        rightButtonReturn = MB_CANCEL; // all threw buttons are enabled
        middleButtonReturn = MB_NO;
        leftButtonReturn = MB_YES;
        this->initializeButton(RIGHT,"cancel","MessageBoxError : 0xF"); // <=== Error 0xF
        this->initializeButton(MIDDLE,"no","MessageBoxError : 0x10"); // <==     Error 0x10
        this->initializeButton(LEFT,"yes","MessageBoxError : 0x11"); // <===     Error 0x11
        break;
    case MB_GENERIC:
        rightButtonReturn = MB_RIGHT; // custom
        middleButtonReturn = MB_MIDDLE;
        leftButtonReturn = MB_LEFT;
        break;
    case MB_ABOUT:
        rightButtonReturn = MB_NULL; // all are disabled
        middleButtonReturn = MB_NULL;
        leftButtonReturn = MB_NULL;
        this->dontDrawIcon = true;
        break;
    default:
        rightButtonReturn = MB_NULL; // all are disabled
        middleButtonReturn = MB_NULL;
        leftButtonReturn = MB_NULL;
        this->dontDrawIcon = true;
        break;
    }



    DIALOG_ANSWER returnValue = MB_NULL;
    bool isWindowResizedToMaximum = false;
    bool isNotResized = false;
    
    sf::Texture resizeButtonTexture;
    APPLICATION_DEBUG::gaurdLoadProcess( //// <==== Error 0x12
        resizeButtonTexture.loadFromFile("assets/message_box/buttons/resize_button.png"),
        "assets/message_box/buttons/resize_button.png",
        "MessageBoxError : 0x12"
    );

    APPLICATION_GUI::Button resizeButton(sf::Vector2i(15,15),resizeButtonTexture,sf::Vector2f(370.f,0),this->getWindow());

    sf::Texture exitButtonTexture;
    APPLICATION_DEBUG::gaurdLoadProcess( /// <=== Error 0x13
        exitButtonTexture.loadFromFile("assets/message_box/buttons/exit_button.png"),
        "assets/message_box/buttons/exit_button.png",
        "MessageBoxError : 0x13"
    );
    
    APPLICATION_GUI::Button exitButton(sf::Vector2i(15,15),exitButtonTexture,sf::Vector2f(385.f,0.f),this->getWindow());

    bool isExitButtonPressed = false;
    
    while(this->getWindow().isOpen())
    {

        sf::Event event;
        while(this->getWindow().pollEvent(event))
        {
            switch(event.type)
            {
                case sf::Event::MouseButtonReleased:
                    switch(event.mouseButton.button)
                    {
                        case sf::Mouse::Left:

                            if(this->areButtonsPressed[RIGHT])
                            {
                                this->getWindow().close();
                                returnValue = rightButtonReturn;
                            }
                            if(this->areButtonsPressed[MIDDLE])
                            {
                                this->getWindow().close();
                                returnValue = middleButtonReturn;
                            }
                            if(this->areButtonsPressed[LEFT])
                            {
                                this->getWindow().close();
                                returnValue = leftButtonReturn;
                            }

                            if(isNotResized)
                            {
                                isNotResized = false;
                                if(!isWindowResizedToMaximum)
                                {
                                    this->getWindow().setSize(sf::Vector2u((unsigned int)(sf::VideoMode::getDesktopMode().width/1.1),(unsigned int)(sf::VideoMode::getDesktopMode().height/1.1)));
                                    this->getWindow().setPosition(sf::Vector2i(0,0));
                                    isWindowResizedToMaximum = true;
                                }
                                else
                                {
                                    this->getWindow().setSize(sf::Vector2u(400,200));
                                    this->getWindow().setPosition(sf::Vector2i((int)(sf::VideoMode::getDesktopMode().width / 3),(int)(sf::VideoMode::getDesktopMode().height / 3)));
                                    isWindowResizedToMaximum = false;
                                }
                            }
                            if(isExitButtonPressed)
                            {
                                this->getWindow().close();
                                returnValue = MB_EXIT;
                            }
                            break;
                        default:
                            resizeButton.handleButton(this->getWindow(),false);
                            exitButton.handleButton(this->getWindow(),false);
                            
                            if(areButtonsEnabled[RIGHT])
                            {
                                this->buttons[RIGHT]->handleButton(
                                    this->getWindow(),
                                    false
                                );
                            }
                            if(areButtonsEnabled[MIDDLE])
                            {
                                this->buttons[MIDDLE]->handleButton(
                                    this->getWindow(),
                                    false
                                );
                            }
                            if(areButtonsEnabled[LEFT])
                            {
                                this->buttons[LEFT]->handleButton(
                                this->getWindow(),
                                false
                                );
                            }  
                            
                            break;
                    }
                    break;
                case sf::Event::MouseButtonPressed:
                    switch(event.mouseButton.button)
                    {   
                        case sf::Mouse::Left:
                            if(resizeButton.handleButton(this->getWindow(),true)=="pressed")
                                isNotResized = true;
                            if(exitButton.handleButton(this->getWindow(),true)=="pressed")
                                isExitButtonPressed = true;

                            if(areButtonsEnabled[RIGHT])
                            {
                                if(this->buttons[RIGHT]->handleButton(this->getWindow(),true)=="pressed")
                                    this->areButtonsPressed[RIGHT] = true;
                            }
                            if(areButtonsEnabled[MIDDLE])
                            {
                                if(this->buttons[MIDDLE]->handleButton(this->getWindow(),true)=="pressed")
                                    this->areButtonsPressed[MIDDLE] = true;
                            }
                            if(areButtonsEnabled[LEFT])
                            {
                                if(this->buttons[LEFT]->handleButton(this->getWindow(),true)=="pressed")
                                    this->areButtonsPressed[LEFT] = true;
                            }

                            break;
                        default:
                            resizeButton.handleButton(this->getWindow(),false);
                            exitButton.handleButton(this->getWindow(),false);
                            
                            if(areButtonsEnabled[RIGHT])
                            {
                                this->buttons[RIGHT]->handleButton(
                                    this->getWindow(),
                                    false
                                );
                            }
                            if(areButtonsEnabled[MIDDLE])
                            {
                                this->buttons[MIDDLE]->handleButton(
                                    this->getWindow(),
                                    false
                                );
                            }
                            if(areButtonsEnabled[LEFT])
                            {
                                this->buttons[LEFT]->handleButton(
                                this->getWindow(),
                                false
                                );
                            }  
                            break;
                    }
                    break;
                default:
                    resizeButton.handleButton(this->getWindow(),false);
                    exitButton.handleButton(this->getWindow(),false);
                    if(areButtonsEnabled[RIGHT])
                    {
                        this->buttons[RIGHT]->handleButton(
                            this->getWindow(),
                            false
                        );
                    }
                    if(areButtonsEnabled[MIDDLE])
                    {
                        this->buttons[MIDDLE]->handleButton(
                            this->getWindow(),
                            false
                        );
                    }
                    if(areButtonsEnabled[LEFT])
                    {
                        this->buttons[LEFT]->handleButton(
                            this->getWindow(),
                            false
                        );
                    }
                    break;
            } 
        }
        // makes window dragable
        this->makeWindowDragable();
        //////////////////////

        

        this->getWindow().clear();
        this->getWindow().draw(this->getWindowBackground());
        this->getWindow().draw(this->getTitle());
        this->getWindow().draw(this->getText());
        resizeButton.drawButton(&this->getWindow());
        exitButton.drawButton(&this->getWindow());
        if(this->areButtonsEnabled[RIGHT])
            this->buttons[RIGHT]->drawButton(&this->getWindow());
        if(this->areButtonsEnabled[MIDDLE])
            this->buttons[MIDDLE]->drawButton(&this->getWindow());
        if(this->areButtonsEnabled[LEFT])
            this->buttons[LEFT]->drawButton(&this->getWindow());
        if(!this->dontDrawIcon)
            this->getWindow().draw(*this->messageBoxIcon);
        this->getWindow().display();
    }
    if(returnValue==MB_NULL) /// <=== Error 0x14
        std::cerr << "Error createDialog returned NULL MessageBoxError :  0x14\n";
    return returnValue; 
}

void Internel::makeWindowDragable(void)
{
    sf::Vector2i mouseDeltaPos = sf::Mouse::getPosition() - this->getWindow().getPosition();
    sf::Vector2i mousePreviousPos = sf::Mouse::getPosition();
    while(sf::Mouse::isButtonPressed(sf::Mouse::Left) and 
          sf::Mouse::getPosition(this->getWindow()).x >= 0 and
          sf::Mouse::getPosition(this->getWindow()).y >= 0 and
          sf::Mouse::getPosition(this->getWindow()).x <= (int)this->getWindow().getSize().x and
          sf::Mouse::getPosition(this->getWindow()).y <= (int)this->getWindow().getSize().y
          )
    {
        if(sf::Mouse::getPosition()!=mousePreviousPos)
        {
            this->getWindow().setPosition(sf::Mouse::getPosition() - mouseDeltaPos);
            mousePreviousPos = sf::Mouse::getPosition();
        }
    }
}
