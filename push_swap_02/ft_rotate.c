/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 19:15:09 by jupark            #+#    #+#             */
/*   Updated: 2021/06/04 21:03:24 by jupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_stacks *stack)
{
	t_node	*head;
	
	stack->ra_cnt += 1;
	if (!stack->lst_a->cnt || stack->lst_a->cnt == 1)
		return ;
	head = stack->lst_a->head;
	stack->lst_a->head = head->next;
	stack->lst_a->tail = head;
	if (!stack->isprint)
		write(1, "ra\n", 3);
}

void	ft_rb(t_stacks *stack)
{
	t_node	*head;

	stack->rb_cnt += 1;
	if (!stack->lst_b->cnt || stack->lst_b->cnt == 1)
		return ;
	head = stack->lst_b->head;
	stack->lst_b->head = head->next;
	stack->lst_b->tail = head;
	if (!stack->isprint)
		write(1, "rb\n", 3);
}

void	ft_rr(t_stacks *stack)
{
	stack->isprint = 1;
	ft_ra(stack);
	ft_rb(stack);
	write(1, "rr\n", 3);
	stack->isprint = 0;
}
