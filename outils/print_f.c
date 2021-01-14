/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnelson <lnelson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 13:35:46 by lnelson           #+#    #+#             */
/*   Updated: 2021/01/14 14:17:38 by lnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

void	pf_float(float f, t_print *args)
{
	int		i;
	float	second;
	int		temp;

	second = (f - (int)f) * (f >= 0 ? 1 : -1);
	temp = 0;
	i = 0;
	ft_putnbr_fd((int)f * (f >= 0 ? 1 : -1), 1);
	if (HASH == 1 || second > 0)
		write(1, ".", 1);
	while (second != 0 && i < (PRECIS == -1 ? 6 : PRECIS))
	{
		second *= 10;
		temp = (int)second;
		ft_putchar_fd(temp * (f < 0 ? -1 : 1) + 48, 1);
		second -= temp;
	}
}

int		float_len(float f, t_print *args)
{
	int res;
	int second;
	int i;

	i = 0;
	res = (int)f * (f < 0 ? -1 : 1);
	second = ((f * (f < 0 ? -1 : 1)) - res) * (f < 0 ? -1 : 1);
	if (HASH == 1 || (second != 0 && PRECIS > 0))
		res++;
	while (second != 0 && i < (PRECIS == -1 ? 6 : PRECIS))
	{
		second *= 10;
		second -= (int)second;
		i++;
		res++;
	}
	return (res);
}

void	print_f_norme(int nbr, t_print *args)
{
	ft_putnchar_fd(' ', WIDE - SIZE, 1);
	if (PLUS == 1 || SPACE == 1 || nbr < 0)
		write(1, (nbr < 0 ? "-" : (PLUS == 1 ? "+" : " ")), 1);
	pf_float(nbr, args);
}

int		print_f(float nbr, t_print *args)
{
	SIZE = float_len(nbr, args);
	SIZE += (PLUS == 1 || SPACE == 1 || nbr < 0) ? 1 : 0;
	if (MIN_KEY == 1)
	{
		if (PLUS == 1 || SPACE == 1 || nbr < 0)
			write(1, (nbr < 0 ? "-" : (PLUS == 1 ? "+" : " ")), 1);
		pf_float(nbr, args);
		ft_putnchar_fd(' ', WIDE - SIZE, 1);
	}
	else
	{
		if (ZERO_KEY == 1)
		{
			if (PLUS == 1 || SPACE == 1 || nbr < 0)
				write(1, (nbr < 0 ? "-" : (PLUS == 1 ? "+" : " ")), 1);
			ft_putnchar_fd('0', WIDE - SIZE, 1);
			pf_float(nbr, args);
			return (WIDE > SIZE ? WIDE : SIZE);
		}
		print_f_norme(nbr, args);
	}
	return (WIDE > SIZE ? WIDE : SIZE);
}
