/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-ouis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 13:21:11 by ael-ouis          #+#    #+#             */
/*   Updated: 2020/07/27 13:21:59 by ael-ouis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned const char *str1;
	unsigned const char *str2;

	str1 = s1;
	str2 = s2;
	while (n-- > 0)
		if (*str1++ != *str2++)
			return (*(str1 - 1) - *(str2 - 1));
	return (0);
}
