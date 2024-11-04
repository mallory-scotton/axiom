###############################################################################
###
### MIT License
###
### Copyright(c) 2024 Mallory SCOTTON
###
### Permission is hereby granted, free of charge, to any person obtaining a
### copy of this software and associated documentation files (the "Software"),
### to deal in the Software without restriction, including without limitation
### the rights to use, copy, modify, merge, publish, distribute, sublicense,
### and#or sell copies of the Software, and to permit persons to whom the
### Software is furnished to do so, subject to the following coditions:
###
### The above copyright notice and this permission notice shall be included
### in all copies or substantial portions of the Software?
###
### THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
### IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
### FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
### AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
### LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
### FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
### DEALINGS IN THE SOFTWARE.
###
###############################################################################

###############################################################################
#                               CONFIGURATION                                 #
###############################################################################

# Build
NAME              = libaxiom
BUILD_DIR         = ./build

# Compilation
CC                = g++
CFLAGS            = -std=c++17 -Wall -Wextra -Iinclude
DFLAGS            = -MMD -MF $(@:.o=.d)
LFLAGS            = -lsfml-graphics \
                    -lsfml-system \
                    -lsfml-window \
                    -lsfml-audio \
                    -lGL

FLAGS             = $(CFLAGS) $(DFLAGS) $(LFLAGS)

# Metadata
AUTHOR            = mallory-scotton
DATE              =
HASH              =

# Visual
NO_VISUAL         = 0

###############################################################################
#                                  SOURCES                                    #
###############################################################################

# File extension
EXTENSION         = .cpp

SOURCES           = ./source/axiom/math/vector2.cpp \
                    ./source/axiom/math/vector3.cpp \
                    ./source/axiom/window/videoMode.cpp

###############################################################################
#                              MAKEFILE OBJECTS                               #
###############################################################################

# Shell used by the Makefile
SHELL            := /bin/bash

# Convert the sources to objects (.o) and dependencies (.d)
OBJECTS           = $(SOURCES:$(EXTENSION)=.o)
DEPENDENCIES      = $(SOURCES:$(EXTENSION)=.d)

# Constant for library format
STATIC_LIB_EXT    = a
DLL_EXT           = so

# Special case, on windows, the format of the library will be .dll
ifeq ($(OS), Windows_NT)
    DLL_EXT       = dll
endif

###############################################################################
#                               MAKEFILE LOGIC                                #
###############################################################################

