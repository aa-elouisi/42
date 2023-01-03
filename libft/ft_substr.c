/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-ouis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 13:57:54 by ael-ouis          #+#    #+#             */
/*   Updated: 2020/07/27 13:58:37 by ael-ouis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	int		i;

	i = 0;
	if (!(s))
		return (NULL);
	if (start > ft_strlen(s) || !(len))
		return (ft_strdup(""));
	if (!(str = malloc((len + 1) * sizeof(char))))
		return (NULL);
	while (len-- && s[start])
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}
