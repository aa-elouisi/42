#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
size_t		ft_strlen(const char *str);
static int	ft_nbrlen(int n);
char		*ft_itoa(int n);
void		ft_putchar(char c);
int		ft_pfputstr(char *s);
int		ft_pfputnbr(int n);
char		*ft_puthexa(uintptr_t nb, int base, int maj);
int		ft_putptr(void *i);

#endif
