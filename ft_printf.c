/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napoleon <napoleon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 04:48:09 by lnelson           #+#    #+#             */
/*   Updated: 2020/05/06 04:18:19 by napoleon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft/libft.h"
#include "ft_printf.h"
#define ARG_TYPE buffer->arg_type
#define REVERSE	buffer->reverse
#define ZERO_KEY buffer->zero
#define ARG_SIZE buffer->arg_size
#define WIDTH buffer->minimal_size
#define PRECISION buffer->precision


////////////////////////////////////////////////////////////////////////////////////////////////////

test_print_arg(t_arg test)
{
	printf("ARG_TYPE = %c\n", test.arg_type);
	printf("REVERSE = %c\n", test.reverse);
	printf("ZERO_KEY = %c\n", test.zero);
	printf("ARG_SIZE = %d\n", test.arg_size);
	printf("WIDTH = %d\n", test.minimal_size);
	printf("PRECISION = %d\n", test.precision);
}

///////////////////////////////////////////////////////////////////////////////////////////////////

void	ft_putchar(char c)
{
	write(1, &c, 1);
	return ;
}

void	ft_get_argparam(char *str, t_arg *buffer, va_list *args)
{
	while (ft_strchr("cspdiuxX", *str) == 0)
	{
		if (str == '.')
		{
			str++;
			if (*(str) == '*')
				PRECISION = va_arg(*args, int);
			else
			{
				PRECISION = atoi(str);
				while(ft_isdigit((int)(*(str++)) == 0));
			}
		}
		if (str == '*')
			WIDTH = va_arg(*args, int);
		if (str == '-')
			REVERSE++;
		if (str == '0' && ZERO_KEY == 0)
			ZERO_KEY++;
		if (ft_isdigit((int)*str) == 0 && *str != 0)
		{
			WIDTH = atoi(str);
			while(ft_isdigit((int)(*(str++)) == 0));
		}
	}
	ARG_TYPE = *str;
}

int ft_print_arg(char *str, t_arg *buffer, va_list *args)
{
	int printed;

	printed = 0;
	ft_get_argparam(str, buffer, args);
	if (buffer->arg_type == 'c')
	
	if (buffer->arg_type == 's')
	
	if (buffer->arg_type == 'p')
	
	if (buffer->arg_type == 'd')
	
	if (buffer->arg_type == 'i')
	
	if (buffer->arg_type == 'u')
	
	if (buffer->arg_type == 'x')
	
	if (buffer->arg_type == 'X')
	

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
			printed_value = printed_value + ft_print_arg(str, &buffer, &args);
		else if (*str != '%')
		{
			ft_putchar(*(str));
			str++;
			printed_value++;
		}
	}
}


int main (int ac, char **av)
{
	 
}