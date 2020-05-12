/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napoleon <napoleon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 04:48:09 by lnelson           #+#    #+#             */
/*   Updated: 2020/05/12 05:03:10 by napoleon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> // NOUBLIE PAS PUTAIN TA MERE
#include <stdarg.h>
#include "libft/libft.h"
#include "ft_printf.h"


////////////////////////////////////////////////////////////////////////////////////////////////////

void	test_print_arg(t_arg test)
{
	printf("\nARG_TYPE = %c\n", test.arg_type);
	printf("REVERSE = %c\n", test.reverse);
	printf("ZERO_KEY = %c\n", test.zero);
	printf("ARG_SIZE = %d\n", test.arg_size);
	printf("WIDTH = %d\n", test.minimal_size);
	printf("PRECISION = %d\n", test.precision);
}

///////////////////////////////////////////////////////////////////////////////////////////////////

void	ft_get_argparam(char **str, t_arg *buffer, va_list *args)
{
	while (ft_strrchr("cspdiuxX", (int)**str) == 0)
	{
		if (**str == '.')
		{
			*str++;
			if (**(str) == '*')
				PRECISION = va_arg(*args, int);
			else
			{
				PRECISION = atoi(*str);
				while(ft_isdigit((int)(**(str++)) == 0));
			}
		}
		if (**str == '*')
			WIDTH = va_arg(*args, int);
		if (**str == '-')
			REVERSE++;
		if (**str == '0' && ZERO_KEY == 0)
			ZERO_KEY++;
		if (ft_isdigit((int)**str) == 0 && *str != 0)
		{
			WIDTH = ft_atoi(*str);
			while(ft_isdigit((int)(**(str++)) == 0));
		}
		*str++;
	}
	ARG_TYPE = **str;
}

int ft_print_arg(char **str, t_arg *buffer, va_list *args)
{
	int printed;

	printed = 0;
	ft_get_argparam(str, buffer, args);
	if (buffer->arg_type == 'c')
		printed = ft_printf_char((char)va_arg(*args, char), *buffer);
	if (buffer->arg_type == 's')
		printed = ft_printf_string((char *)va_arg(*args, char*), *buffer);
//	if (buffer->arg_type == 'p')
//		
	if (buffer->arg_type == 'd' && buffer->arg_type == 'i')
		printed = ft_printf_integer((int)va_arg(*args, int), *buffer);
//	if (buffer->arg_type == 'u')
	
//	if (buffer->arg_type == 'x')
	
//	if (buffer->arg_type == 'X')
	printf("printed = %d", printed);

	return (printed);
}

int	ft_printf(const char *str, ...)
{

	va_list args;
	t_arg	buffer;
	int		printed_value;

	va_start(args, str);
	printed_value = 0;
	while (*str)
	{
		if (*str == '%')
		{
			write(1, "_FIRST CHECKPOINT_", 19);
			printed_value = printed_value + ft_print_arg((char **)&str, &buffer, &args);
		}
		else if (*str != '%')
		{
			ft_putchar_fd(*(str), 1);
			str++;
			printed_value++;
		}
	}
}


int main (int ac, char **av)
{
	
	ft_printf("TEST 1 DONE\n");
	ft_printf("TEST 2 INTEGER %d", -21474836);
	
	
	return 0;
		 
}