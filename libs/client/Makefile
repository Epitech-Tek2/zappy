##
## EPITECH PROJECT, 2021
## zappy
## File description:
## Makefile
##

LIB 				=	libclient.a

SRC					=	GetFileDirectory/GetFileDirectory.cpp	\
						Button/Button.cpp	\
						driver/Network/Network.cpp	\
						driver/Sound/Sound.cpp	\
						sfml/setImage.cpp	\
						sfml/setText.cpp	\

CFLAGS 				=	-w -DDEBUG -Wextra -std=c++14 -O2

LDFLAGS				=	-Iinclude/ -lsfml-graphics

AR 					=	ar rc

MV					=	mv

LIB_OBJ 			=	$(SRC:.cpp=.o)

all:					$(LIB)
						$(MV) $(LIB) ../../bin/

$(LIB):					$(LIB_OBJ)
						$(AR)  $(LIB) $(LIB_OBJ)

clean_lib:
						$(RM) $(LIB)

clean:
						$(RM) $(LIB_OBJ)

fclean:					clean
						$(RM) $(LIB)
						$(RM) ../../bin/$(LIB)

re:						fclean all

.PHONY:					all clean fclean re