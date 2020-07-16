/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnchar_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napoleon <napoleon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 17:05:14 by napoleon          #+#    #+#             */
/*   Updated: 2020/07/16 16:53:39 by napoleon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putnchar_fd(char c, int n, int fd)
{
	int i;

	i = 0;
	while (i < n)
	{
		write(fd, &c, 1);
		i++;
	}
}
