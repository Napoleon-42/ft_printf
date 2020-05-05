/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnelson <lnelson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 22:11:40 by napoleon          #+#    #+#             */
/*   Updated: 2019/11/28 18:41:40 by lnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memchr(const void *mem, int c, size_t n)
{
	unsigned char	*tmp;
	unsigned char	c1;

	tmp = (unsigned char*)mem;
	c1 = (unsigned char)c;
	while (n > 0)
	{
		if (*tmp == c1)
			return (tmp);
		tmp++;
		n--;
	}
	return (NULL);
}
