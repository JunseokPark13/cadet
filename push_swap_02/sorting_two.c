/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_two.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 17:21:43 by jupark            #+#    #+#             */
/*   Updated: 2021/06/04 20:59:10 by jupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			cmp_three(int a, int b, int c)
{
	if (a < c && c < b)
		return (1);
	else if (b < a && a < c)
		return (2);
	else if (b < c && c < a)
		return (3);
	else if (c < a && a < b)
		return (4);
	else if (c < b && b < a)
		return (5);
	else
		return (6);
}

void		sort_two(t_stacks *stack, t_list *lst, int st)
{
	t_node	*first;
	t_node	*second;

	first = lst->head;
	second = first->next;
	if (st && first->num > second->num)
		ft_sa(stack);
	else if (!st && first->num < second->num)
		ft_sb(stack);
}

int			lstnum_check(t_list *lst, t_node *head, int piv)
{
	int		k;

	k = 0;
	while (1)
	{
		if (k > 0 && head == lst->head)
			return (1);
		else
		{
			if (head->num >= piv)
				return (0);
		}
		head = head->next;
		k++;
	}
}
