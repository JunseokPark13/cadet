/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 17:16:44 by jupark            #+#    #+#             */
/*   Updated: 2021/06/01 00:28:57 by jupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_printlst_front(t_list *lst)
{
	t_node	*head;
	int		k;

	k = 0;
	head = lst->head;
	while (1)
	{
		if (k > 0 && head == lst->head)
			break ;
		printf("%d :   %d\n", k++, head->num);	
		head = head->next;
	}
}

void	ft_printlst_back(t_list *lst)
{
	t_node	*tail;
	int		k;

	k = 0;
	tail = lst->tail;
	while (1)
	{
		if (k > 0 && tail == lst->tail)
			break ;
		printf("%d :   %d\n", k++, tail->num);	
		tail = tail->prev;
	}
}

void	ft_lstdelone(t_node *node)
{
	if(!node)
		return ;
	free(node);
}

void	ft_lstclear(t_list *lst)
{
	t_node *current_n;
	t_node *next_n;

	if(!lst)
		return ;
	current_n = lst->head;
	while(current_n)
	{
		next_n = current_n->next;
		ft_lstdelone(current_n);
		current_n = next_n;
	}
	free(lst);
}
