#include "printf.h"



void	printf_param(va_list *ap, int *res, t_print *args)
{
	init_print(args);
	get_param(str, ap, args);
	if (ARG_TYPE == 'c')
		*res = print_c((char)(va_arg(*ap, int)), args);
	if (ARG_TYPE == 's')
		*res = print_s((char *)(va_arg(*ap, int*)), args);
	/*if (ARG_TYPE == 'p')

	if (ARG_TYPE == 'd')

	if (ARG_TYPE == 'i')

	if (ARG_TYPE == 'u')
	
	if (ARG_TYPE == '%')

	if (ARG_TYPE == 'x' || ARG_TYPE == 'X')

	if (ARG_TYPE == 'n')

	if (ARG_TYPE == 'f')

	if (ARG_TYPE == 'g')

	if (ARG_TYPE == 'e')
	*/	
}

int		ft_printf(const char *str, ...)
{
	int		res;
	va_list	ap;
	t_print args;

	va_start(ap, str);
	res = 0;
	while (*str != 0)
	{
		if (*str == '%')
			printf_param(&str, &ap, &res, &args);
		else
		{
			ft_putchar_fd(*str, 1);
			res++;
		}
		str++;
	}
	va_end(ap);
	return (res);
}

int main()
{
    ft_printf("\nc = |%c|", 'A');
    ft_printf("\nc = |%3c|", 'A');
    ft_printf("\nc = |%-3c|", 'A');
    ft_printf("\nc = |%-*c|", 3,'A');


/*	ft_printf("\ns = |%s|", "salut");
	ft_printf("\ns = |%8s|", "salut");
	ft_printf("\ns = |%-8s|", "salut");
	ft_printf("\ns = |%-*s|", 8,"salut");*/

	return 0;
}