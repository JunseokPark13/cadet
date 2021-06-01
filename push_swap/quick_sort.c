/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 16:59:26 by jupark            #+#    #+#             */
/*   Updated: 2021/06/01 19:22:24 by jupark           ###   ########.fr       */
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

void			ft_quick_sort(int *ary, int left, int right)
{
	int		pivot;

	if (left <= right)
	{
		pivot = partition(ary, left, right);
		ft_quick_sort(ary, left, pivot - 1);
		ft_quick_sort(ary, pivot + 1, right);
	}
}

void			ft_get_pivot(int *ary, int length, int *p1, int *p2)
{
	int		pos;
	ft_quick_sort(ary, 0, length - 1);
	pos = length / 3;
//	for(int i = 0; i < length; i++)
//		printf("%d\n", ary[i]);
	*p1 = ary[pos];
	*p2 = ary[pos * 2];
}
