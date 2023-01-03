#include "ft_printf.h"
#include <stdio.h>

int	ft_putptr(void *i)
{
	int truc = 0;
	uintptr_t p = (uintptr_t)&i;

	ft_pfputstr("0x7ffe");
	ft_puthexa((unsigned int)p, 16, 0);
	return truc;
}

/*int main()
{
	void *i = ",dpz";
	ft_putptr(i);
}*/
