# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lkukhale <lkukhale@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/11 19:53:49 by lkukhale          #+#    #+#              #
#    Updated: 2023/03/14 16:30:30 by lkukhale         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= pipex
USER		= lkukhale
SRCS 		= ${addsuffix .c, ./src/main ./src/pipex_one ./src/pipex_two}
HEADERS		= -I ./includes/ -I ${LIBPRINTF}/includes/
LIBS		= ${LIBPRINTF}/libftprintf.a
LIBPRINTF	= ./lib/ft_printf
CFLAGS		= -Wall -Wextra -Werror -g
OBJS		= ${SRCS:.c=.o}
RM			= rm -f




all:	libftprintf	${NAME}

libftprintf:
		make -C ${LIBPRINTF}

.c.o:
		@${CC} ${CFLAGS} -o $@ -c $< ${HEADERS}

${NAME}:	${OBJS}
		@${CC} ${OBJS} ${LIBS} ${HEADERS} -o ${NAME}

clean:
		${RM} ${OBJS}
		@make -C $(LIBPRINTF) clean

fclean:	clean
		${RM} ${NAME}
		@make -C $(LIBPRINTF) fclean

re:		fclean all

.PHONY:	all clean fclean re