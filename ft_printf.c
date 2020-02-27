/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnelson <lnelson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 04:48:09 by lnelson           #+#    #+#             */
/*   Updated: 2020/02/27 08:07:41 by lnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef	struct	progression
{
	char	pers_key;
	char	null_key;
	char	index;
	char	precision;
	
}				buffer;

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
	int	(*flag) (char *pointer, buffer *buff) = {0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, %, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, &ft_big_hex,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, &ft_char, &ft_integer, 0, 0, 0, 0, i, 0,
	0, 0, 0, 0, 0, 0, p, 0, 0, &ft_string, 0, u, 0, 0, &ft_small_hex, 0, 0, 0,
	};
}