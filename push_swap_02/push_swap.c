/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 17:56:01 by jupark            #+#    #+#             */
/*   Updated: 2021/06/04 22:58:02 by jupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rr_by_cnt(t_stacks *stack, int ra_cnt, int rb_cnt)
{
	int		i;

	i = 0;
	while (i < ra_cnt && i < rb_cnt)
	{
		ft_rrr(stack);
		i++;
	}
	if (i == ra_cnt && i < rb_cnt)
		while (i++ < rb_cnt)
			ft_rrb(stack);
	if (i == rb_cnt && i < ra_cnt)
		while (i++ < ra_cnt)
			ft_rra(stack);
}

void		a_to_b(t_stacks *stack, int size)
{
	t_node	*head;
	int		pb;
	int		rb;
	int		flag;

	//ft_printlst_two(stack->lst_a, stack->lst_b);
	if (is_sorted(stack->lst_a, size, 1))
		return ;
	if (size <= 3)
	{
		ft_optimize(stack, size, 1);
		return ;
	}
	get_pivot(stack, stack->lst_a, size, 2);
	//printf("a to b : %d %d\n", stack->p1, stack->p2);
	head = stack->lst_a->head;
	flag = 0;
	while (size--)
	{
		if (head->num >= stack->p2)
		{
			if (flag)
				ft_rr(stack);
			else
				ft_ra(stack);
			flag = 0;
		}
		else
		{
			if (flag)
				ft_rb(stack);
			flag = 0;
			ft_pb(stack);
			if (stack->lst_b->head->num >= stack->p1)
			{
				flag = 1;
				if (!size)
					ft_rb(stack);
			}
		}
		head = stack->lst_a->head;
	}
	rr_by_cnt(stack, stack->ra_cnt, stack->rb_cnt);
	pb = stack->p_cnt;
	rb = stack->rb_cnt;
	a_to_b(stack, stack->ra_cnt);
	b_to_a(stack, rb);
	b_to_a(stack, pb - rb);
}

void		b_to_a(t_stacks *stack, int size)
{
	t_node	*head;
	int		pa;
	int		ra;
	int		rb;
	int		flag;
	
	//ft_printlst_two(stack->lst_a, stack->lst_b);
	if (size <= 3)
	{
		ft_optimize(stack, size, 0);
		return ;
	}
	get_pivot(stack, stack->lst_b, size, 2);
	//printf("b to a : %d %d\n", stack->p1, stack->p2);
	head = stack->lst_b->head;
	flag = 0;
	while (size--)
	{
		if (head->num <= stack->p1)
		{
			if (flag)
				ft_rr(stack);
			else
				ft_rb(stack);
			flag = 0;
		}
		else
		{
			if (flag)
				ft_ra(stack);
			flag = 0;
			ft_pa(stack);
			if (stack->lst_a->head->num <= stack->p2)
			{
				flag = 1;
				if (!size)
					ft_ra(stack);
			}
		}
		head = stack->lst_b->head;
	}
	ra = stack->ra_cnt;
	pa = stack->p_cnt;
	rb = stack->rb_cnt;
	a_to_b(stack, pa - ra);
	rr_by_cnt(stack, ra, rb);
	a_to_b(stack, ra);
	b_to_a(stack, rb);
}
