


#-----------TimeIEX---------------------------------------------------------------------------------------
#----This software is a program that provides timer, interval timer, smart time manager and stopwatch.----
#----Copyright (C) 2024  tareqalwahsh666                                                              ----
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
BUILD_TARGET 							=build/TimeIEX

# dynamic lib suffix # change it to .dll for windows 
DLIB 									=.so



# >>>>	GENERAL	VARIABLES	START	<<<<
CXX 									=g++
CXXSTD 									=-std=c++20
INCLUDE									=./includes/
CXXFLAGS								=-Wall -g $(CXXSTD) -I$(INCLUDE) -Werror -pedantic -Wextra  -Wshadow -Wconversion -O2
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

OBJDIR									=objects/
LIBDIR									=build/libs/
SRCDIR									=sources/

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
	$(RM) objects/*.o $(BUILD_TARGET) build/*$(DLIB) build/libs*$(DLIB)
	echo build removed successfully


# 				>>>> GENERAL RULES END <<<<







#		>>>>	PROGRAM		WORKSPACE	START	<<<<

#Global Variables

# Main Variables
MAIN_OBJ =$(OBJDIR)main.o
MAIN_SRC =$(SRCDIR)main.cpp
# Application kernel variabless
APPLICATION_KERNEL_OBJ 	=$(OBJDIR)application_kernel.o
APPLICATION_KERNEL_DLIB =build/application_kernel$(DLIB)
APPLICATION_KERNEL_SRC	=$(SRCDIR)application_kernel.cpp
# Application scene manager variables
APPLICATION_SCENE_MANAGER_OBJ =$(OBJDIR)application_scene_manager.o
APPLICATION_SCENE_MANAGER_DLIB =$(LIBDIR)application_scene_manager$(DLIB)
APPLICATION_SCENE_MANAGER_SRC =$(SRCDIR)application_scene_manager.cpp

#scenes
LINK_SCENES = ./$(DEFAULT_SCENE_DLIB)

#default scene
DEFAULT_SCENE_OBJ =$(OBJDIR)default_scene.o
DEFAULT_SCENE_DLIB =$(LIBDIR)default_scene$(DLIB)
DEFAULT_SCENE_SRC =$(SRCDIR)scenes/default_scene.cpp



# Main Rules
$(BUILD_TARGET):$(APPLICATION_KERNEL_DLIB) $(MAIN_OBJ) 
	$(BUILD) $(MAIN_OBJ) -o $(BUILD_TARGET) ./$(APPLICATION_KERNEL_DLIB) ./$(APPLICATION_SCENE_MANAGER_DLIB) $(LINK_SCENES)  $(SFML)

$(MAIN_OBJ): $(MAIN_SRC)
	$(BUILD_OBJ) $(MAIN_SRC) -o $(MAIN_OBJ)





# application kernel rules
$(APPLICATION_KERNEL_DLIB):$(APPLICATION_KERNEL_OBJ) $(APPLICATION_SCENE_MANAGER_DLIB)
	$(BUILD_DLIB) $(APPLICATION_KERNEL_OBJ) -o $(APPLICATION_KERNEL_DLIB) ./$(APPLICATION_SCENE_MANAGER_DLIB) $(SFML) 

$(APPLICATION_KERNEL_OBJ):$(APPLICATION_KERNEL_SRC)
	$(BUILD_DLIBOBJ) $(APPLICATION_KERNEL_SRC) -o $(APPLICATION_KERNEL_OBJ)


# application scene manager rules
$(APPLICATION_SCENE_MANAGER_DLIB):$(APPLICATION_SCENE_MANAGER_OBJ) $(DEFAULT_SCENE_DLIB)
	$(BUILD_DLIB) $(APPLICATION_SCENE_MANAGER_OBJ) -o $(APPLICATION_SCENE_MANAGER_DLIB) $(LINK_SCENES)

$(APPLICATION_SCENE_MANAGER_OBJ):$(APPLICATION_SCENE_MANAGER_SRC)
	$(BUILD_DLIBOBJ) $(APPLICATION_SCENE_MANAGER_SRC) -o $(APPLICATION_SCENE_MANAGER_OBJ)


# scenes rules

# default scene rules
$(DEFAULT_SCENE_DLIB):$(DEFAULT_SCENE_OBJ)
	echo in
	$(BUILD_DLIB) $(DEFAULT_SCENE_OBJ) -o $(DEFAULT_SCENE_DLIB)

$(DEFAULT_SCENE_OBJ):$(DEFAULT_SCENE_SRC)
	$(BUILD_DLIBOBJ) $(DEFAULT_SCENE_SRC) -o $(DEFAULT_SCENE_OBJ)



#		>>>>	PROGRAM		WORKSPACE	END		<<<<


