/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 14:17:56 by dim               #+#    #+#             */
/*   Updated: 2021/06/29 15:54:00 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		push_swap_bonus(t_lst *tail_a, t_lst *tail_b, int i)
{
	if (tail_a->size > 1 && (i == 1 || i == 3))
		st_swap(tail_a->tail);
	if (tail_b->size > 1 && (i == 2 || i == 3))
		st_swap(tail_b->tail);
	if (tail_b->size > 0 && i == 4)
		st_push(tail_b, tail_a);
	if (tail_a->size > 0 && i == 5)
		st_push(tail_a, tail_b);
	if (tail_a->size > 1 && (i == 6 || i == 8))
		st_rotate(tail_a);
	if (tail_b->size > 1 && (i == 7 || i == 8))
		st_rotate(tail_b);
	if (tail_a->size > 1 && (i == 9 || i == 11))
		st_rev_rotate(tail_a);
	if (tail_b->size > 1 && (i == 10 || i == 11))
		st_rev_rotate(tail_b);
}

void		checker(t_lst *tail_a, t_lst *tail_b, char **line)
{
	if (ft_strcmp(*line, "sa") == 0)
		push_swap_bonus(tail_a, tail_b, 1);
	else if (ft_strcmp(*line, "sb") == 0)
		push_swap_bonus(tail_a, tail_b, 2);
	else if (ft_strcmp(*line, "ss") == 0)
		push_swap_bonus(tail_a, tail_b, 3);
	else if (ft_strcmp(*line, "pa") == 0)
		push_swap_bonus(tail_a, tail_b, 4);
	else if (ft_strcmp(*line, "pb") == 0)
		push_swap_bonus(tail_a, tail_b, 5);
	else if (ft_strcmp(*line, "ra") == 0)
		push_swap_bonus(tail_a, tail_b, 6);
	else if (ft_strcmp(*line, "rb") == 0)
		push_swap_bonus(tail_a, tail_b, 7);
	else if (ft_strcmp(*line, "rr") == 0)
		push_swap_bonus(tail_a, tail_b, 8);
	else if (ft_strcmp(*line, "rra") == 0)
		push_swap_bonus(tail_a, tail_b, 9);
	else if (ft_strcmp(*line, "rrb") == 0)
		push_swap_bonus(tail_a, tail_b, 10);
	else if (ft_strcmp(*line, "rrr") == 0)
		push_swap_bonus(tail_a, tail_b, 11);
	else
		rt_error((char **)NULL, (t_lst *)NULL);
}

void		show_result(t_lst *tail_a, int i)
{
	if (tail_a->size != i || check_ascending(tail_a, tail_a->size))
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
}

int			main(int argc, char *argv[])
{
	int		gnl;
	int		i;
	char	*line;
	t_lst	*tail_a;
	t_lst	*tail_b;

	if (argc <= 1)
		return (0);
	line = NULL;
	tail_a = ft_lstnew_t();
	tail_b = ft_lstnew_t();
	parse(argv, tail_a);
	i = tail_a->size;
	while ((gnl = get_next_line(0, &line)) > 0)
	{
		checker(tail_a, tail_b, &line);
		free(line);
		line = NULL;
	}
	free(line);
	show_result(tail_a, i);
	free_lst(tail_a);
	free_lst(tail_b);
	return (0);
}
