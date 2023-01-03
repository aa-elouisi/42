/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-ouis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 13:56:34 by ael-ouis          #+#    #+#             */
/*   Updated: 2020/07/27 13:59:00 by ael-ouis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_issep(char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;

	if (!(s1) || !(set))
		return (NULL);
	i = 0;
	j = ft_strlen(s1) - 1;
	while (ft_issep(s1[i], set))
		i++;
	if (!(s1[i]))
		return (ft_strdup(""));
	while (ft_issep(s1[j], set))
		j--;
	return (ft_substr(s1, i, j - i + 1));
}
