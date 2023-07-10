/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkukhale <lkukhale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 20:46:13 by lkukhale          #+#    #+#             */
/*   Updated: 2022/12/13 18:33:43 by lkukhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 64
# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
int		ft_strchrnl(char *s, char c);
char	*ft_strjoint(char *s1, char *s2);
int		ft_strlennl(char *str);
#endif