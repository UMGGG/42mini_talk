# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaeyjeon <@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/04 20:00:47 by jaeyjeon          #+#    #+#              #
#    Updated: 2022/07/05 18:10:27 by jaeyjeon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= minitalk

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra
ar			= ar rcs
RM			= rm -f

LIB_DIR		= ./lib/libft

SRCS			= client.c change_bit_cl.c set_data.c server.c set_data.c\
				 change_bit_se.c

CLIENT_SRCS		= client.c change_bit_cl.c set_data.c

SERVER_SRCS		= server.c set_data.c change_bit_se.c

SERVER_OBJS		=	$(SERVER_SRCS:.c=.o)

CLIENT_OBJS		=	$(CLIENT_SRCS:.c=.o)

%.o : %.c
		${CC} ${CFLAGS} -c -o $@ $<

$(NAME):	$(SERVER_OBJS) $(CLIENT_OBJS)
			make -C $(LIB_DIR)
			$(CC) ${CFLAGS} $(SERVER_OBJS) -L $(LIB_DIR) -lft -o server
			$(CC) ${CFLAGS} $(CLIENT_OBJS) -L $(LIB_DIR) -lft -o client

all: 		$(NAME)

clean:
			make -C $(LIB_DIR) clean
			$(RM) $(SERVER_OBJS)
			$(RM) $(CLIENT_OBJS)

fclean:		clean
			make -C $(LIB_DIR) fclean
			$(RM) server
			$(RM) client

re:			clean all

PHONY:		all clean fclean re
