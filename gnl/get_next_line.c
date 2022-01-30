/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-guna <m3t9mm@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 07:27:18 by mal-guna          #+#    #+#             */
/*   Updated: 2021/11/09 16:45:59 by mal-guna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_free(char **s)
{
	free(*s);
	*s = NULL;
}

char	*ft_line(char	**s, int i)
{
	char	*temp;
	char	*ret;

	if (ft_strchr(*s, '\n'))
	{
		temp = *s;
		ret = ft_substr(*s, 0, i);
		*s = ft_strdup(temp + i);
		free(temp);
		temp = NULL;
		return (ret);
	}
	else if (*s)
	{
		temp = ft_strdup(*s);
		ft_free(s);
		return (temp);
	}
	return (NULL);
}

int	nl_index(char	*str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}

int	ft_reader(char **save, int fd, int n)
{
	char	*temp;
	char	buff[BUFFER_SIZE + 1];

	while (n && !ft_strchr(*save, '\n'))
	{
		n = read(fd, buff, BUFFER_SIZE);
		if (n <= 0)
			break ;
		buff[n] = '\0';
		temp = *save;
		*save = ft_strjoin(temp, buff);
		free(temp);
	}
	return (n);
}

char	*get_next_line(int fd)
{
	static char	*save[8192];
	int			index;
	int			b;

	b = 1;
	if (fd < 0 || fd > 8192 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!save[fd])
		save[fd] = ft_strdup("");
	b = ft_reader(&save[fd], fd, b);
	if (*save[fd] == '\0' && b <= 0)
	{
		ft_free(&save[fd]);
		return (NULL);
	}
	index = nl_index(save[fd]);
	return (ft_line(&save[fd], index + 1));
}
