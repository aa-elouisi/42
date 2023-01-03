#include "ft_printf.h"
#include <stdio.h>

int	ft_printf(const char *format, ...)
{
	int i = 0;
	va_list		ap;

	va_start(ap, format);
	while(*format)
	{
		while (*format != '%' && (*format))
		{
			ft_putchar(*format);
			format++;
			i++;
		}
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				ft_putchar(va_arg(ap, int));
				i++;
			}
			if (*format == 's')
				i += ft_pfputstr(va_arg(ap, char *));
			if (*format == 'p')
				i += ft_putptr(va_arg(ap, char *));
			if (*format == 'd' || *format == 'i')
				i += ft_pfputnbr(va_arg(ap, int));
			//if (*format == 'u')
			//	unsigned int -> décimal non signé
			if (*format == 'x')
				i += ft_strlen(ft_puthexa(va_arg(ap, int), 16, 0));
			if (*format == 'X')
				i += ft_strlen(ft_puthexa(va_arg(ap, int), 16, 1));
			if (*format == '%')
			{
				ft_putchar('%');
				i++;
			}
		}
		format++;
	}
	va_end(ap);
	printf("%d\n", i);
	return (i);
}

int main()
{
	char str[] = "achraf";
	int nbr = 112;
	char c = ':';
	void *i = ",dpz";
	
	ft_printf("%p", i);
	//ft_printf("%d", nbr);
	//ft_printf("%i", nbr);
	//ft_printf("%x", nbr);
	//ft_printf("%X", nbr);
	//ft_printf("%s", str);
	//ft_printf("%c", c);
	//ft_printf("%%");
}

//regler le probleme de i du a la recursive de putnbr pour les cas %d et %i
//attaquer %p
//attaquer %u
//normer tester corriger
