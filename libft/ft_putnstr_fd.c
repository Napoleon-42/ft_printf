#include "libft.h"

void	ft_putnstr_fd(char *str, int n, int fd)
{
	int i;

	if (n < 0)
	{
		ft_putstr_fd(str, fd);
		return ;
	}
	i = 0;
	while (i < n)
	{
		ft_putchar_fd(str[i], fd);
		i++;
	}
	
}