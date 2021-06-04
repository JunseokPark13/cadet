/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 19:17:45 by jupark            #+#    #+#             */
/*   Updated: 2021/06/04 21:10:56 by jupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_stacks *stack)
{
	t_node	*head;
	t_node	*tail;

	if (!stack->lst_a->cnt || stack->lst_a->cnt == 1)
		return ;
	head = stack->lst_a->head;
	tail = stack->lst_a->tail;
	stack->lst_a->head = head->prev;
	stack->lst_a->tail = tail->prev;
	if (!stack->isprint)
		write(1, "rra\n", 4);
}

void	ft_rrb(t_stacks *stack)
{
	t_node	*head;
	t_node	*tail;

	if (!stack->lst_b->cnt || stack->lst_b->cnt == 1)
		return ;
	head = stack->lst_b->head;
	tail = stack->lst_b->tail;
	stack->lst_b->head = head->prev;
	stack->lst_b->tail = tail->prev;
	if (!stack->isprint)
		write(1, "rrb\n", 4);
}

void	ft_rrr(t_stacks *stack)
{
	stack->isprint = 1;
	ft_rra(stack);
	ft_rrb(stack);
	write(1, "rrr\n", 4);
	stack->isprint = 0;
}
