/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-guna <mal-guna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 07:27:33 by mal-guna          #+#    #+#             */
/*   Updated: 2021/11/12 09:55:29 by mal-guna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	while (*str != '\0')
	{
		if (*str == (char)c)
			return (str);
		str++;
	}
	if (c == '\0')
		return (str);
	return (NULL);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(const char *src)
{
	char	*dest;
	size_t	z;
	size_t	i;

	z = ft_strlen(src);
	dest = malloc(sizeof(char) * (z + 1));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (i != (z + 1))
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

char	*ft_substr(const char	*s, unsigned int start, size_t len)
{
	size_t	j;
	char	*str;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	if (start + len > ft_strlen(s))
		len = ft_strlen(s) - start;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	j = 0;
	while (s[start] && j < len)
	{
		str[j] = s[start];
		j++;
		start++;
	}
	str[j] = 0;
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	size_t	i;
	size_t	b;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	b = 0;
	join = malloc(sizeof(*join) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!join)
		return (NULL);
	while (s1[i])
		join[b++] = s1[i++];
	i = 0;
	while (s2[i])
	{
		join[b] = s2[i];
		i++;
		b++;
	}
	join[b] = '\0';
	return (join);
}
