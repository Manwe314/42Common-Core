# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: beaudibe <beaudibe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/11 19:53:49 by lkukhale          #+#    #+#              #
#    Updated: 2023/07/03 17:10:03 by beaudibe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= minishell
USER		= lkukhale


SRCS 		=	src/arguments_one.c 			\
				src/env.c 						\
				src/get_next_line_utils_bonus.c \
				src/pwd.c 						\
				src/split_utils.c 				\
				src/arguments_two.c 			\
				src/execution.c 				\
				src/global.c 					\
				src/redirect_four.c 			\
				src/unset.c 					\
				src/builtin.c 					\
				src/exit.c 						\
				src/handle_dollar.c 			\
				src/redirect_three.c 			\
				src/utils_one.c 				\
				src/cd.c 						\
				src/expoort_four.c 				\
				src/heredoc.c 					\
				src/redirect_two.c 				\
				src/validation_one.c 			\
				src/clean_up.c 					\
				src/export.c 					\
				src/history.c 					\
				src/redirect_utils_one.c 		\
				src/validation_two.c 			\
				src/command_one.c 				\
				src/export_one.c 				\
				src/input_handler.c 			\
				src/redirect_utils_two.c 		\
				src/command_three.c 			\
				src/export_three.c 				\
				src/main.c 						\
				src/redirection_one.c 			\
				src/command_two.c 				\
				src/export_two.c 				\
				src/piping_one.c 				\
				src/signal.c 					\
				src/echo.c 						\
				src/get_next_line_bonus.c 		\
				src/piping_two.c 				\
				src/split_q.c					\
				src/export_five.c				\
				src/norm_overflow.c

# HEADERS		= -I./includes
# LIBS		= ${LIBFT}/libft.a -L


READLINE_PATH := $(shell brew --prefix readline)

HEADERS = -I./includes -I$(READLINE_PATH)/include
LIBS = ${LIBFT}/libft.a -L$(READLINE_PATH)/lib
LIBFT		= ./lib/libft
CFLAGS		= -Wall -Wextra -Werror -g
OBJS		= ${SRCS:.c=.o}
RM			= rm -f


all:	libft	${NAME}

libft:
		make -C ${LIBFT}

.c.o:
		@${CC} ${CFLAGS} -o $@ -c $< ${HEADERS}

${NAME}: ${OBJS}
	@${CC} ${OBJS} ${LIBS} ${HEADERS} -o ${NAME} -lreadline

clean:
		${RM} ${OBJS}
		@make -C $(LIBFT) clean

fclean:	clean
		${RM} ${NAME}
		@make -C $(LIBFT) fclean

re:		fclean all

brew:
		brew install readline

git:	fclean
		git add .
		git commit -m "auto commit"
		git push

.PHONY:	all clean fclean re
