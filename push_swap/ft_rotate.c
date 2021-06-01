/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 19:15:09 by jupark            #+#    #+#             */
/*   Updated: 2021/06/01 19:17:23 by jupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_stacks *stack)
{
	t_node	*head;
	t_node	*tail;

	if (!stack->lst_a->cnt || stack->lst_a->cnt == 1)
		return ;
	head = stack->lst_a->head;
	tail = stack->lst_a->tail;
	stack->lst_a->head = head->next;
	stack->lst_a->tail = tail->next;
}

void	ft_rb(t_stacks *stack)
{
	t_node	*head;
	t_node	*tail;

	if (!stack->lst_b->cnt || stack->lst_b->cnt == 1)
		return ;
	head = stack->lst_b->head;
	tail = stack->lst_b->tail;
	stack->lst_b->head = head->next;
	stack->lst_b->tail = tail->next;
}

void	ft_rr(t_stacks *stack)
{
	ft_ra(stack);
	ft_rb(stack);
}
