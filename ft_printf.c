/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napoleon <napoleon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 04:48:09 by lnelson           #+#    #+#             */
/*   Updated: 2020/03/18 02:58:35 by napoleon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#define ARG_TYPE arg->arg_type
#define REVERSE	arg->reverse
#define ZERO_KEY arg->zero
#define ARG_SIZE arg->arg_size
#define TOTAL_SIZE arg->total_size
#define PRECISION arg->precision

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

void	ft_putnstr(char *str, buffer *var)

{
	int i;

	i = 0;
	if (var->pres_key)
	while(str[i] && i < var->pres_val)
	{
		write(1, (str + i), 1);
		i++;
		var->printed_nb++;
	}
	return ;
}

int		ft_print_arg(char *str, t_arg *buffer, va_list *args)
{
	ft_get_argparam(str, buffer, args);
	while (ft_strchr("cspdiuxX", *str) == 0)
	{
		if (str == ' ')
		
		*******

		if (str == '*')
		//size = param ****

		*******
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
