/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-ouis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 13:30:07 by ael-ouis          #+#    #+#             */
/*   Updated: 2020/07/27 13:41:24 by ael-ouis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_getword(char const *s, char c, int i)
{
	char	*str;
	int		j;

	j = 0;
	while (s[i + j] && s[i + j] != c)
		j++;
	if (!(str = malloc((j + 1) * sizeof(char))))
		return (NULL);
	j = 0;
	while (s[i] && s[i] != c)
	{
		str[j] = s[i];
		j++;
		i++;
	}
	str[j] = '\0';
	return (str);
}

static int		ft_wordnum(char const *s, char c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1])
			j++;
		i++;
	}
	return (j + 1);
}

char			**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**tab;

	i = 0;
	j = 0;
	if (!(s))
		return (NULL);
	if (!(tab = malloc((ft_wordnum(s, c) + 1) * sizeof(char*))))
		return (NULL);
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			tab[j++] = ft_getword(s, c, i);
		while (s[i] && s[i] != c)
			i++;
	}
	tab[j] = NULL;
	return (tab);
}
