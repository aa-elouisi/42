#include "ft_printf.h"

size_t		ft_strlen(const char *str)
{
	size_t		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static int		ft_nbrlen(int n)
{
	int		len;

	len = 0;
	if (n < 0)
		len = 1;
	while (n)
	{
		n /= 10;
		len++;
	}
	if (len)
		return (len);
	return (1);
}

char			*ft_itoa(int n)
{
	char		*s;
	int		len;
	unsigned int	nb;

	len = ft_nbrlen(n);
	nb = n;
	if (!(s = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	*(s + len) = '\0';
	if (n < 0)
	      nb = -n;
	while (len--)
	{
		*(s + len) = nb % 10 + '0';
		nb /= 10;
	}
	if (n < 0)
		*s = '-';
	return (s);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_pfputstr(char *s)
{
	int	i;

	i = 0;
	while (*s)
	{
		write(1, s++, 1);
		i++;
	}
	return (i);
}

int	ft_pfputnbr(int n)
{
	long	i;
	int	j;
	
	i = n;
	j++;
	if (i < 0)
	{
		ft_putchar('-');
		i *= -1;
	}
	if (i > 9)
	{
		ft_pfputnbr(i / 10);
		ft_pfputnbr(i % 10);
	}
	else
	{
		ft_putchar(i + '0');
	}
	return (j);
}
