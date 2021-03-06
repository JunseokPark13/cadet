/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_a_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 17:56:01 by jupark            #+#    #+#             */
/*   Updated: 2021/06/08 15:03:44 by jupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	flagcheck(t_stacks *stack, int *flag, int size)
{
	if (*flag)
		ft_rb(stack);
	*flag = 0;
	ft_pb(stack);
	if (stack->lst_b->head->num >= stack->p1)
	{
		*flag = 1;
		if (!size)
			ft_rb(stack);
	}
}

static void	a_to_b_main(t_stacks *stack, int size)
{
	t_node	*head;
	int		flag;

	head = stack->lst_a->head;
	flag = 0;
	while (size--)
	{
		if (head->num >= stack->p2)
		{
			if (flag)
				ft_rr(stack, 0);
			else
				ft_ra(stack);
			flag = 0;
		}
		else
			flagcheck(stack, &flag, size);
		head = stack->lst_a->head;
	}
}

void		a_to_b(t_stacks *stack, int size)
{
	int		pb;
	int		rb;

	if (is_sorted(stack->lst_a, size, 1))
		return ;
	if (size <= 3)
	{
		ft_optimize(stack, size, 1);
		return ;
	}
	get_pivot(stack, stack->lst_a, size, 2);
	a_to_b_main(stack, size);
	rr_by_cnt(stack, stack->ra_cnt, stack->rb_cnt);
	pb = stack->p_cnt;
	rb = stack->rb_cnt;
	a_to_b(stack, stack->ra_cnt);
	b_to_a(stack, rb);
	b_to_a(stack, pb - rb);
}
