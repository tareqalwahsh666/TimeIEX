


#-----------TimeIEX---------------------------------------------------------------------------------------
#----This software is a program that provides timer, interval timer, smart time manager and stopwatch.----
#----Copyright (C) 2024  tareqalwahsh666(tareqaldebs)                                                 ----
#----                                                                                                 ----
#----This program is free software: you can redistribute it and/or modify                             ----
#----it under the terms of the GNU General Public License as published by                             ----
#----the Free Software Foundation, either version 3 of the License, or                            	  ----
#----(at your option) any later version.                                                              ----
#----                                                                                             	  ----
#----This program is distributed in the hope that it will be useful,                              	  ----
#----but WITHOUT ANY WARRANTY; without even the implied warranty of                               	  ----
#----MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                                	  ----
#----GNU General Public License for more details.                                                 	  ----
#----                                                                                             	  ----
#----  You should have received a copy of the GNU General Public License                          	  ----
#----   along with this program.  If not, see https://www.gnu.org/licenses/gpl-3.0.txt            	  ----
#---------------------------------------------------------------------------------------------------------



# app_name
BUILD_TARGET 							=TimeIEX

# dynamic lib suffix # change it to .dll for windows 
DLIB 									=.so



# >>>>	GENERAL	VARIABLES	START	<<<<
CXX 									=g++
CXXSTD 									=-std=c++20
INCLUDE									=/home/tareq/Desktop/workspace/TimeIEX/includes/
CXXFLAGS								=-Wall  $(CXXSTD) -I$(INCLUDE) -pedantic -Wextra  -Wshadow -Wconversion -O2
RM 										=rm -f
SFML									=-lsfml-window -lsfml-system -lsfml-graphics
# >>>>	GENERAL VARIABLES END








# >>>>	BUILD	VARIABLES	START	<<<<
# ----> Build Excutable file <----
BUILD									=$(CXX) $(CXXFLAGS)
# ----> Build Dynamic library <----
BUILD_DLIB								=$(BUILD) --shared
# ----> Builds .o file <----
BUILD_OBJ								=$(BUILD) -c
# ----> Builds .o file that can be linked into dynamic lib <----
BUILD_DLIBOBJ 							=$(BUILD_OBJ) -fPIC
# >>>>	BUILD	VARIABLES	END    <<<<





# >>>	BUILD	DIRECTORIES		START	<<<<

OBJDIR									=/home/tareq/Desktop/workspace/TimeIEX/objects/
LIBDIR									=libs/
SRCDIR									=/home/tareq/Desktop/workspace/TimeIEX/sources/

# >>>	BUILD	DIRECTORIES		END		<<<<







# 				>>>> GENERAL RULES START <<<<

#############################################################################
##### Don't check for these files	 ####	they are labels not files	###s##
#############################################################################
.PHONY: BUILD_SOFTWARE CLEAN EXCUTE										#####
#############################################################################
# This rule simply builds the program
BUILD_SOFTWARE: $(BUILD_TARGET)
	echo Building the program succeed
