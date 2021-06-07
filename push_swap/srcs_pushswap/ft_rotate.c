/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 19:15:09 by jupark            #+#    #+#             */
/*   Updated: 2021/06/07 15:39:29 by jupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_stacks *stack)
{
	t_node	*head;

	if (!stack)
		return ;
	stack->ra_cnt += 1;
	if (!stack->lst_a->cnt || stack->lst_a->cnt == 1)
		return ;
	head = stack->lst_a->head;
	stack->lst_a->head = head->next;
	stack->lst_a->tail = head;
	if (!stack->isprint)
		ft_putstr("ra");
}

void	ft_rb(t_stacks *stack)
{
	t_node	*head;

	if (!stack)
		return ;
	stack->rb_cnt += 1;
	if (!stack->lst_b->cnt || stack->lst_b->cnt == 1)
		return ;
	head = stack->lst_b->head;
	stack->lst_b->head = head->next;
	stack->lst_b->tail = head;
	if (!stack->isprint)
		ft_putstr("rb");
}

void	ft_rr(t_stacks *stack)
{
	if (!stack)
		return ;
	stack->isprint = 1;
	ft_ra(stack);
	ft_rb(stack);
	ft_putstr("rr");
	stack->isprint = 0;
}
