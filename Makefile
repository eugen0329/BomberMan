#######################
#      GENERAL
#######################

rwildcard=$(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2) $(filter $(subst *,%,$2),$d))

SHELL := /bin/bash

CC = g++

#######################
#      DEFAULTS
#######################

LSFMLFL= -lsfml-graphics -lsfml-window -lsfml-system

CFLAGS = -Wall -pedantic-errors -g -std=c++11
LDFLAGS = $(CFLAGS) 
LDLIBS =  

OBJ_DIR = obj
LIB_DIR = inc
SRC_DIR = src

#CPPFLAGS="-Wall -pedantic-errors -g " 


SRC_NAMES = $(call rwildcard, $(SRC_DIR), *.cpp) 
LIB_NAMES = $(wildcard $(LIB_DIR)/*.hpp)
OBJ_NAMES = $(SRC_NAMES:.cpp=.o)

OBJECTS =  $(patsubst $(SRC_DIR)/%, $(OBJ_DIR)/%, $(OBJ_NAMES)) 
HEADERS =  $(LIB_NAMES)
SOURCES =  $(SRC_NAMES) 

INCLUDE_DIRS = -I . -I ./src  -I $(LIB_DIR)

EXECUTABLE = bin


#.SILENT:


all: dup_src_tree $(EXECUTABLE) $(SOURCES) 

$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(LDLIBS) $(OBJECTS) -o $@ $(LSFMLFL)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(HEADERS) 
	$(CC) $(CFLAGS) -c "$<" $(INCLUDE_DIRS) -o "$@"

dup_src_tree:
	@for f in  "$(shell find $(SRC_DIR) -type d -not -wholename $(SRC_DIR))"; do \
		mkdir -pv "$(OBJ_DIR)/$$(echo $$f | sed "s/[./]*\w*\///")";\
	done

rebuild: r
re: r
r: clean all  
	
clean: c
cl: c
c:
	rm $(EXECUTABLE) $(OBJECTS)
