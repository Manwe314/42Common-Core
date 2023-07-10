# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lkukhale <lkukhale@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/11 19:53:49 by lkukhale          #+#    #+#              #
#    Updated: 2023/04/30 18:53:50 by lkukhale         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= so_long
USER		= lkukhale
SRCS 		= ${addsuffix .c, \
						 ./src/main ./src/get_next_line \
						 ./src/get_next_line_utils ./src/map_utils \
						 ./src/map_utils_two ./src/map_handler ./src/map_paint_utils_two \
						 ./src/map_paint_utils ./src/map_paint ./src/game_info_two ./src/game_info \
						 ./src/game_three ./src/game_two ./src/game ./src/f_norm ./src/game_four}
HEADERS		= -I ./includes/ -I ${LIBMLX}/include/ -I ${LIBPRINTF}/includes/ -I /Users/${USER}/.brew/Cellar/glfw/3.3.8/include/
LIBS		= -lglfw -L /Users/${USER}/.brew/opt/glfw/lib/ ${LIBMLX}/libmlx42.a ${LIBPRINTF}/libftprintf.a
LIBMLX		= ./lib/MLX42
LIBPRINTF	= ./lib/ft_printf
CFLAGS		=  -g -Wall -Wextra -Werror
OBJS		= ${SRCS:.c=.o}
RM			= rm -f




all:	libmlx	libftprintf	${NAME}

libftprintf:
		make -C ${LIBPRINTF}

libmlx:
		make -C ${LIBMLX}

.c.o:
		@${CC} ${CFLAGS} -o $@ -c $< ${HEADERS}

${NAME}:	${OBJS}
		@${CC} ${OBJS} ${LIBS} ${HEADERS} -o ${NAME}

clean:
		${RM} ${OBJS}
		@make -C $(LIBPRINTF) clean
		@make -C $(LIBMLX) clean

fclean:	clean
		${RM} ${NAME}
		@make -C $(LIBPRINTF) fclean
		@make -C $(LIBMLX) fclean

re:		fclean all

.PHONY:	all clean fclean re