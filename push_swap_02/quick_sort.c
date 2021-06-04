/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 16:59:26 by jupark            #+#    #+#             */
/*   Updated: 2021/06/04 20:02:20 by jupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		swap(int *ary, int x, int y)
{
	int 	temp;
	
	temp = ary[x];
	ary[x] = ary[y];
	ary[y] = temp;
}

static int		partition(int *ary, int left, int right)
{
	int		pivot;
	int		low;
	int		high;
	
	low = left + 1;
	high = right;
	pivot = ary[left];
	while (low <= high)
	{
		while (low <= right && pivot >= ary[low])
			low++;
		while (high >= (left + 1) && pivot <= ary[high])
			high--;
		if (low <= high)
			swap(ary, low, high);
	}
	swap(ary, left, high);
	return (high);
}

static void		ft_quick_sort(int *ary, int left, int right)
{
	int		pivot;

	if (left <= right)
	{
		pivot = partition(ary, left, right);
		ft_quick_sort(ary, left, pivot - 1);
		ft_quick_sort(ary, pivot + 1, right);
	}
}

void			get_pivot(t_stacks *stack, t_list *lst, int size, int cs)
{
	t_node	*head;
	int		ary[size];
	int		i;

	head = lst->head;
	i = -1;
	while (++i < size)
	{
		ary[i] = head->num;
		head = head->next;
	}
	ft_quick_sort(ary, 0, size - 1);
	if (cs == 2)
	{
		stack->p1 = ary[size / 3];
		stack->p2 = ary[(size / 3) * 2];
	}
	else if (cs == 1)
		stack->p1 = ary[size / 2];
	ft_stackcnt_init(stack);
}

int				is_sorted(t_list *lst, int size, int dir)
{
	t_node	*head;
	int		k;
	
	head = lst->head;
	k = 0;
	while (1)
	{
		if ((k > 0 && head->next == lst->head) || k == size)
			return (1);
		else
		{
			if (dir)
			{
				if (head->num > head->next->num)
					return (0);
			}
			else
				if (head->num < head->next->num)
					return (0);
		}
		k++;
		head = head->next;
	}
}
