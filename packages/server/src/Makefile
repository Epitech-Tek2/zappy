##
## EPITECH PROJECT, 2021
## zappy
## File description:
## Makefile
##

CC	=	gcc

RM	=	rm -f

SRC_MAIN	=	main.c	\
				server.c	\
				file.c

UTILS_PATH	=	utils/
UTILS_SRC	=	strctok.c	\
				parse_username.c	\
				send_logs_to_client.c

COMMAND_PATH	=	commands/
COMMAND_SRC	=	user/uuid.c \
				msz.c	\
				bct.c 	\
				mct.c 	\
				tna.c	\
				pnw.c	\
				ppo.c	\
				plv.c	\
				pin.c	\
				pex.c	\
				pbc.c	\
				pic.c	\
				pie.c	\
				pfk.c	\
				pdr.c	\
				pgt.c	\
				pdi.c	\
				enw.c	\
				eht.c	\
				ebo.c	\
				sgt.c	\
				smg.c	\
				suc.c	\
				sbp.c	\
				seg.c	\
				sst.c	\
				edi.c	\
				nop.c	\
				login.c	\
				users.c	\
				user.c

CLIENT_PATH	=	client/
CLIENT_SRC	=	handle.c	\
				close.c	\
				client.c	\
				logout.c

SRC	=	$(SRC_MAIN)	\
		$(addprefix $(COMMAND_PATH), $(COMMAND_SRC))	\
		$(addprefix $(UTILS_PATH), $(UTILS_SRC))	\
		$(addprefix $(CLIENT_PATH), $(CLIENT_SRC))

NAME	=	../../../zappy_server

CFLAGS	=	-I../../includes -lm -g

LDFLAGS	=	-lstring -L../../../bin/ -lcstring -L../../../bin/ -L../../../bin -llist \
	-L../../../libs/zappy/ -luuid

OBJS	=	$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(CFLAGS) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re