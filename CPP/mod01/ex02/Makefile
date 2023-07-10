# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lkukhale <lkukhale@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/23 16:24:43 by lkukhale          #+#    #+#              #
#    Updated: 2023/06/23 17:54:41 by lkukhale         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



NAME = brain

SRC = ${addsuffix .cpp, main}
CC = g++
RM = rm -f
CPPFLAGS = -Wall -Wextra -Werror -g -std=c++98 -pedantic
OBJ = ${SRC:.cpp=.o}


all: ${NAME}

${NAME}: ${OBJ}
	${CC} ${CPPFLAGS} ${OBJ} -o ${NAME}

clean:
	${RM} ${OBJ}

fclean: clean
	${RM} ${NAME}

re: fclean ${NAME}

.PHONY: all clean fclean re