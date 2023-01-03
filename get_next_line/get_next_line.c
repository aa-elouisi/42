/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-ouis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 14:49:54 by ael-ouis          #+#    #+#             */
/*   Updated: 2021/03/27 13:38:27 by ael-ouis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void		ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;

	ptr = s;
	while (n--)
		*(ptr++) = '\0';
}

static int	linelen(const char *s)
{
	int		i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	return (i);
}

static int	readline(int fd, char **rest)
{
	char		buf[BUFFER_SIZE + 1];
	char		*tmp;
	int			size;

	size = 1;
	while (!(ft_strchr(*rest, '\n')) && size)
	{
		ft_bzero(buf, BUFFER_SIZE + 1);
		if ((size = read(fd, buf, BUFFER_SIZE)) == -1)
			break ;
		if (!*rest)
			tmp = ft_strdup(buf);
		else
			tmp = ft_strjoin(*rest, buf);
		free(*rest);
		*rest = tmp;
	}
	return (size);
}

int			get_next_line(int fd, char **line)
{
	static char	*rest;
	char		*tmp;
	int			size;

	if (fd < 0 || !(line) || BUFFER_SIZE < 1 ||
			(size = readline(fd, &rest)) == -1)
		return (-1);
	*line = ft_substr(rest, 0, linelen(rest));
	if ((tmp = ft_strchr(rest, '\n')))
		tmp = ft_strdup(tmp + 1);
	free(rest);
	rest = tmp;
	if (size)
		return (1);
	return (0);
}
