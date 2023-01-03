/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-ouis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 13:18:15 by ael-ouis          #+#    #+#             */
/*   Updated: 2020/07/29 21:15:41 by ael-ouis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned int	i;

	i = 0;
	while (n--)
	{
		((char *)dest)[i] = ((const char *)src)[i];
		if (((char *)src)[i] == (char)c)
			return ((void *)&dest[i + 1]);
		i++;
	}
	return (NULL);
}
