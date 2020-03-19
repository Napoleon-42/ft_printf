/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napoleon <napoleon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 04:48:09 by lnelson           #+#    #+#             */
/*   Updated: 2020/03/19 03:28:59 by napoleon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#define ARG_TYPE buffer->arg_type
#define REVERSE	buffer->reverse
#define ZERO_KEY buffer->zero
#define ARG_SIZE buffer->arg_size
#define WIDTH buffer->total_size
#define PRECISION buffer->precision

typedef	struct	progression
{
	char	arg_type;
	char	reverse;
	char	zero;
	int		arg_size;
	int		total_size;
	int		precision;
}				t_arg;

char	*ft_strchr(const char *s, int c)
{
	char *str;

	str = (char *)s;
	while (*str != c)
	{
		if (*str == 0)
			return (0);
		str++;
	}
	return (str);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
	return ;
}

int		ft_print_arg(char *str, t_arg *buffer, va_list *args)
{
	ft_get_argparam(str, buffer, args);
	while (ft_strchr("cspdiuxX", *str) == 0)
	{
		if (str == '.')
		{
			str++;
			if (*(str) == '*')
				PRECISION = va_copy(args, int);
			else
			{
				PRECISION = atoi(str);
				while(ft_isdigit((int)*str) == 0)
					str++;
			}
		}                                      /// TA PLU DE LIGNE, +4 SUR ATOI >> TABLEAU :| 
		if (str == '*')
			WIDTH = va_copy(args, int);
		if (str == '-')
			REVERSE++;
		if (str == '0' && ZERO_KEY == 0)
			ZERO_KEY++;
		if (ft_isdigit((int)*str) == 0)
		{
			WIDTH = atoi(str);
			while(ft_isdigit((int)*str) == 0)
				str++;
		}
		
	}
	

	*************************************************


	//printf ()

	
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

	va_list args;
	t_arg	buffer;
	int		i;

	va_start(args, str);
	i = 0;
	while (*str)
	{
		if (*str == '%')
			i = i + ft_print_arg(str, &buffer, &args);
		else if (*str != '%')
		{
			ft_putchar(*(str));
			str++;
			i++;
		}
	}
}
