# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lkukhale <lkukhale@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/11 19:53:49 by lkukhale          #+#    #+#              #
#    Updated: 2022/11/30 20:35:07 by lkukhale         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= libftprintf.a
SRCS 		= $(addsuffix .c, ./srcs/ft_putnbr_base ./srcs/ft_putpointer ./srcs/main ./srcs/ft_fotmater)
INCLUDES	= ./includes/
AR			= ar
ARFLAGS		= rc
RANLIB		= ranlib
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
RM 			= rm -f
LIBFT		= ./libft/libft.a

.c.o:
		${CC} ${CFLAGS} -I ${INCLUDES} -c $< -o ${<:.c=.o}

OBJS	= ${SRCS:.c=.o}

${NAME}:	${OBJS}
		make -C ./libft
		cp ${LIBFT} ${NAME}
		${AR} ${ARFLAGS} ${NAME} ${OBJS}
		${RANLIB} ${NAME}

all:	${NAME}

clean:
		cd libft && make clean
		${RM} ${OBJS}

fclean:	clean
		cd libft && make fclean
		${RM} ${NAME}

re:		fclean all

.PHONY:	all clean fclean re