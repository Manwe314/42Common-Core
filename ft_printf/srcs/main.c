/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkukhale <lkukhale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:13:18 by lkukhale          #+#    #+#             */
/*   Updated: 2023/03/08 19:59:28 by lkukhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/libft.h"

int	printprecent(void)
{
	write(1, "%", 1);
	return (1);
}

int	printunsigneddecimal(unsigned int nbr)
{
	return (ft_putnbr_base(nbr, "0123456789"));
}

int	printvoidpointer(unsigned long long ptr)
{
	int	print_size;

	print_size = 0;
	print_size += write(1, "0x", 2);
	if (ptr == 0)
		print_size += write(1, "0", 1);
	else
		print_size += putpointer(ptr);
	return (print_size);
}

int	formated_printer(va_list args, const char format)
{
	int	print_size;

	print_size = 0;
	if (format == 'c')
		print_size += printchar(va_arg(args, int));
	else if (format == 's')
		print_size += printstring(va_arg(args, char *));
	else if (format == 'p')
		print_size += printvoidpointer(va_arg(args, unsigned long long));
	else if (format == 'd' || format == 'i')
		print_size += printinteger(va_arg(args, int));
	else if (format == 'u')
		print_size += printunsigneddecimal(va_arg(args, unsigned int));
	else if (format == 'x')
		print_size += printlowcasehex(va_arg(args, unsigned int));
	else if (format == 'X')
		print_size += printupcasehex(va_arg(args, unsigned int));
	else if (format == '%')
		print_size += printprecent();
	return (print_size);
}

int	ft_printf(const char *str, ...)
{
	int		print_size;
	int		i;
	va_list	args;

	print_size = 0;
	i = 0;
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] != '%')
		{
			ft_putchar_fd(str[i], 1);
			print_size++;
		}
		else if (str[i] == '%')
		{
			print_size += formated_printer(args, str[i + 1]);
			i++;
		}
		i++;
	}
	va_end(args);
	return (print_size);
}
