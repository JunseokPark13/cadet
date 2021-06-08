/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_five.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 19:58:06 by jupark            #+#    #+#             */
/*   Updated: 2021/06/06 23:04:29 by jupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	a_to_b_five_main(t_stacks *stack, int size)
{
	t_node	*head;

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
}

void		a_to_b_five(t_stacks *stack, int size)
{
	int		pb;

	if (size <= 3)
	{
		ft_optimize(stack, size, 1);
		return ;
	}
	get_pivot(stack, stack->lst_a, size, 1);
	a_to_b_five_main(stack, size);
	pb = stack->p_cnt;
	a_to_b_five(stack, stack->ra_cnt);
	ft_optimize(stack, pb, 0);
}
