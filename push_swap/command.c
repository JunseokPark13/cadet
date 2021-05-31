/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 21:39:52 by jupark            #+#    #+#             */
/*   Updated: 2021/06/01 00:16:35 by jupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_list *lst)
{
	t_node *first;
	t_node *second;
	int		tmp;

	first = lst->head;
	second = first->next;
	tmp = first->num;
	first->num = second->num;
	second->num = tmp;
}

void	ft_move(t_list *lst, int dir)
{
	t_node *head;
	t_node *tail;
	
	head = lst->head;
	tail = lst->tail;
	if (dir)
	{
		lst->head = head->next;
		lst->tail = tail->next;
	}
	else
	{
		lst->head = head->prev;
		lst->tail = tail->prev;
	}
}

void	ft_push(t_list *lst1, t_list *lst2)
{
	t_node *head;
	t_node *next;
	t_node *prev;

	head = lst1->head;
	next = head->next;
	prev = head->prev;
	head->next = NULL;
	head->prev = NULL;
	prev->next = next;
	next->prev = prev;
	ft_lstadd_front(lst2, head);
}
