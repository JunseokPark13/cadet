/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 17:06:52 by jupark            #+#    #+#             */
/*   Updated: 2021/06/07 18:44:13 by jupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
t_node		*ft_nodenew(int num)
{
	t_node	*node;

	node = (t_node*)malloc(sizeof(t_node));
	if (!node)
		exit(1);
//	printf("num = %d\n", num);
	node->num = num;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

t_list		*ft_lstnew(void)
{
	t_list	*lst;

	lst = (t_list*)malloc(sizeof(t_list));
	if (!lst)
		exit(1);
	lst->head = NULL;
	lst->tail = NULL;
	lst->cnt = 0;
	return (lst);
}

t_stacks	*ft_stacknew(t_list *lst_a, t_list *lst_b)
{
	t_stacks	*stack;

	stack = (t_stacks*)malloc(sizeof(t_stacks));
	if (!stack)
		exit(1);
	stack->lst_a = lst_a;
	stack->lst_b = lst_b;
	stack->p1 = 0;
	stack->p2 = 0;
	stack->ra_cnt = 0;
	stack->rb_cnt = 0;
	stack->p_cnt = 0;
	return (stack);
}

void		ft_stackcnt_init(t_stacks *stack)
{
	stack->ra_cnt = 0;
	stack->rb_cnt = 0;
	stack->p_cnt = 0;
	stack->isprint = 0;
}
