# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lkukhale <lkukhale@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/11 19:53:49 by lkukhale          #+#    #+#              #
#    Updated: 2023/05/23 18:45:33 by lkukhale         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= philo
USER		= lkukhale
SRCS 		= ${addsuffix .c, ./src/main ./src/philo_utils_one ./src/philo_input ./src/philo_sim_one ./src/philo_sim_two}
HEADERS		= -I ./includes/
CFLAGS		= -Wall -Wextra -Werror  #-fsanitize=thread -g -O1 #-fsanitize=address
OBJS		= ${SRCS:.c=.o}
RM			= rm -f




all:	${NAME}

.c.o:
		@${CC} ${CFLAGS} -o $@ -c $< ${HEADERS}

${NAME}:	${OBJS}
		@${CC} ${CFLAGS} ${OBJS} ${HEADERS} -o ${NAME}

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}

re:		fclean all

.PHONY:	all clean fclean re