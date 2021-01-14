/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnelson <lnelson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 13:35:38 by lnelson           #+#    #+#             */
/*   Updated: 2021/01/14 14:07:25 by lnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

int		print_c(char c, t_print *args)
{
	if (WIDE > 1)
	{
		if (MIN_KEY != 1)
		{
			ft_putnchar_fd(' ', WIDE - 1, 1);
			ft_putchar_fd(c, 1);
		}
		else
		{
			ft_putchar_fd(c, 1);
			ft_putnchar_fd(' ', WIDE - 1, 1);
		}
	}
	else
		ft_putchar_fd(c, 1);
	return (WIDE > 1 ? WIDE : 1);
}

int		print_s_null(t_print *args)
{
	if (MIN_KEY != 1)
		ft_putnchar_fd(' ', WIDE - (PRECIS >= 6 || PRECIS < 0 ? 6 : 0), 1);
	if (PRECIS >= 6 || PRECIS < 0)
		write(1, "(null)", 6);
	if (MIN_KEY == 1)
		ft_putnchar_fd(' ', WIDE - (PRECIS >= 6 || PRECIS < 0 ? 6 : 0), 1);
	if (PRECIS >= 6 || PRECIS < 0)
		return (WIDE > 6 ? WIDE : 6);
	return (WIDE > 0 ? WIDE : 0);
}

int		print_s(char *str, t_print *args)
{
	int l;

	if (str == NULL)
		return (print_s_null(args));
	l = ((PRECIS >= 0 && PRECIS <= ft_strlen(str)) ? PRECIS : ft_strlen(str));
	if (WIDE > (PRECIS > ft_strlen(str) ? ft_strlen(str) : l))
	{
		if (MIN_KEY != 1)
		{
			ft_putnchar_fd(' ', WIDE - (PRECIS > ft_strlen(str) ? ft_strlen(str) : l), 1);
			ft_putnstr_fd(str, l, 1);
		}
		else
		{
			ft_putnstr_fd(str, PRECIS, 1);
			ft_putnchar_fd(' ', WIDE - (PRECIS > ft_strlen(str) ? ft_strlen(str) : l), 1);
		}
	}
	else
		ft_putnstr_fd(str, PRECIS, 1);
	if (str != NULL && *str == 0)
		return (WIDE != -1 ? WIDE : 0);
	return (WIDE >= l ? WIDE : (PRECIS > ft_strlen(str) ? ft_strlen(str) : l));
}
