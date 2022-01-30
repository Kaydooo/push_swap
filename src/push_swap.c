/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-guna <mal-guna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 10:08:37 by mal-guna          #+#    #+#             */
/*   Updated: 2021/11/12 09:30:03 by mal-guna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_free(t_data *data)
{
	free(data->a);
	data->a = NULL;
	free(data->b);
	data->b = NULL;
	free(data->indexarray);
	data->indexarray = NULL;
}

void	set_struct(t_data *data, int argc)
{
	data->a = malloc(sizeof(int) * (argc - 1));
	data->b = malloc(sizeof(int) * (argc - 1));
	data->indexarray = malloc(sizeof(int) * (argc - 1));
	data->topa = argc - 2;
	data->topb = -1;
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
	set_struct(&data, argc + 1 - j);
	while (argc != j)
	{
		data.a[i] = ft_atoi(&data, argv[argc - 1], argv, j);
		data.indexarray[i++] = ft_atoi(&data, argv[argc - 1], argv, j);
		argc--;
	}
	ft_check(&data, argv, j);
	if (j == 0)
		free_arg(argv);
	return (0);
}
