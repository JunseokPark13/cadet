/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 19:10:52 by jupark            #+#    #+#             */
/*   Updated: 2021/06/06 21:04:55 by jupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*push_node(t_list *lst)
{
	t_node	*head;

	head = lst->head;
	(head->prev)->next = head->next;
	(head->next)->prev = head->prev;
	lst->cnt -= 1;
	lst->head = head->next;
	lst->tail = head->prev;
	return (head);
}

void	ft_pb(t_stacks *stack)
{
	t_node	*head;

	stack->p_cnt += 1;
	if (!stack->lst_a->cnt)
		return ;
	head = push_node(stack->lst_a);
	ft_lstadd_back(stack->lst_b, head);
	write(1, "pb\n", 3);
}

void	ft_pa(t_stacks *stack)
{
	t_node	*head;

	stack->p_cnt += 1;
	if (!stack->lst_b->cnt)
		return ;
	head = push_node(stack->lst_b);
	ft_lstadd_back(stack->lst_a, head);
	write(1, "pa\n", 3);
}
