/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_integer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napoleon <napoleon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 03:42:43 by napoleon          #+#    #+#             */
/*   Updated: 2020/05/06 05:02:44 by napoleon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

static void	ft_putcharn(char c, int n)
{
	int i;

	i = 0;
	while(i < n)
	{
		write(1, &c, 1);
		i++;
	}	
}

int			ft_get_num_size(int num)
{
	int				i;
	unsigned int	nb;

	i = 1;
	if (num < 0)
	{
		nb = -num;
		i++;
	}
	else
		nb = num;
	while (nb > 10)
	{
		i++;
		nb = nb/10;
	}
	return (i);
}

void		ft_print_nb(int num, t_arg buffer)
{
	if (buffer.precision > buffer.arg_size)
	{
		ft_putcharn('0', buffer.precision - buffer.arg_size);
		buffer.precision = 0;
	}
	ft_putnbr_fd(num, 1);
}

int			ft_printf_integer(int num, t_arg buffer)
{
	int i;

	buffer.arg_size = ft_get_num_size(num);
	if (buffer.arg_size < buffer.precision)
		i = buffer.precision;
	else
		i = buffer.arg_size;
	if (buffer.minimal_size > i)
	{
		if (buffer.reverse == 0)
			ft_putcharn(' ', (buffer.minimal_size - i));
		ft_print_nb(num, buffer);
		if (buffer.reverse > 0)
			ft_putcharn(' ', (buffer.minimal_size - i));
		return (buffer.minimal_size);
	}
	ft_print_nb(num, buffer);
	return ((buffer.precision > i) ? buffer.precision : i);
}

int main(void)
{
	int i;
	t_arg test;
	test.reverse = 1;
	test.precision = 15;
	test.minimal_size = 21;
	test.zero = 0;
	i = ft_printf_integer(2147483647, test);
	printf("|\n\033[0;31m%d", i);
	return(0);
}