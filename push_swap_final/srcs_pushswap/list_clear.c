/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_clear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 17:16:44 by jupark            #+#    #+#             */
/*   Updated: 2021/06/08 16:49:29 by jupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_lstdelone(t_node *node)
{
	if (!node)
		return ;
	free(node);
}

static void	ft_lstclear(t_list *lst)
{
	t_node	*head;
	t_node	*next_n;
	int		i;

	if (!lst)
		return ;
	if (!lst->cnt || lst->cnt == 1)
	{
		free(lst);
		return ;
	}
	head = lst->head;
	i = 0;
	while (1)
	{
		if (i > 0 && head == lst->head)
			break ;
		next_n = head->next;
		ft_lstdelone(head);
		head = next_n;
		i++;
	}
	free(lst);
}

void		ft_stacksclear(t_stacks *stack)
{
	if (!stack)
		return ;
	ft_lstclear(stack->lst_a);
	ft_lstclear(stack->lst_b);
	free(stack);
}
