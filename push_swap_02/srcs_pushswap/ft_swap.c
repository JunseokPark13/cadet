/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 19:05:11 by jupark            #+#    #+#             */
/*   Updated: 2021/06/06 21:29:57 by jupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_num_swap(t_node *n1, t_node *n2)
{
	int		temp;

	temp = n1->num;
	n1->num = n2->num;
	n2->num = temp;
}

void		ft_sa(t_stacks *stack)
{
	t_list	*lst;

	lst = stack->lst_a;
	if (!lst->cnt || lst->cnt == 1)
		return;
	ft_num_swap(lst->head, lst->head->next);
	ft_putstr("sa");
}

void		ft_sb(t_stacks *stack)
{
	t_list	*lst;

	lst = stack->lst_b;
	if (!lst->cnt || lst->cnt == 1)
		return;
	ft_num_swap(lst->head, lst->head->next);
	ft_putstr("sb");
}

void		ft_ss(t_stacks *stack)
{
	ft_sa(stack);
	ft_sb(stack);
}
