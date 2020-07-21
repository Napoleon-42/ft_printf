#include "../../ft_printf/printf.h"

static void		pf_putnbr(unsigned int nb, t_print *args)
{
	if (nb / 16 > 0)
		pf_putnbr(nb / 16, args);
	ft_putchar_fd((ARG_TYPE == 'X' ? UPP_HEXA : LOW_HEXA)[nb % 16], 1);
}

static int	nbrlen(unsigned int nb)
{
	int				i;

	i = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		i++;
		nb = nb / 16;
	}
	return (i);
}

void		print_x_norme(unsigned int nbr, t_print *args)
{
	ft_putnchar_fd(' ', WIDE - SIZE, 1);
	if (HASH == 1)
		write(1, ( ARG_TYPE == 'X' ? "0X" : "0x"), 2);
	ft_putnchar_fd('0', PRECIS - nbrlen(nbr), 1);
	pf_putnbr(nbr, args);
}

static int	null_precision_nbr(int with)
{
	ft_putnchar_fd(' ', with, 1);
	return 0;
}

int			print_x(unsigned int nbr, t_print *args)
{
	if (PRECIS == 0 && nbr == 0)
		return (null_precision_nbr(WIDE));
	SIZE = nbrlen(nbr) < PRECIS ? PRECIS : nbrlen(nbr);
	SIZE += (HASH == 1) ? 2 : 0;
	if (MIN_KEY == 1)
	{
		if (HASH == 1)
			write(1, ( ARG_TYPE == 'X' ? "0X" : "0x"), 2);
		ft_putnchar_fd('0', PRECIS - nbrlen(nbr), 1);
		pf_putnbr(nbr, args);
		ft_putnchar_fd(' ', WIDE - SIZE, 1);
	}	
	else
	{
		if (ZERO_KEY == 1 && PRECIS < 0)
		{
			if (HASH == 1)
				write(1, ( ARG_TYPE == 'X' ? "0X" : "0x"), 2);
			ft_putnchar_fd('0', WIDE - SIZE, 1);
			pf_putnbr(nbr, args);
			return (WIDE > SIZE ? WIDE : SIZE);
		}
		print_x_norme(nbr, args);
	}
	return (WIDE > SIZE ? WIDE : SIZE);
}
