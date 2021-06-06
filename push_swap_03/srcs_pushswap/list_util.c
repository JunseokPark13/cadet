/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 17:06:52 by jupark            #+#    #+#             */
/*   Updated: 2021/06/06 22:22:58 by jupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_lstcnt(t_list *lst)
{
	t_node	*head;
	int		cnt;

	head = lst->head;
	if (!head)
		return (0);
	cnt = 0;
	while (1)
	{
		if (cnt > 0 && head == lst->head)
			break;
		cnt++;
		head = head->next;
	}
	return (cnt);
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
