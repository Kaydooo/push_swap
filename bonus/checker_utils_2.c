/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-guna <mal-guna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 10:08:44 by mal-guna          #+#    #+#             */
/*   Updated: 2021/11/10 11:35:36 by mal-guna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_duplicate(int *array, int maxindex)
{
	int	i;
	int	j;

	i = 0;
	while (i <= maxindex)
	{
		j = i + 1;
		while (j <= maxindex)
		{
			if (array[j] == array[i])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	count(char **argv, int *j)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		i++;
	}
	*j = 0;
	return (i);
}

void	free_arg(char **argv)
{
	int	j;

	j = 0;
	while (argv[j])
		free(argv[j++]);
	free(argv);
}
