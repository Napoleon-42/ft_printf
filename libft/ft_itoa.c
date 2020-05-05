/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnelson <lnelson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 14:02:56 by napoleon          #+#    #+#             */
/*   Updated: 2019/11/28 17:54:35 by lnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*itoa_brain(long int num, char *str, int str_size)
{
	int					i;
	unsigned long int	nb;

	i = str_size - 1;
	str[str_size] = 0;
	if (num < 0)
	{
		nb = -num;
		str[0] = '-';
		while (i > 0)
		{
			str[i] = (nb % 10) + 48;
			i--;
			nb = nb / 10;
		}
	}
	else
		while (i >= 0)
		{
			str[i] = (num % 10) + 48;
			i--;
			num = num / 10;
		}
	return (str);
}

char	*ft_itoa(int n)
{
	char		*res;
	int			size;
	long int	temp;

	temp = n;
	size = 1;
	if (n < 0)
	{
		size++;
		temp = -temp;
	}
	while (temp >= 10)
	{
		size++;
		temp = temp / 10;
	}
	if (!(res = malloc((1 + size) * sizeof(char))))
		return (0);
	return (res = itoa_brain((long int)n, res, size));
}
