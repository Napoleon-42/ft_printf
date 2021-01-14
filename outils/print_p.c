/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnelson <lnelson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 13:36:01 by lnelson           #+#    #+#             */
/*   Updated: 2021/01/14 13:48:31 by lnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

int		ui_len(__uintmax_t nbr)
{
	int i;

	if (nbr == 0)
		return (1);
	i = 0;
	while (nbr != 0)
	{
		i++;
		nbr /= 16;
	}
	return (i);
}

void	put_uint_base(__uintmax_t nbr, char *str)
{
	if (nbr >= 16)
		put_uint_base(nbr / 16, str);
	ft_putchar_fd(str[nbr % 16], 1);
}

int		print_p_zero(t_print *args)
{
	if (MIN_KEY == 1)
	{
		write(1, "(nil)", 5);
		ft_putnchar_fd(' ', WIDE - 5, 1);
	}
	else
	{
		ft_putnchar_fd(' ', WIDE - 5, 1);
		write(1, "(nil)", 5);
	}
	return (5 < WIDE ? WIDE : 5);
}

void	utils(t_print *args)
{
	write(1, "0x", 2);
	ft_putnchar_fd('0', WIDE - SIZE, 1);
}

int		print_p(__uintmax_t nbr, t_print *args)
{
	if (nbr == 0)
		return (print_p_zero(args));
	SIZE = (ui_len(nbr) < PRECIS ? PRECIS : ui_len(nbr)) + 2;
	if (MIN_KEY == 1)
	{
		write(1, "0x", 2);
		put_uint_base(nbr, "0123456789abcdef");
		if (WIDE > SIZE)
			ft_putnchar_fd(' ', WIDE - SIZE, 1);
	}
	else
	{
		if (ZERO_KEY == 1 && WIDE > SIZE)
			utils(args);
		else if (WIDE > SIZE)
			ft_putnchar_fd(' ', WIDE - SIZE, 1);
		if (ZERO_KEY != 1)
			write(1, "0x", 2);
		if (PRECIS > ui_len(nbr))
			ft_putnchar_fd('0', PRECIS - ui_len(nbr), 1);
		put_uint_base(nbr, "0123456789abcdef");
	}
	return ((WIDE > SIZE) ? WIDE : SIZE);
}
