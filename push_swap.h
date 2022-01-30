/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-guna <mal-guna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 10:08:33 by mal-guna          #+#    #+#             */
/*   Updated: 2021/11/12 11:41:24 by mal-guna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "./gnl/get_next_line.h"

typedef struct s_data
{
	int	*a;
	int	*b;
	int	*indexarray;
	int	topa;
	int	topb;
	int	bestindex;
	int	bestvalue;
	int	correctadd;
	int	correctvalue;
}	t_data;

int		get_values(t_data *data);
void	push_to_a(t_data *data, int *x);
void	pushback(t_data *data);
void	push(t_data *data, int min, int max);
void	ft_push(t_data *data);
void	rra(t_data *data);
void	rrb(t_data *data);
void	rrr(t_data *data);
void	ra(t_data *data);
void	rb(t_data *data);
void	rr(t_data *data);
void	pa(t_data *data);
void	pb(t_data *data);
void	sa(t_data *data);
void	sb(t_data *data);
void	ss(t_data *data);
int		ft_lowesta(t_data *data);
int		is_digit(char c);
int		ft_atoi(t_data *data, char *str, char **argv, int j);
int		ft_is_sorted(t_data *data);
void	print_and_exit(t_data *data, char **argv, int j);
int		ft_find_correct_index_on_a(t_data *data, int index);
int		ft_moves(t_data *data, int i);
int		ft_checkbestindex(t_data *data);
void	sortarry(t_data *data);
int		is_duplicate(int *array, int maxindex);
void	ft_free(t_data *data);
void	set_struct(t_data *data, int argc);
void	ft_sort_three(t_data *data);
void	ft_sort_small(t_data *data);
void	ft_sort_large(t_data *data);
void	print_and_exit_checker(t_data *data, char **argv, int j);
int		ft_strcmp(char *s1, char *s2);
void	ft_free_checker(t_data *data, char **argv, int j);
void	ft_get_lines(t_data *data, char **argv, int j);
char	**ft_split(char const *s, char c);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_strdup(const char *s);
int		count(char **argv, int *j);
void	ft_check(t_data *data, char **argv, int j);
void	free_arg(char **argv);
void	ft_check_input(t_data *data, char **line, int *error);

#endif
