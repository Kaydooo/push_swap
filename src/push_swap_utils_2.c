/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-guna <m3t9mm@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 10:08:44 by mal-guna          #+#    #+#             */
/*   Updated: 2021/11/09 16:10:29 by mal-guna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_find_correct_index_on_a(t_data *data, int index)
{
	int	i;

	i = data->topa;
	while (i > 0)
	{
		if (data->b[index] > data->a[i] && data->b[index] < data->a[i - 1])
			return (i - 1);
		i--;
	}
	return (data->topa);
}

int	ft_moves(t_data *data, int i)
{
	int	moves;
	int	sortedindex;

	moves = 0;
	if (i < data->topb / 2)
		moves += i;
	else
		moves += data->topb - i;
	sortedindex = ft_find_correct_index_on_a(data, i);
	if (sortedindex < data->topa / 2)
		moves += sortedindex;
	else
		moves += data->topa - sortedindex;
	return (moves);
}

int	ft_checkbestindex(t_data *data)
{
	int	moves;
	int	bestmoves;
	int	bestindex;
	int	i;

	i = data->topb;
	bestmoves = ft_moves(data, i);
	bestindex = data->topb;
	while (i >= 0)
	{
		moves = ft_moves(data, i);
		if (moves < bestmoves)
		{
			bestmoves = moves;
			bestindex = i;
		}
		i--;
	}
	return (bestindex);
}

void	sortarry(t_data *data)
{
	int	n;
	int	i;
	int	j;
	int	tmp;

	n = data->topa + 1;
	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			if (data->indexarray[j] > data->indexarray[i])
			{
				tmp = data->indexarray[i];
				data->indexarray[i] = data->indexarray[j];
				data->indexarray[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

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
