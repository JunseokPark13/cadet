/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 17:06:52 by jupark            #+#    #+#             */
/*   Updated: 2021/06/01 11:45:12 by jupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_nodenew(int num)
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

t_list	*ft_lstnew()
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
