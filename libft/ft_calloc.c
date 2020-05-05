/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnelson <lnelson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 21:02:14 by napoleon          #+#    #+#             */
/*   Updated: 2019/11/26 13:37:31 by lnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*result;
	size_t	i;

	i = 0;
	if (!(result = malloc(size == 0 || nmemb == 0 ? 1 : size * nmemb)))
		return (NULL);
	while (i <= nmemb * size)
	{
		((char*)result)[i] = 0;
		i++;
	}
	return (result);
}
