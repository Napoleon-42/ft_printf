#include "../../ft_printf/printf.h"

void	init_print(t_print *args)
{
	PRECIS = -1;
	WIDE = -1;
	ZERO_KEY = -1;
	MIN_KEY = -1;
	SIZE = 0;
	ARG_TYPE = 0;
	HASH = -1;
	PLUS = -1;
	SPACE = -1;
}

void	get_param_utils(const char **str, va_list *ap, t_print *args)
{
	if (**str == '.')
	{
		//write(1, "|prec change|", 13);
		(*str)++;
		if (**str == '*')
			PRECIS = va_arg(*ap, int);
		else
		{
			PRECIS = ft_atoi(*str);
			while (ft_isdigit(**str) == 42)
				(*str)++;
			(*str)--;
		}
	}
	else if (ft_isdigit(**str) == 42)
	{
		//write(1, "|wide change utils|", 19);
		WIDE = ft_atoi(*str);
		while (ft_isdigit(**str) == 42)
			(*str)++;
		(*str)--;
	}
}

void	get_param(const char **str, va_list *ap, t_print *args)
{
	(*str)++;
	while(ft_strchr("cspdiuxnefg%", **str) == NULL)
	{
		if (**str == ' ')
			SPACE = 1;
		if (**str == '+')
			PLUS = 1;
		if (**str == '#')
			HASH = 1;
		if (**str == '-')
			MIN_KEY = 1;
		if (**str == '0')
			ZERO_KEY = 1;
		if (**str == '*')
		{
		//	write(1, "|wide change|", 13);
			WIDE = va_arg(*ap, int);
		}
		if (**str == '.' || ft_isalnum(**str))
			get_param_utils(str, ap, args);
		(*str)++;
	}
	ARG_TYPE = **str;
}