/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-guna <m3t9mm@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 11:10:39 by mal-guna          #+#    #+#             */
/*   Updated: 2021/11/09 17:58:34 by mal-guna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	*ft_strdup(const char *s)
{
	char	*new;

	new = malloc(sizeof(*new) * (ft_strlen(s) + 1));
	if (!new)
		return (NULL);
	ft_strlcpy(new, s, ft_strlen(s) + 1);
	new[ft_strlen(s)] = '\0';
	return (new);
}
