/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 17:56:01 by jupark            #+#    #+#             */
/*   Updated: 2021/06/03 23:41:49 by jupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr_by_cnt(t_stacks *stack)
{
	int		i;

	i = 0;
	while (i < stack->ra_cnt && i < stack->rb_cnt)
	{
		ft_rrr(stack);
		i++;
	}
	stack->isprint = 0;
	if (i == stack->ra_cnt && i < stack->rb_cnt)
		while (i++ < stack->rb_cnt)
			ft_rrb(stack);
	if (i == stack->rb_cnt && i < stack->ra_cnt)
		while (i++ < stack->ra_cnt)
			ft_rra(stack);
}

void	a_to_b(t_stacks *stack, int size)
{
	t_node	*head;
	int		pb;
	int		rb;

	//ft_printlst_two(stack->lst_a, stack->lst_b);

	if (is_sorted(stack->lst_a, size, 1))
		return ;
	if (size <= 3)
	{
		if (size == 2)
			sort_two(stack, stack->lst_a, 1);
		else if (size == 3)
			sort_three(stack, stack->lst_a, 1);
		return ;
	}
	get_pivot_from_lst(stack, stack->lst_a, size);
	//printf("a to b : %d %d\n", stack->p1, stack->p2);
	head = stack->lst_a->head;
	while (size--)
	{
		if (head->num >= stack->p2)
			ft_ra(stack);
		else
		{
			ft_pb(stack);
			if (stack->lst_b->head->num >= stack->p1)
				ft_rb(stack);
		}
		head = stack->lst_a->head;
	}
	rr_by_cnt(stack);
	pb = stack->p_cnt;
	rb = stack->rb_cnt;
	a_to_b(stack, stack->ra_cnt);
	b_to_a(stack, rb);
	b_to_a(stack, pb - rb);
}

void	b_to_a(t_stacks *stack, int size)
{
	t_node	*head;
	int		pa;
	int		ra;
	int		rb;

	if (is_sorted(stack->lst_b, size, 0))
	{
		while (size--)
			ft_pa(stack);
		return ;
	}

	//ft_printlst_two(stack->lst_a, stack->lst_b);
	if (size <= 3)
	{
		if (size == 2)
			sort_two(stack, stack->lst_b, 0);
		else if (size == 3)
			sort_three(stack, stack->lst_b, 0);
		while (size--)
			ft_pa(stack);
		return ;
	}
	get_pivot_from_lst(stack, stack->lst_b, size);
	//printf("b to a : %d %d\n", stack->p1, stack->p2);
	head = stack->lst_b->head;
	while (size--)
	{
		if (head->num <= stack->p1)
			ft_rb(stack);
		else
		{
			ft_pa(stack);
			if (stack->lst_a->head->num <= stack->p2)
				ft_ra(stack);
		}
		head = stack->lst_b->head;
	}
	ra = stack->ra_cnt;
	pa = stack->p_cnt;
	rb = stack->rb_cnt;
	a_to_b(stack, pa - ra);
	stack->ra_cnt = ra;
	stack->p_cnt = pa;
	stack->rb_cnt = rb;
	rr_by_cnt(stack);
	a_to_b(stack, ra);
	b_to_a(stack, rb);
}
