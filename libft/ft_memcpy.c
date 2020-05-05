/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnelson <lnelson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 20:44:46 by napoleon          #+#    #+#             */
/*   Updated: 2019/11/26 13:38:00 by lnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char *tmp;
	char *tmpp;

	tmp = (char *)dest;
	tmpp = (char *)src;
	if (!n || dest == src)
		return (dest);
	while (n--)
		*tmp++ = *tmpp++;
	return (dest);
}
