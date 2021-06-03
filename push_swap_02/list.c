/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 17:06:52 by jupark            #+#    #+#             */
/*   Updated: 2021/06/03 21:32:29 by jupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node		*ft_nodenew(int num)
{
	t_node	*node;

	node = (t_node*)malloc(sizeof(t_node));
	if (!node)
		exit(1);
	node->num = num;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

t_list		*ft_lstnew()
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

void	ft_lstadd_back(t_list *lst, t_node *new_n)
{
	t_node *head;
	t_node *tail;

	if(!lst->tail)
	{
		lst->head = new_n;
		lst->tail = new_n;
		lst->cnt += 1;
		return ;
	}
	head = lst->head;
	tail = lst->tail;
	head->prev = new_n;
	tail->next = new_n;
	new_n->next = head;
	new_n->prev = tail;
	lst->head = new_n;
	lst->cnt += 1;
}

void	ft_lstadd_front(t_list *lst, t_node *new_n)
{
	t_node	*head;
	t_node	*tail;

	if (!lst->head)
	{
		lst->head = new_n;
		lst->tail = new_n;
		lst->cnt += 1;
		return ;
	}
	head = lst->head;
	tail = lst->tail;
	head->prev = new_n;
	tail->next = new_n;
	new_n->next = head;
	new_n->prev = tail;
	lst->tail = new_n;
	lst->cnt += 1;
}
