/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 19:10:52 by jupark            #+#    #+#             */
/*   Updated: 2021/06/01 19:25:58 by jupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pb(t_stacks *stack)
{
	t_node	*head;
	t_node	*next;
	t_node	*prev;

	if (!stack->lst_a->cnt)
		return ;
	head = stack->lst_a->head;
	next = head->next;
	prev = head->prev;
	head->next = NULL;
	head->prev = NULL;
	prev->next = next;
	next->prev = prev;
	stack->lst_a->cnt -= 1;
	if (!stack->lst_a->cnt)
	{
		stack->lst_a->head = NULL;
		stack->lst_a->tail = NULL;
	}
	else
	{
		stack->lst_a->head = next;
		stack->lst_a->tail = next->prev;
	}
	ft_lstadd_back(stack->lst_b, head);
}

void	ft_pa(t_stacks *stack)
{
	t_node	*head;
	t_node	*next;
	t_node	*prev;

	if (!stack->lst_b->cnt)
		return ;
	head = stack->lst_b->head;
	next = head->next;
	prev = head->prev;
	head->next = NULL;
	head->prev = NULL;
	prev->next = next;
	next->prev = prev;
	stack->lst_b->cnt -= 1;
	if (!stack->lst_b->cnt)
	{
		stack->lst_b->head = NULL;
		stack->lst_b->tail = NULL;
	}
	else
	{
		stack->lst_b->head = next;
		stack->lst_b->tail = next->prev;
	}
	ft_lstadd_back(stack->lst_a, head);
}
