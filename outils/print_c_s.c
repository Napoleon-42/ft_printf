#include "../../ft_printf/printf.h"

int		print_c(char c, t_print *args)
{
	if (WIDE)
	{
		if (MIN_KEY == 1)
		{
			ft_putnchar_fd(' ', WIDE-1, 1);
			ft_putchar_fd(c, 1);
		}
		else
		{
			ft_putchar_fd(c, 1);
			ft_putnchar_fd(' ', WIDE-1, 1);
		}
	}
	else 
		ft_putchar_fd(c, 1);
	return ((WIDE) ? WIDE : 1);
}

int		print_s(char *str, t_print *args)
{
	int lenght;

	lenght = ft_strlen(str);
	if (WIDE > lenght)
	{
		if (MIN_KEY == 1)
		{
			ft_putnchar_fd(' ', WIDE - lenght, 1);
			ft_putstr_fd(str, 1);
		}
		else
		{
			ft_putstr_fd(str, 1);
			ft_putnchar_fd(' ', WIDE - lenght, 1);
		}
	}
	else
		ft_putstr_fd(str, 1);
	return ((WIDE > lenght) ? WIDE : lenght);
}