/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fotmater.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkukhale <lkukhale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 20:31:45 by lkukhale          #+#    #+#             */
/*   Updated: 2023/03/15 20:28:31 by lkukhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	printchar(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	printstring(char *str)
{
	char	*nul;

	nul = ft_strdup("(null)");
	if (str == 0)
	{
		ft_putstr_fd(nul, 1);
		free(nul);
		return (6);
	}
	free(nul);
	ft_putstr_fd(str, 1);
	return ((int)ft_strlen(str));
}

int	printinteger(int nbr)
{
	char	*str;
	int		len;

	str = ft_itoa(nbr);
	ft_putstr_fd(str, 1);
	len = (int)ft_strlen(str);
	free(str);
	return (len);
}

int	printlowcasehex(unsigned int nbr)
{
	return (ft_putnbr_base(nbr, "0123456789abcdef"));
}

int	printupcasehex(unsigned int nbr)
{
	return (ft_putnbr_base(nbr, "0123456789ABCDEF"));
}
