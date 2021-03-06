/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 03:39:19 by dim               #+#    #+#             */
/*   Updated: 2021/06/28 11:46:35 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		set_pivot(int *arr, t_pivot *pivot, int size)
{
	pivot->p1 = arr;
	pivot->p2 = arr + size / 3;
	pivot->p3 = arr + ((size / 3) * 2);
}

void		init_lstsave(t_save *save)
{
	save->n_pa = 0;
	save->n_pb = 0;
	save->n_ra = 0;
	save->n_rb = 0;
}

void		int_swap(int *a, int *b)
{
	int		temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int			*arr_forsort(t_lst *tail_lst)
{
	t_st	*cur;
	int		*arr;
	int		i;
	int		size;

	i = 0;
	size = tail_lst->size;
	arr = (int *)malloc(sizeof(int) * size);
	if (arr == NULL)
		exit(1);
	cur = tail_lst->tail->next;
	while (i < size)
	{
		arr[i++] = cur->num;
		cur = cur->next;
	}
	return (arr);
}

void		quick_sort(int left, int right, int *arr)
{
	int		pivot;
	int		i;
	int		j;

	i = left;
	j = right;
	pivot = arr[(left + right) / 2];
	if (left < right)
	{
		while (i <= j)
		{
			while (arr[i] < pivot)
				i++;
			while (arr[j] > pivot)
				j--;
			if (i <= j)
			{
				int_swap(&(arr[i]), &(arr[j]));
				i++;
				j--;
			}
		}
		quick_sort(left, j, arr);
		quick_sort(i, right, arr);
	}
}
