/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-ouis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 02:04:36 by ael-ouis          #+#    #+#             */
/*   Updated: 2020/07/29 21:10:16 by ael-ouis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		nb;
	int		neg;

	nb = 0;
	while (ft_isspace(*str))
		str++;
	neg = (*str == '-') ? 1 : 0;
	if (*str == '+' || *str == '-')
		str++;
	while (ft_isdigit(*str))
		nb = nb * 10 + (*(str++) - '0');
	return ((neg) ? -nb : nb);
}