# This rule cleans objects and binary files
CLEAN:
	$(RM) $(OBJDIR)*.o $(BUILD_TARGET) $(DLIBDIR)*$(DLIB) libs/*$(DLIB)
	echo build removed successfully


# 				>>>> GENERAL RULES END <<<<







#		>>>>	PROGRAM		WORKSPACE	START	<<<<

#Global Variables

# Main Variables
MAIN_OBJ =$(OBJDIR)main.o
MAIN_SRC =$(SRCDIR)main.cpp
# Application kernel variabless
APPLICATION_KERNEL_OBJ 	=$(OBJDIR)application_kernel.o
APPLICATION_KERNEL_DLIB =application_kernel$(DLIB)
APPLICATION_KERNEL_SRC	=$(SRCDIR)application_kernel.cpp
# Application scene manager variables
APPLICATION_SCENE_MANAGER_OBJ =$(OBJDIR)application_scene_manager.o
APPLICATION_SCENE_MANAGER_DLIB =$(LIBDIR)application_scene_manager$(DLIB)
APPLICATION_SCENE_MANAGER_SRC =$(SRCDIR)application_scene_manager.cpp
# Application_base_abstracts
APPLICATION_BASE_ABSTRACTS_OBJ =$(OBJDIR)application_base_abstracts.o
APPLICATION_BASE_ABSTRACTS_DLIB =$(LIBDIR)application_base_abstracts$(DLIB)
APPLICATION_BASE_ABSTRACTS_SRC  =$(SRCDIR)application_base_abstracts.cpp
# Application base external access
APPLICATION_BASE_EXTERNAL_ACCESS_OBJ 	=$(OBJDIR)application_base_external_access.o
APPLICATION_BASE_EXTERNAL_ACCESS_DLIB	=$(LIBDIR)application_base_external_access$(DLIB)
APPLICATION_BASE_EXTERNAL_ACCESS_SRC  	=$(SRCDIR)application_base_external_access.cpp

# application gui

# button
BUTTON_OBJ =$(OBJDIR)button.o
BUTTON_SRC =$(SRCDIR)button.cpp
BUTTON_LIB =$(LIBDIR)button$(DLIB)

# message box
MESSAGE_BOX_OBJ =$(OBJDIR)message_box.o
MESSAGE_BOX_SRC =$(SRCDIR)message_box.cpp
MESSAGE_BOX_LIB =$(LIBDIR)message_box$(DLIB)

#scenes
LINK_SCENES = ./$(DEFAULT_SCENE_DLIB)

#default scene
DEFAULT_SCENE_OBJ =$(OBJDIR)default_scene.o
DEFAULT_SCENE_DLIB =$(LIBDIR)default_scene$(DLIB)
DEFAULT_SCENE_SRC =$(SRCDIR)scenes/default_scene.cpp



# Main Rules
$(BUILD_TARGET):$(BUTTON_LIB) $(MESSAGE_BOX_LIB) $(APPLICATION_KERNEL_DLIB) $(MAIN_OBJ) 
	$(BUILD) $(MAIN_OBJ) -o $(BUILD_TARGET) ./$(BUTTON_LIB) ./$(MESSAGE_BOX_LIB) ./$(APPLICATION_KERNEL_DLIB) ./$(APPLICATION_BASE_EXTERNAL_ACCESS_DLIB) ./$(APPLICATION_BASE_ABSTRACTS_DLIB) ./$(APPLICATION_SCENE_MANAGER_DLIB)  $(LINK_SCENES)  $(SFML)

$(MAIN_OBJ): $(MAIN_SRC)
	$(BUILD_OBJ) $(MAIN_SRC) -o $(MAIN_OBJ)





# application kernel rules
$(APPLICATION_KERNEL_DLIB):$(APPLICATION_BASE_ABSTRACTS_DLIB) $(APPLICATION_BASE_EXTERNAL_ACCESS_DLIB) $(APPLICATION_KERNEL_OBJ) $(APPLICATION_SCENE_MANAGER_DLIB)
	$(BUILD_DLIB) $(APPLICATION_KERNEL_OBJ) -o $(APPLICATION_KERNEL_DLIB) ./$(APPLICATION_SCENE_MANAGER_DLIB) ./$(APPLICATION_BASE_EXTERNAL_ACCESS_DLIB) ./$(APPLICATION_BASE_ABSTRACTS_DLIB) $(SFML) 

$(APPLICATION_KERNEL_OBJ):$(APPLICATION_KERNEL_SRC)
	$(BUILD_DLIBOBJ) $(APPLICATION_KERNEL_SRC) -o $(APPLICATION_KERNEL_OBJ)


# application scene manager rules
$(APPLICATION_SCENE_MANAGER_DLIB):$(APPLICATION_SCENE_MANAGER_OBJ) $(DEFAULT_SCENE_DLIB)
	$(BUILD_DLIB) $(APPLICATION_SCENE_MANAGER_OBJ) -o $(APPLICATION_SCENE_MANAGER_DLIB) ./$(APPLICATION_BASE_ABSTRACTS_DLIB) ./$(APPLICATION_BASE_EXTERNAL_ACCESS_DLIB) $(LINK_SCENES)

$(APPLICATION_SCENE_MANAGER_OBJ):$(APPLICATION_SCENE_MANAGER_SRC)
	$(BUILD_DLIBOBJ) $(APPLICATION_SCENE_MANAGER_SRC) -o $(APPLICATION_SCENE_MANAGER_OBJ)

# application base abstracts
$(APPLICATION_BASE_ABSTRACTS_DLIB):$(APPLICATION_BASE_ABSTRACTS_OBJ)
	$(BUILD_DLIB) $(APPLICATION_BASE_ABSTRACTS_OBJ) -o $(APPLICATION_BASE_ABSTRACTS_DLIB)

$(APPLICATION_BASE_ABSTRACTS_OBJ):$(APPLICATION_BASE_ABSTRACTS_SRC)
	$(BUILD_DLIBOBJ) $(APPLICATION_BASE_ABSTRACTS_SRC) -o $(APPLICATION_BASE_ABSTRACTS_OBJ)

# application base external access
$(APPLICATION_BASE_EXTERNAL_ACCESS_DLIB):$(APPLICATION_BASE_EXTERNAL_ACCESS_OBJ)
	$(BUILD_DLIB) $(APPLICATION_BASE_EXTERNAL_ACCESS_OBJ) -o $(APPLICATION_BASE_EXTERNAL_ACCESS_DLIB)

$(APPLICATION_BASE_EXTERNAL_ACCESS_OBJ):$(APPLICATION_BASE_EXTERNAL_ACCESS_SRC)
	$(BUILD_DLIBOBJ) $(APPLICATION_BASE_EXTERNAL_ACCESS_SRC) -o $(APPLICATION_BASE_EXTERNAL_ACCESS_OBJ)

# message box

$(MESSAGE_BOX_LIB):$(MESSAGE_BOX_OBJ) $(BUTTON_LIB)
	$(BUILD_DLIB) $(MESSAGE_BOX_OBJ) -o $(MESSAGE_BOX_LIB) ./$(BUTTON_LIB)

$(MESSAGE_BOX_OBJ): $(INCLUDE)abstract_classes/message_box.hpp $(INCLUDE)message_box.hpp  $(MESSAGE_BOX_SRC)
	$(BUILD_DLIBOBJ) $(MESSAGE_BOX_SRC) -o $(MESSAGE_BOX_OBJ)

# application gui rules


# application button rules

$(BUTTON_LIB): $(BUTTON_OBJ)
	$(BUILD_DLIB) $(BUTTON_OBJ) -o $(BUTTON_LIB)

$(BUTTON_OBJ):$(BUTTON_SRC) $(INCLUDE)button.hpp
	$(BUILD_DLIBOBJ) $(BUTTON_SRC) -o $(BUTTON_OBJ)

# scenes rules

# default scene rules
$(DEFAULT_SCENE_DLIB):$(DEFAULT_SCENE_OBJ)
	echo in
	$(BUILD_DLIB) $(DEFAULT_SCENE_OBJ) -o $(DEFAULT_SCENE_DLIB) ./$(BUTTON_LIB) ./$(MESSAGE_BOX_LIB)

$(DEFAULT_SCENE_OBJ):$(INCLUDE)scenes/default_scene.hpp $(DEFAULT_SCENE_SRC)
	$(BUILD_DLIBOBJ) $(DEFAULT_SCENE_SRC) -o $(DEFAULT_SCENE_OBJ)



#		>>>>	PROGRAM		WORKSPACE	END		<<<<


