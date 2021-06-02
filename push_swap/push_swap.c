/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 17:56:01 by jupark            #+#    #+#             */
/*   Updated: 2021/06/02 19:11:26 by jupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr_together(t_stacks *stack, int l1, int l2)
{
	int		i;
	
	i = 0;
	while (i < l1 && i < l2)
	{
		ft_rrr(stack);
		i++;
	}
	if (i >= l1 && i < l2)
		while (i++ < l2)
			ft_rrb(stack);
	else if (i < l1 && i >= l2)
		while (i++ < l1)
			ft_rra(stack);
}

void	a_to_b(t_stacks *stack, int size)
{
	t_node	*head;
	int		ra_cnt;
	int		rb_cnt;
	int		pb_cnt;

	if (size < 3)
		return ;
	get_pivot_from_lst(stack, stack->lst_a, size);
	//printf("p1 = %d, p2 = %d\n", stack->p1, stack->p2);
	ra_cnt = 0;
	rb_cnt = 0;
	pb_cnt = 0;
	head = stack->lst_a->head;
	while (size--)
	{
		if (head->num >= stack->p2)
		{
			ft_ra(stack);
			ra_cnt++;
		}
		else
		{
			ft_pb(stack);
			pb_cnt++;
			if (stack->lst_b->head->num >= stack->p1)
			{
				ft_rb(stack);
				rb_cnt++;
			}
		}
		head = stack->lst_a->head;
	}
	rr_together(stack, ra_cnt, rb_cnt);
	printf("a_to_b : ra = %d, rb = %d, pb = %d\n", ra_cnt, rb_cnt, pb_cnt);
	//printf("ra_cnt = %d\nrb_cnt = %d\npb_cnt = %d\n", ra_cnt, rb_cnt, pb_cnt);
	a_to_b(stack, ra_cnt);
	b_to_a(stack, rb_cnt);
	b_to_a(stack, pb_cnt - rb_cnt);
}

void	b_to_a(t_stacks *stack, int size)
{
	t_node	*head;
	int		rb_cnt;
	int		ra_cnt;
	int		pa_cnt;

	if (size < 3)
	{
		//printf("push to a %d\n", size);
		while (size--)
			ft_pa(stack);
		return ;
	}
	get_pivot_from_lst(stack, stack->lst_b, size);
	head = stack->lst_b->head;
	rb_cnt = 0;
	ra_cnt = 0;
	pa_cnt = 0;
	while (size--)
	{
		if (head->num < stack->p1)
		{
			ft_rb(stack);
			rb_cnt++;
		}
		else
		{
			ft_pa(stack);
			pa_cnt++;
			if (stack->lst_a->head->num >= stack->p2)
			{
				ft_ra(stack);
				ra_cnt++;
			}
		}
	}
	printf("b_to_a : ra = %d, rb = %d, pa = %d\n", ra_cnt, rb_cnt, pa_cnt);
	a_to_b(stack, pa_cnt - ra_cnt);
	rr_together(stack, ra_cnt, rb_cnt);
	a_to_b(stack, rb_cnt);
	b_to_a(stack, ra_cnt);
}
