/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 17:06:52 by jupark            #+#    #+#             */
/*   Updated: 2021/05/31 18:37:46 by jupark           ###   ########.fr       */
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
	return (lst);
}

t_node	*ft_lstlast(t_node *lst)
{
	t_node	*next_n;
	
	if(!lst)
		return (NULL);
	next_n = lst;
	while(next_n->next)
		next_n = next_n->next;
	return (next_n);
}

void	ft_lstadd_back(t_list *lst, t_node *new_n)
{
	t_node *head;
	t_node *tail;

	if(!lst->tail)
	{
		lst->head = new_n;
		lst->tail = new_n;
		return ;
	}
	head = lst->head;
	tail = lst->tail;
	head->prev = new_n;
	tail->next = new_n;
	new_n->next = head;
	new_n->prev = tail;
	lst->head = new_n;
}

void	ft_lstadd_front(t_list *lst, t_node *new_n)
{
	t_node	*head;
	t_node	*tail;

	if (!lst->head)
	{
		lst->head = new_n;
		lst->tail = new_n;
		return ;
	}
	head = lst->head;
	tail = lst->tail;
	head->prev = new_n;
	tail->next = new_n;
	new_n->next = head;
	new_n->prev = tail;
	lst->tail = new_n;
}
