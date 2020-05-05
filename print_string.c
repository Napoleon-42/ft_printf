/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napoleon <napoleon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 03:42:48 by napoleon          #+#    #+#             */
/*   Updated: 2020/05/05 04:41:45 by napoleon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft/libft.h"
#include "ft_printf.h"

static void	ft_putstrn(char *str, int max)
{
	int i;

	i = 0;
	while (str[i] && i < max)
	{
		ft_putchar(str[i]);
		i++;
	}
}

int			ft_printf_string(char *str, t_arg buffer)
{
	int i;	

	if(ft_strlen(str) < buffer.precision)
		buffer.arg_size = ft_strlen(str);
	else
		buffer.arg_size = buffer.precision;
	if (buffer.arg_size < buffer.minimal_size)
	{
		i = buffer.minimal_size;
		if (buffer.reverse == 0)
			while(--i > buffer.arg_size)
				ft_putchar(' ');
		ft_putstrn(str, buffer.precision);
		if (buffer.reverse > 0)
			while(--i > buffer.arg_size)
				ft_putchar(' ');
		return (buffer.minimal_size);
	}
	ft_putstrn(str, buffer.precision);
	return (buffer.arg_size);
}

/*
int main(void)
{
	int i;
	t_arg test;
	test.reverse = 1;
	test.precision = 6;
	test.minimal_size = 15;
	test.zero = 1;
	printf("|");
	i = ft_printf_string("printf_test_succes", test);
	printf("|");
	printf("\n\033[0;31m%d", i);
	return(0);
}
*/