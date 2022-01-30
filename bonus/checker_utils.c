/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-guna <mal-guna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 10:08:44 by mal-guna          #+#    #+#             */
/*   Updated: 2021/11/12 16:18:13 by mal-guna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\n' && s2[i] != '\0')
		i++;
	if (s1[i] == '\n' && s2[i] == '\0')
		return (1);
	else
		return (0);
}

void	print_and_exit_checker(t_data *data, char **argv, int j)
{
	ft_free_checker(data, argv, j);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
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
		print_and_exit_checker(data, argv, j);
	while (is_digit(str[i]))
	{
		res = (res * 10) + (str[i] - 48);
		i++;
	}
	if (!is_digit(str[i]) && str[i])
		print_and_exit_checker(data, argv, j);
	if ((res > 2147483647 && sign == 1) || ((res > 2147483648) && (sign == -1)))
		print_and_exit_checker(data, argv, j);
	return (res * sign);
}
