/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkukhale <lkukhale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 17:44:59 by lkukhale          #+#    #+#             */
/*   Updated: 2022/11/30 20:34:17 by lkukhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stddef.h>
# include <stdarg.h>
# include <stdint.h>

int	ft_printf(const char *str, ...);
int	formated_printer(va_list args, const char format);
int	printprecent(void);
int	printupcasehex(unsigned int nbr);
int	printlowcasehex(unsigned int nbr);
int	printinteger(int nbr);
int	printstring(char *str);
int	printchar(char c);
int	ft_putnbr_base(unsigned int nbr, char *base);
int	putpointer(uintptr_t ptr);

#endif