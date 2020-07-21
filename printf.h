#ifndef PRINTF_H
# define PRINTF_H

# include "./libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# define LOW_HEXA "0123456789abcdef"
# define UPP_HEXA "0123456789ABCDEF"
# define ZERO_KEY args->zero_key
# define MIN_KEY args->minus_key
# define SIZE args->size
# define WIDE args->wide
# define ARG_TYPE args->arg
# define PRECIS args->precision
# define SPACE args->space
# define PLUS args->plus
# define HASH args->hash

typedef struct	s_print
{
	char	zero_key;
	char	minus_key;
	int		size;
	int		wide;
	int		precision;
	char	arg;
	char	space;
	char	plus;
	char	hash;
}				t_print;


void	init_print(t_print *args);
void	get_param_utils(const char **str, va_list *ap, t_print *args);
void	get_param(const char **str, va_list *ap, t_print *args);

int		print_c(char c, t_print *args);
int		print_s(char *str, t_print *args);
int		print_p(__uintmax_t nbr, t_print *args);
int		print_i_d(int nbr, t_print *args);
int		print_u(unsigned int nbr, t_print *args);
int		print_x(unsigned int nbr, t_print *args);

#endif