#include "../../ft_printf/printf.h"

void	pf_putnbr(int nbr, t_print *args)
{
	unsigned int	nb;

	if (nbr < 0)
		nb = -nbr;
	else
		nb = nbr;
	if (nb / 10 > 0)
		pf_putnbr(nb / 10, args);
	ft_putchar_fd((nb % 10 + 48), 1);
}

int		nbrlen(int nbr)
{
	int				i;
	unsigned int	nb;

	i = 0;
	if (nbr < 0)
		nb = -nbr;
	else
		nb = nbr;
	while (nb > 0)
	{
		i++;
		nb = nb / 10;
	}
	return (i);
}

void	print_i_d_norme(int nbr, t_print *args)
{
	ft_putnchar_fd(' ', WIDE - SIZE, 1);
	if (PLUS == 1 || SPACE == 1 || nbr < 0)
		write(1, (nbr < 0 ? "-" : (PLUS == 1 ? "+" : " ")), 1);
	ft_putnchar_fd('0', PRECIS - nbrlen(nbr), 1);
	pf_putnbr(nbr, args);
}

int		print_i_d(int nbr, t_print *args)
{
	if (PRECIS == 0 && nbr == 0)
		return (0);	
	SIZE = nbrlen(nbr) < PRECIS ? PRECIS : nbrlen(nbr);
	SIZE += (PLUS == 1 || SPACE == 1 || nbr < 0) ? 1 : 0;
	if (MIN_KEY == 1)
	{
		if (PLUS == 1 || SPACE == 1 || nbr < 0)
			write(1, (nbr < 0 ? "-" : (PLUS == 1 ? "+" : " ")), 1);
		ft_putnchar_fd('0', PRECIS - nbrlen(nbr), 1);
		pf_putnbr(nbr, args);
		ft_putnchar_fd(' ', WIDE - SIZE, 1);
	}
	else
	{
		if (ZERO_KEY == 0 || PRECIS < 0)
		{
			if (PLUS == 1 || SPACE == 1 || nbr < 0)
				write(1, (nbr < 0 ? "-" : (PLUS == 1 ? "+" : " ")), 1);
			ft_putnchar_fd('0', WIDE - SIZE, 1);
			pf_putnbr(nbr, args);
			return (WIDE > SIZE ? WIDE : SIZE);
		}
		print_i_d_norme(nbr, args);
	}
	return (WIDE > SIZE ? WIDE : SIZE);
}