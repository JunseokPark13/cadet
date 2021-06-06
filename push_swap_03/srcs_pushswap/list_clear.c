/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_clear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 17:16:44 by jupark            #+#    #+#             */
/*   Updated: 2021/06/06 22:57:48 by jupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstdelone(t_node *node)
{
	if(!node)
		return ;
	free(node);
}

void	ft_lstclear(t_list *lst)
{
	t_node *head;
	t_node *next_n;
	int		i;

	if(!lst)
		return ;
	head = lst->head;
	i = 0;
	while(1)
	{
		if (i > 0 && head == lst->head)
			break;
		next_n = head->next;
		ft_lstdelone(head);
		head = next_n;
		i++;
	}
	free(lst);
}

void	ft_stacksclear(t_stacks *stack)
{
	if (!stack)
		return ;
	ft_lstclear(stack->lst_a);
	free(stack->lst_b);
	free(stack);
}
