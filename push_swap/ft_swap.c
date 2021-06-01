/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 19:05:11 by jupark            #+#    #+#             */
/*   Updated: 2021/06/01 19:25:17 by jupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_sa(t_stacks *stack)
{
	t_node	*first;
	t_node	*second;
	t_list	*lst;
	int		tmp;

	lst = stack->lst_a;
	if (!lst->cnt || lst->cnt == 1)
		return;
	first = lst->head;
	second = first->next;
	tmp = first->num;
	first->num = second->num;
	second->num = tmp;
}

void		ft_sb(t_stacks *stack)
{
	t_node	*first;
	t_node	*second;
	t_list	*lst;
	int		tmp;

	lst = stack->lst_b;
	if (!lst->cnt || lst->cnt == 1)
		return;
	first = lst->head;
	second = first->next;
	tmp = first->num;
	first->num = second->num;
	second->num = tmp;
}

void		ft_ss(t_stacks *stack)
{
	ft_sa(stack);
	ft_sb(stack);
}
