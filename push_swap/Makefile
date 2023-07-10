# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lkukhale <lkukhale@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/11 19:53:49 by lkukhale          #+#    #+#              #
#    Updated: 2023/03/10 20:48:57 by lkukhale         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= push_swap
BNAME		= checker
USER		= lkukhale
SRCS 		= ${addsuffix .c, ./src/main ./src/quick_sort \
						./src/validate ./src/handle_input \
						./src/actions_a ./src/actions_b \
						./src/actions_double ./src/stage1 ./src/greedy_one \
						./src/greedy_two ./src/greedy_three ./src/small_clean}
BNSRCS		= ${addsuffix .c, ./bsrc/main_bonus \
						./src/quick_sort ./src/validate ./src/handle_input \
						./src/actions_a ./src/actions_b ./src/actions_double \
						./bsrc/get_next_line ./bsrc/get_next_line_utils \
						./bsrc/checker_utils_one ./bsrc/checker_utils_two}
HEADERS		= -I ./includes/ -I ${LIBPRINTF}/includes/
LIBS		= ${LIBPRINTF}/libftprintf.a
LIBPRINTF	= ./lib/ft_printf
CFLAGS		= -Wall -Wextra -Werror
OBJS		= ${SRCS:.c=.o}
BOBJS		= ${BNSRCS:.c=.o}
RM			= rm -f




all:	libftprintf	${NAME} bonus

libftprintf:
		make -C ${LIBPRINTF}

.c.o:
		@${CC} ${CFLAGS} -o $@ -c $< ${HEADERS}

${NAME}:	${OBJS}
		@${CC} ${OBJS} ${LIBS} ${HEADERS} -o ${NAME}

bonus:	libftprintf ${BOBJS}
		@${CC} ${CFLAGS} ${BOBJS} ${LIBS} ${HEADERS} -o ${BNAME}

clean:
		${RM} ${OBJS}
		${RM} ${BOBJS}
		@make -C $(LIBPRINTF) clean

fclean:	clean
		${RM} ${NAME}
		${RM} ${BNAME}
		@make -C $(LIBPRINTF) fclean

re:		fclean all

.PHONY:	all clean fclean re