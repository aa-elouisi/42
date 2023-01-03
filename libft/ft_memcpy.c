/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-ouis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 13:22:28 by ael-ouis          #+#    #+#             */
/*   Updated: 2020/07/27 13:33:30 by ael-ouis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*cpy_dest;
	const char	*cpy_src;

	if (!dest && !src)
		return (NULL);
	cpy_dest = dest;
	cpy_src = src;
	while (n--)
		*cpy_dest++ = *cpy_src++;
	return (dest);
}
