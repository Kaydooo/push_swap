/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-guna <m3t9mm@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 10:08:49 by mal-guna          #+#    #+#             */
/*   Updated: 2021/11/09 16:09:52 by mal-guna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rr(t_data *data)
{
	int	temp;
	int	i;

	if (data->topa > 0)
	{
		temp = data->a[data->topa];
		i = data->topa;
		while (i > 0)
		{
			data->a[i] = data->a[i - 1];
			i--;
		}
		data->a[0] = temp;
	}
	if (data->topb > 0)
	{
		temp = data->b[data->topb];
		i = data->topb;
		while (i > 0)
		{
			data->b[i] = data->b[i - 1];
			i--;
		}
		data->b[0] = temp;
	}
	write(1, "rr\n", 3);
}

void	pa(t_data *data)
{
	if (data->topb >= 0)
	{
		data->a[data->topa + 1] = data->b[data->topb];
		data->topa += 1;
		data->topb -= 1;
	}
	write(1, "pa\n", 3);
}

void	pb(t_data *data)
{
	if (data->topa >= 0)
	{
		data->b[data->topb + 1] = data->a[data->topa];
		data->topb += 1;
		data->topa -= 1;
	}	
	write(1, "pb\n", 3);
}

void	sa(t_data *data)
{
	int	temp;

	if (data->topa > 0)
	{
		temp = data->a[data->topa];
		data->a[data->topa] = data->a[data->topa - 1];
		data->a[data->topa - 1] = temp;
	}
	write(1, "sa\n", 3);
}

void	sb(t_data *data)
{
	int	temp;

	if (data->topb > 0)
	{
		temp = data->b[data->topb];
		data->b[data->topb] = data->b[data->topb - 1];
		data->b[data->topb - 1] = temp;
	}
	write(1, "sb\n", 3);
}
