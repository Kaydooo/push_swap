/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-guna <mal-guna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 10:08:41 by mal-guna          #+#    #+#             */
/*   Updated: 2022/04/25 11:47:08 by mal-guna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_lowesta(t_data *data)
{
	int	i;
	int	lowest;
	int	lowestindex;

	i = 0;
	lowestindex = i;
	lowest = data->a[i];
	while (i <= data->topa)
	{
		if (data->a[i] < lowest)
		{
			lowest = data->a[i];
			lowestindex = i;
		}
		i++;
	}
	return (lowestindex);
}

int	is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(t_data *data, char *str, char **argv, int j)
{
	int		i;
	long	res;
	int		sign;

	sign = 1;
	res = 0;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		sign = -1;
		i++;
	}
	if (!is_digit(str[i]))
		print_and_exit(data, argv, j);
	while (is_digit(str[i]))
	{
		res = (res * 10) + (str[i] - 48);
		i++;
	}
	if ((!is_digit(str[i]) && str[i]) || i > 12)
		print_and_exit(data, argv, j);
	if ((res > 2147483647 && sign == 1) || ((res > 2147483648) && (sign == -1)))
		print_and_exit(data, argv, j);
	return (res * sign);
}

int	ft_is_sorted(t_data *data)
{
	int	i;

	i = data->topa;
	while (i != 0)
	{
		if (data->a[i] < data->a[i - 1])
			i--;
		else
			return (0);
	}
	return (1);
}

void	print_and_exit(t_data *data, char **argv, int j)
{
	ft_free(data);
	if (j == 0)
		free_arg(argv);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}
