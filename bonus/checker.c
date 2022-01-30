/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-guna <mal-guna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 10:55:39 by mal-guna          #+#    #+#             */
/*   Updated: 2021/11/12 16:18:41 by mal-guna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_check_input(t_data *data, char **line, int *error)
{
	if (ft_strcmp(*line, "sa"))
		sa(data);
	else if (ft_strcmp(*line, "sb"))
		sb(data);
	else if (ft_strcmp(*line, "ss"))
		ss(data);
	else if (ft_strcmp(*line, "pa"))
		pa(data);
	else if (ft_strcmp(*line, "pb"))
		pb(data);
	else if (ft_strcmp(*line, "ra"))
		ra(data);
	else if (ft_strcmp(*line, "rb"))
		rb(data);
	else if (ft_strcmp(*line, "rr"))
		rr(data);
	else if (ft_strcmp(*line, "rra"))
		rra(data);
	else if (ft_strcmp(*line, "rrb"))
		rrb(data);
	else if (ft_strcmp(*line, "rrr"))
		rrr(data);
	else
		*error = 1;
}

void	ft_get_lines(t_data *data, char **argv, int j)
{
	char	*line;
	int		n;
	int		error;

	n = 1;
	error = 0;
	while (n == 1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		ft_check_input(data, &line, &error);
		free(line);
		line = NULL;
	}
	if (error)
		print_and_exit_checker(data, argv, j);
	if (ft_is_sorted(data) && data->topb == -1)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

void	set_struct_checker(t_data *data, int argc)
{
	data->a = malloc(sizeof(int) * (argc - 1));
	data->b = malloc(sizeof(int) * (argc - 1));
	data->topa = argc - 2;
	data->topb = -1;
}

void	ft_free_checker(t_data *data, char **argv, int j)
{
	free(data->a);
	data->a = NULL;
	free(data->b);
	data->b = NULL;
	if (j == 0)
		free_arg(argv);
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		i;
	int		j;

	i = 0;
	j = 1;
	if (argc == 1)
		exit(EXIT_SUCCESS);
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		argc = count(argv, &j);
	}
	set_struct_checker(&data, argc + 1 - j);
	while (argc != j)
	{
		data.a[i++] = ft_atoi(&data, argv[argc - 1], argv, j);
		argc--;
	}
	if (is_duplicate(data.a, data.topa))
		print_and_exit_checker(&data, argv, j);
	ft_get_lines(&data, argv, j);
	ft_free_checker(&data, argv, j);
	return (0);
}