# Constant for colors
COM_COLOR         = \033[0;34m
OBJ_COLOR         = \033[0;36m
OK_COLOR          = \033[0;32m
ERROR_COLOR       = \033[0;31m
WARN_COLOR        = \033[0;33m
NO_COLOR          = \033[m

# Compilation text
COM_STRING        = "compiling"

# Find the OS of the user
ifeq ($(OS), Windows_NT)
    DETECTED_OS  := Windows
else
    DETECTED_OS  := $(shell sh -c 'uname 2> /dev/null || echo Unknown')
endif

# Define the run command based on the operating system of the user
ifeq ($(DETECTED_OS), Darwin)
    RUN_CMD       = script -q $@.log $1 > /dev/null; \
                    RESULT=$$?
else ifeq ($(DETECTED_OS), Linux)
    RUN_CMD       = script -q -e -c "$(1)" $@.log > /dev/null; \
                    RESULT=$$?; \
                    sed -i '1d' $@.log; \
                    sed -i "$$(($$(wc -l < $@.log)-1)),\$$d" $@.log
else
    RUN_CMD       = $(1) 2> $@.log; \
                    RESULT=$$?
endif

# If the directory is a Github repo, find the different information
ifeq ($(shell git rev-parse HEAD &>/dev/null; echo $$?), 0)
    AUTHOR       := $(shell git log --format='%aN' | sort -u | awk \
                        '{printf "%s, ", $$0}' | rev | cut -c 3- | rev)
    DATE         := $(shell git log -1 --date=format:"%Y/%m/%d %T" \
                        --format="%ad")
    HASH         := $(shell git rev-parse --short HEAD)
endif

# Define a function utils to run and print the result of the command
define Run
printf "%b%-46b" "$(COM_COLOR)$(COM_STRING) " "$(OBJ_COLOR)$(@F)$(NO_COLOR)"; \
$(RUN_CMD); \
if [ $$RESULT -ne 0 ]; then \
    printf "%b\n" "$(ERROR_COLOR)[✖]$(NO_COLOR)          "; \
    rm -rf .files_changed; \
    if [ $(NO_VISUAL) -eq 0 ]; then \
        echo; \
    fi; \
elif [ -s $@.log ]; then \
    printf "%b\n" "$(WARN_COLOR)[⚠]$(NO_COLOR)          "; \
else \
    printf "%b\n" "$(OK_COLOR)[✓]$(NO_COLOR)          "; \
fi; \
cat $@.log; \
rm -f $@.log; \
exit $$RESULT
endef

# Save the modified files to a temporary file
define SaveModifiedFiles
FILE_CPP=`echo $(SOURCES)`; \
FILE_OBJ=`echo $(OBJECTS)`; \
TO_COMPILE=`echo $$FILE_CPP | wc -w`; \
for FILE in $$FILE_CPP; do \
    for OBJ in $$FILE_OBJ; do \
        if [ $${FILE%$(EXTENSION)} = $${OBJ%.o} ]; then \
            if [ $$FILE -ot $$OBJ ]; then \
                FILE_DEP=`echo $$OBJ | sed 's/\.o/\.d/'`; \
                HEAD_FILES=`< $$FILE_DEP xargs | grep -oh "\w*.h\w*"`; \
                RECOMPILE=0; \
                for HEAD in $$HEAD_FILES; do \
                    if [ $$HEAD -nt $$OBJ ]; then \
                        RECOMPILE=1; \
                        break; \
                    fi; \
                done; \
                if [ $$RECOMPILE -eq 0 ]; then \
                    ((TO_COMPILE=$$TO_COMPILE-1)); \
                fi;\
            fi;\
        fi;\
    done; \
done; \
echo 0/$$TO_COMPILE > .files_changed
endef

# Draw the loading bar
define DrawProgressBar
FILE_TOTAL=`bash -c 'cat .files_changed | cut -d"/" -f2'`; \
FILE_DONE=`bash -c 'cat .files_changed | cut -d"/" -f1'`; \
if [ $$FILE_TOTAL -eq 0 ]; then \
    FILE_TOTAL=1; \
    FILE_DONE=1; \
fi; \
RES=`echo "scale=2; $$FILE_DONE/$$FILE_TOTAL*48" | bc`; \
RES=`echo $${RES%%.*}`; \
printf "$(OBJ_COLOR)[$(NO_COLOR)"; \
i=0; \
while [ $$i -lt 48 ]; do \
    if [ $$i -lt $$RES ]; then \
        printf "$(OK_COLOR)█$(NO_COLOR)"; \
    else \
        printf "$(COM_COLOR)▒$(NO_COLOR)"; \
    fi; \
    ((i=$$i+1)); \
done; \
printf "$(OBJ_COLOR)]$(NO_COLOR)"; \
printf " ($(COM_COLOR)$$FILE_DONE$(NO_COLOR)/$(COM_COLOR)$$FILE_TOTAL$(NO_COLOR))"; \
printf " "; \
((FILE_DONE=$$FILE_DONE+1)); \
echo $$FILE_DONE/$$FILE_TOTAL > .files_changed;
endef

define DisplayProgressBar
if [ $(NO_VISUAL) -eq 0 ]; then \
    line=`bash -c 'oldstty=$$(stty -g); stty raw -echo min 0; tput u7 > \
        /dev/tty; IFS=";" read -r -d R -a pos; stty $$oldstty; \
        row=$$(($${pos[0]:2} - 1)); echo $$row'`; \
    max_line=`tput lines`; \
    ((max_line=$$max_line-2));\
    new_line=0; \
    tput sc; \
    i=0; \
    while [ $$i -lt 60 ]; do \
        printf " "; \
        ((i=$$i+1)); \
    done; \
    tput rc; \
    if [ $$line -gt $$max_line ]; then \
        new_line=1; \
        echo ; \
    else \
        ((line=$$line+1));\
    fi; \
    tput sc; \
    tput cup $$line; \
    $(DrawProgressBar) \
    if [ $$new_line -eq 1 ]; then \
        ((line=$$line-1));\
        tput cup $$line; \
    else \
        tput rc; \
    fi; \
fi;
endef

###############################################################################
#                               MAKEFILE RULES                                #
###############################################################################

header:
	@printf "%b" "$(OK_COLOR)"
	@cat axiom.art
	@echo
ifneq ($(HASH),)
	@printf "%b" "$(OBJ_COLOR)Name:	$(WARN_COLOR)$(NAME)@$(HASH)\n"
else
	@printf "%b" "$(OBJ_COLOR)Name:	$(WARN_COLOR)$(NAME)\n"
endif
	@printf "%b" "$(OBJ_COLOR)Author:	$(WARN_COLOR)$(AUTHOR)\n"
	@printf "%b" "$(OBJ_COLOR)Date: 	$(WARN_COLOR)$(DATE)\n\033[m"
	@printf "%b" "$(OBJ_COLOR)CC: 	$(WARN_COLOR)$(CC)\n\033[m"
	@printf "%b" "$(OBJ_COLOR)Flags: 	$(WARN_COLOR)$(CFLAGS)\n\033[m"
	@echo

-include $(DEPENDENCIES)

setup:
	@$(call SaveModifiedFiles)

static: FLAGS += -DAXIOM_STATIC
static: header setup $(NAME).$(STATIC_LIB_EXT)

restatic: fclean static

dynamic: header setup $(NAME).$(DLL_EXT)

redynamic: fclean dynamic

$(NAME).$(DLL_EXT): $(OBJECTS)
	@mkdir -p $(BUILD_DIR)
	@$(call Run, ar rcs $(BUILD_DIR)/$@ $^)
	@rm -rf .files_changed
	@printf "%-53b%b" "$(COM_COLOR)dynamic:" "$(OK_COLOR)[✓]$(NO_COLOR)\n"

$(NAME).$(STATIC_LIB_EXT): $(OBJECTS)
	@mkdir -p $(BUILD_DIR)
	@$(call Run, ar rcs $(BUILD_DIR)/$@ $^)
	@rm -rf .files_changed
	@printf "%-53b%b" "$(COM_COLOR)static:" "$(OK_COLOR)[✓]$(NO_COLOR)\n"

%.o: %.cpp
	@$(call DisplayProgressBar)
	@$(call Run, $(CC) $(FLAGS) -c $< -o $@)

clean: header
	@find -type f -iname "*.o" -delete
	@find -type f -iname "*.d" -delete
	@find -type f -iname "*.gcda" -delete
	@find -type f -iname "*.gcno" -delete
	@find -type f -iname "*.html" -delete
	@find -type f -iname "*.css" -delete
	@printf "%-53b%b" "$(COM_COLOR)clean:" "$(OK_COLOR)[✓]$(NO_COLOR)\n"

fclean: header clean
	@rm -rf $(BUILD_DIR)
	@printf "%-53b%b" "$(COM_COLOR)fclean:" "$(OK_COLOR)[✓]$(NO_COLOR)\n"

.PHONY: all static dynamic clean fclean setup
