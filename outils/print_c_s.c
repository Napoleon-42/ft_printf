#include "../../ft_printf/printf.h"

int		print_c(char c, t_print *args)
{
	if (WIDE > 1)
	{
		if (MIN_KEY != 1)
		{
			ft_putnchar_fd(' ', WIDE - 1, 1);
			ft_putchar_fd(c, 1);
		}
		else
		{
			ft_putchar_fd(c, 1);
			ft_putnchar_fd(' ', WIDE - 1, 1);
		}
	}
	else 
		ft_putchar_fd(c, 1);
	return ((WIDE) ? WIDE : 1);
}

int		print_s(char *str, t_print *args)
{
	int lenght;

	lenght = (PRECIS >= 0 ? PRECIS : ft_strlen(str));
	if (WIDE > (PRECIS > ft_strlen(str) ? ft_strlen(str) : lenght))
	{
		if (MIN_KEY != 1)
		{
			ft_putnchar_fd(' ', WIDE - (PRECIS > ft_strlen(str) ? ft_strlen(str) : lenght), 1);
			ft_putnstr_fd(str, lenght, 1);
		}
		else
		{
			ft_putnstr_fd(str, PRECIS,1);
			ft_putnchar_fd(' ', WIDE - (PRECIS > ft_strlen(str) ? ft_strlen(str) : lenght), 1);
		}
	}
	else
		ft_putnstr_fd(str, PRECIS, 1);
	return ((WIDE > lenght) ? WIDE : lenght);
}