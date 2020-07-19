#include "../../ft_printf/printf.h"

static void		pf_putnbr(unsigned int nb, t_print *args)
{
	if (nb / 10 > 0)
		pf_putnbr(nb / 10, args);
	ft_putchar_fd((nb % 10 + 48), 1);
}

static int	nbrlen(unsigned int nb)
{
	int				i;

	i = 0;
	while (nb > 0)
	{
		i++;
		nb = nb / 10;
	}
	return (i);
}

void		print_u_norme(unsigned int nbr, t_print *args)
{
	ft_putnchar_fd(' ', WIDE - SIZE, 1);
	if (PLUS == 1 || SPACE == 1)
		write(1, (PLUS == 1 ? "+" : " "), 1);
	ft_putnchar_fd('0', PRECIS - nbrlen(nbr), 1);
	pf_putnbr(nbr, args);
}

int			print_u(unsigned int nbr, t_print *args)
{
	if (PRECIS == 0 && nbr == 0)
		return (0);
	SIZE = nbrlen(nbr) < PRECIS ? PRECIS : nbrlen(nbr);
	SIZE += (PLUS == 1 || SPACE == 1) ? 1 : 0;
	if (MIN_KEY == 1)
	{
		if (PLUS == 1 || SPACE == 1)
			write(1, (PLUS == 1 ? "+" : " "), 1);
		ft_putnchar_fd('0', PRECIS - nbrlen(nbr), 1);
		pf_putnbr(nbr, args);
		ft_putnchar_fd(' ', WIDE - SIZE, 1);
	}	
	else
	{
		if (ZERO_KEY == 0 || PRECIS < 0)
		{
			if (PLUS == 1 || SPACE == 1)
				write(1, (PLUS == 1 ? "+" : " "), 1);
			ft_putnchar_fd('0', WIDE - SIZE, 1);
			pf_putnbr(nbr, args);
			return (WIDE > SIZE ? WIDE : SIZE);
		}
		print_u_norme(nbr, args);
	}
	return (WIDE > SIZE ? WIDE : SIZE);
}
