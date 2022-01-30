/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-guna <mal-guna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 18:38:47 by mal-guna          #+#    #+#             */
/*   Updated: 2021/11/10 14:25:18 by mal-guna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

void	ft_check(t_data *data, char **argv, int j)
{
	if (is_duplicate(data->a, data->topa))
		print_and_exit(data, argv, j);
	sortarry(data);
	if (!ft_is_sorted(data))
		ft_push(data);
	ft_free(data);
}

void	free_arg(char **argv)
{
	int	j;

	j = 0;
	while (argv[j])
		free(argv[j++]);
	free(argv);
}
