/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_five.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 19:58:06 by jupark            #+#    #+#             */
/*   Updated: 2021/06/04 22:50:06 by jupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a_to_b_five(t_stacks *stack, int size)
{
	t_node	*head;
	int		pb;

	if (size <= 3)
	{
		ft_optimize(stack, size, 1);
		return ;
	}
	get_pivot(stack, stack->lst_a, size, 1);
	head = stack->lst_a->head;
	while (size--)
	{
		if (head->num >= stack->p1)
		{
			if (size)
				ft_ra(stack);
			else
				stack->ra_cnt++;
		}
		else
			ft_pb(stack);
		head = stack->lst_a->head;
	}
	pb = stack->p_cnt;
	a_to_b_five(stack, stack->ra_cnt);
	b_to_a_five(stack, pb);
}

void	b_to_a_five(t_stacks *stack, int size)
{
	if (size <= 3)
	{
		ft_optimize(stack, size, 0);
		return ;
	}
}
