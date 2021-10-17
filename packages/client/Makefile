##
## EPITECH PROJECT, 2021
## zappy_gui
## File description:
## Makefile
##

NAME	=	zappy_gui
SRC		=	src/main.cpp \
			src/engine/Core.cpp	\
			src/engine/Interface.cpp	\
			src/scene/intro/Intro.cpp	\
			src/scene/menu/Menu.cpp	\
			src/scene/gameSolo/GameSolo.cpp	\
			src/scene/gameMulti/GameMulti.cpp	\
			src/player/Inventory.cpp	\

OBJ		=	$(SRC:.cpp=.o)
CC		=	g++
CFLAGS	=	-W -Wall -Wextra -Ofast -std=c++17 -I../utils/ -I./src/ -O2
LDFLAGS	=	-lclient -L../../bin/ -lsfml-graphics -lsfml-window -lsfml-audio  -lsfml-system -framework GLUT -framework OpenGL -framework Cocoa
RM		=	rm -f

RED		=	\033[31;1m
GREEN	=	\033[32;1m
BLUE	=	\033[34;1m
NORMAL	=	\033[0m

all:	$(NAME)

$(NAME): $(OBJ)
	@printf "$(BLUE)[CORE] $(NAME)$(NORMAL)\n"
	@$(CC) -o ../../$(NAME) $(OBJ) $(LDFLAGS)
	@printf "$(GREEN)[CORE] $(NAME) Compiled !$(NORMAL)\n"

%.o: %.cpp
	@printf "$(BLUE)[CORE] $< -> $@$(NORMAL)\n"
	@$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@$(RM) $(OBJ) $(RM_FILE)
	@printf "$(RED)[CORE] $(NAME) Removed$(NORMAL)\n"

fclean:
	@$(RM) $(OBJ) $(RM_FILE)
	@printf "$(RED)[CORE] $(NAME) Removed$(NORMAL)\n"
	@$(RM) ../../$(NAME)
	@printf "$(RED)[CORE] $(NAME)$(NORMAL)\n"

re: fclean all

.PHONY: all clean fclean re
