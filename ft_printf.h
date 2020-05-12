/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napoleon <napoleon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 03:42:34 by napoleon          #+#    #+#             */
/*   Updated: 2020/05/12 04:56:15 by napoleon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include <stdarg.h>


typedef	struct	progression
{
	char	arg_type;
	char	reverse;
	char	zero;
	int		arg_size;
	int		minimal_size;
	int		precision;
}				t_arg;

#define ARG_TYPE buffer->arg_type
#define REVERSE	buffer->reverse
#define ZERO_KEY buffer->zero
#define ARG_SIZE buffer->arg_size
#define WIDTH buffer->minimal_size
#define PRECISION buffer->precision

int		ft_printf(const char *str, ...);
int		ft_print_arg(char **str, t_arg *buffer, va_list *args);
void	ft_get_argparam(char **str, t_arg *buffer, va_list *args);
int		ft_printf_char(char c, t_arg buffer);
int		ft_printf_string(char *str, t_arg buffer);
int		ft_printf_integer(int num, t_arg buffer);
void	ft_print_nb(int num, t_arg buffer);


int			ft_get_num_size(int num, int precision);
void		ft_putnbrf(int n, int fd);
void		ft_putcharn(char c, int n);

#endif