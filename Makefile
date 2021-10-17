##
## EPITECH PROJECT, 2021
## Zappy Project
## File description:
## Makefile
##

ZAPPY_SERVER_PATH	=	packages/server/src
ZAPPY_GUI_PATH	=	packages/client
ZAPPY_LIBS_PATH	=	libs/

all:	zappy_libs zappy_server zappy_gui


zappy_server:
	make -C $(ZAPPY_SERVER_PATH) -s

zappy_gui:
	make -C $(ZAPPY_GUI_PATH) -s

zappy_libs:
	make -C $(ZAPPY_LIBS_PATH) -s

clean:
	make clean -C $(ZAPPY_LIBS_PATH) -s
	make clean -C $(ZAPPY_SERVER_PATH) -s
	make clean -C $(ZAPPY_GUI_PATH) -s

fclean:

	make fclean -C $(ZAPPY_LIBS_PATH) -s
	make fclean -C $(ZAPPY_SERVER_PATH) -s
	make fclean -C $(ZAPPY_GUI_PATH) -s

re:
	make re -C $(ZAPPY_LIBS_PATH) -s
	make re -C $(ZAPPY_SERVER_PATH) -s
	make re -C $(ZAPPY_GUI_PATH) -s

.PHONY: all zappy_server zappy_gui clean fclean re