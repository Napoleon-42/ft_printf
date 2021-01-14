/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_outils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnelson <lnelson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 13:35:22 by lnelson           #+#    #+#             */
/*   Updated: 2021/01/14 13:35:23 by lnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

void	init_print(t_print *args)
{
	PRECIS = -1;
	WIDE = -1;
	ZERO_KEY = -1;
	MIN_KEY = -1;
	SIZE = 0;
	ARG_TYPE = 0;
	HASH = -1;
	PLUS = -1;
	SPACE = -1;
}

void	get_param_uts(int num, t_print *args)
{
	if (num < 0)
	{
		WIDE = -num;
		MIN_KEY = 1;
	}
	else
		WIDE = num;
	return;
}

void	get_param_ut(const char **str, va_list *ap, t_print *args)
{
	if (**str == '.')
	{
		(*str)++;
		if (**str == '*')
			PRECIS = va_arg(*ap, int);
		else
		{
			PRECIS = ft_atoi(*str);
			while (ft_isdigit(**str) == 42)
				(*str)++;
			(*str)--;
		}
	}
	else if (ft_isdigit(**str) == 42)
	{
		WIDE = ft_atoi(*str);
		while (ft_isdigit(**str) == 42)
			(*str)++;
		(*str)--;
	}
}

void	get_param(const char **str, va_list *ap, t_print *args)
{
	(*str)++;
	while(ft_strchr("cspdiuxXnefg%\0", **str) == NULL)
	{
		if (**str == ' ')
			SPACE = 1;
		if (**str == '+')
			PLUS = 1;
		if (**str == '#')
			HASH = 1;
		if (**str == '-')
			MIN_KEY = 1;
		if (**str == '0')
			ZERO_KEY = 1;
		if (**str == '*')
			get_param_uts(va_arg(*ap, int), args);
		if (**str == '.' || ft_isalnum(**str))
			get_param_ut(str, ap, args);
		(*str)++;
	}
	ARG_TYPE = **str;
}
