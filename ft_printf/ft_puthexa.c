#include "ft_printf.h"

char	*ft_base(int base, int maj)
{
	int	i;
	char	*hex;
	char	*current;
	
	i = 0;
	if (!(hex = malloc(sizeof(char) * 16)))
		return NULL;
	if (!(current = malloc(sizeof(char) * base)))
		return NULL;
	if (maj)
		hex = "0123456789ABCDEF";
	else
		hex = "0123456789abcdef";
	while(base--)
	{
		current[i] = hex[i];
		i++;
	}
	return (current);
}

int	tab_size(uintptr_t nb, int base)
{
	int	i;

	i = 0;
	while (nb)
	{
		nb /= base;
		i++;
	}
	return (i);
}

char	*ft_puthexa(uintptr_t nb, int base, int maj)
{
	int	size;
	int 	neg;
	char	*tab;
	
	if (base < 2 || base > 16)
		return (0);
	if (base == 10 && nb == -2147483648)
		return ("-2147483648");
	neg = 0;
	if (base == 10 && nb < 0)
		neg = 1;
	if (nb < 0)
		nb = -nb;
	if (nb == 0)
		return ("0");
	size = tab_size(nb, base) - 1;
	if (neg)
		size += 1;
	if (!(tab = malloc(sizeof (char) * size)))
			return NULL;
	while (nb)
	{
		tab[size--] = ft_base(base, maj)[nb % base];
		nb /= base;
	}
	if (neg)
		tab[0] = '-';
	tab[tab_size(nb, base) - 1] = '\0';
	ft_pfputstr(tab);
	return (tab);
}
