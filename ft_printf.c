/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napoleon <napoleon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 04:48:09 by lnelson           #+#    #+#             */
/*   Updated: 2020/03/05 15:14:25 by napoleon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

typedef	struct	progression
{
	char	pres_key;
	char	null_key;
	char	index;
	char	precision;
	int		printed_nb;
}				buffer;

void	ft_putchar(char c)
{
	write(1, &c, 1);
	return ;
}

void	ft_putnstr(char *str, buffer *var)

{
	int i;

	i = 0;
	if (var->pres_key)
	while(str[i] && i < var->precision)
	{
		write(1, (str + i), 1);
		i++;
		var->printed_nb++;
	}
	return ;
}

int ft_big_hex(char *pointer, buffer *buff)
{
	return (1);	
}

int ft_small_hex(char *pointer, buffer *buff)
{
	return (1);	
}

int ft_integer(char *pointer, buffer *buff)
{
	return (1);	
}

int ft_string(char *pointer, buffer *buff)
{
	return (1);	
}

int ft_char(char *pointer, buffer *buff)
{
	return (1);	
}

int	ft_printf(const char *str, ...)
{

	va_list arguments;
	buffer	var;

	va_start(arguments, str);
	while (*str)
	{
		if (*str == '%')
			ft_printf_brain(&str, &var, arguments);
		else if (*str != '%')
		{
			ft_putchar(*(str));
			str++;
			var.printed_nb++;
		}
	}
}
