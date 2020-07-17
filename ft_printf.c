#include "printf.h"
#include <stdio.h>

void	test_print_arg(t_print *args)
{
	printf("\n Arg is: \n PRECIS = %d\t WIDE = %d\n ZERO_KEY = %d\t MIN_KEY = %d \n ARG_TYPE = %c\n", PRECIS, WIDE, (int)ZERO_KEY, (int)MIN_KEY, ARG_TYPE);
}

void	printf_param(const char **str, va_list *ap, int *res, t_print *args)
{
	init_print(args);
	get_param(str, ap, args);
	//test_print_arg(args);
	if (ARG_TYPE == 'c')
		*res += print_c((char)(va_arg(*ap, int)), args);
	if (ARG_TYPE == 's')
		*res += print_s((char *)(va_arg(*ap, int*)), args);
	if (ARG_TYPE == 'p')
		*res += print_p((__uintmax_t)(va_arg(*ap, __uintmax_t)), args);
	/*if (ARG_TYPE == 'd')

	if (ARG_TYPE == 'i')

	if (ARG_TYPE == 'u')
	*/
	if (ARG_TYPE == '%')
		*res += write(1, "%", 1);
	/*if (ARG_TYPE == 'x' || ARG_TYPE == 'X')
*/
	if (ARG_TYPE == 'n')
		*((int *)va_arg(*ap, int*)) = *res;
/*	if (ARG_TYPE == 'f')

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
	/* ------------CHAR AND STRING TEST----------------
    ft_printf("\nc = |%c|", 'A');
    ft_printf("\nc = |%3c|", 'A');
    ft_printf("\nc = |%-3c|", 'A');
    ft_printf("\nc = |%-*c|", 3,'A');


	ft_printf("\ns = |%s|", "salut");
	ft_printf("\ns = |%8.4s|", "salut");
	ft_printf("\ns = |%-8s|", "salut");
	ft_printf("\ns = |%-*.4s|", 8,"salut");*/

	/* ------------POINTER TESTS----------------
	int a;

	printf("\n\n p = -|%p|\n", &a);
	ft_printf("\n p = +|%p|", &a);

    printf("\n\n p = -|%20p|\n", &a);
    ft_printf(" p = +|%20p|", &a);

    printf("\n\n p = -|%20p|\n", &a);
    ft_printf(" p = +|%020p|", &a);

    printf("\n\n p = +|%-20p|\n", &a);
    ft_printf(" p = -|%-20p|", &a); */

	/* ------------ % TEST ----------------
	ft_printf("%% = |% 0-33.*%|", 34);*/

	/* ------------THE NNN	 TESTS----------------
	int b;

	b = -35;
	printf("before = %i\n", b);
	ft_printf("0123456789%n\n", &b);
	printf(" after = %i", b);*/

	return 0;
}