


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

# dynamic lib suffix
DLIB 									=.so



# >>>>	GENERAL	VARIABLES	START	<<<<
CXX 									=g++
CXXSTD 									=-std=c++20
INCLUDE									=./includes/
CXXFLAGS								=-Wall -g $(CXXSTD) -I$(INCLUDE) -Werror -pedantic -Wextra -Wfatal-errors -Wshadow -Wconversion -O2
RM 										=rm -f
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
##### Don't check for these files	 ####	they are labels not files	#####
#############################################################################
.PHONY: BUILD_SOFTWARE CLEAN 											#####
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


# --->	Main stuff Start	<---

# Main Variables
MAIN_OBJ =$(OBJDIR)main.o
MAIN_SRC =$(SRCDIR)main.cpp

# Main Rules
$(BUILD_TARGET): $(MAIN_OBJ)
	$(BUILD) $(MAIN_OBJ) -o $(BUILD_TARGET)

$(MAIN_OBJ): $(MAIN_SRC)
	$(BUILD_OBJ) $(MAIN_SRC) -o $(MAIN_OBJ)
 

#		>>>>	PROGRAM		WORKSPACE	END		<<<<


