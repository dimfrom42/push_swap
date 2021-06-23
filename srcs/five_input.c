/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 03:26:35 by dim               #+#    #+#             */
/*   Updated: 2021/06/23 02:43:14 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	printtail2(t_lst *tail_a)
{
	t_st	*cur;
	int		size;

	size = tail_a->size;
	cur = tail_a->tail->next;
	while (size--)
	{
		printf("lst->num : %lld\n", cur->num);
		cur = cur->next;
	}
}

void		five_input(t_lst *tail_a, t_lst *tail_b)
{
	t_st	*min;
	t_st	*max;
	t_st	*cur;
	int		size;
	int		flag;

	size = tail_a->size;
	flag = 0;
	cur = tail_a->tail->next;
	min = check_min(tail_a, 5);
	max = check_max(tail_a, 5);
	// printf("min : %lld, max : %lld\n", min->num, max->num);
	while(size--)
	{
		if (cur == min || \
		cur == max)
		{
			cur = cur->next;
			pb(tail_a, tail_b);
			flag++;
			if (flag == 2)
				break;
		}
		else
		{
			ra(tail_a);
			cur = cur->next;
		}
	}
	three_input(tail_a);
	while (flag--)
	{
		pa(tail_a, tail_b);
		if (tail_a->tail->next == max)
			ra(tail_a);
	}
	printtail2(tail_a);
}
