# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lkukhale <lkukhale@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/20 18:11:01 by lkukhale          #+#    #+#              #
#    Updated: 2023/07/08 16:48:30 by lkukhale         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = zombie

SRC = ${addsuffix .cpp, main Zombie newZombie randomChump}
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