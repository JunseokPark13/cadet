/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 19:05:11 by jupark            #+#    #+#             */
/*   Updated: 2021/06/08 15:49:20 by jupark           ###   ########.fr       */
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

	if (!stack)
		return ;
	lst = stack->lst_a;
	if (!lst->cnt || lst->cnt == 1)
		return ;
	ft_num_swap(lst->head, lst->head->next);
	if (!stack->isprint)
		ft_putstr("sa\n");
}

void		ft_sb(t_stacks *stack)
{
	t_list	*lst;

	if (!stack)
		return ;
	lst = stack->lst_b;
	if (!lst->cnt || lst->cnt == 1)
		return ;
	ft_num_swap(lst->head, lst->head->next);
	if (!stack->isprint)
		ft_putstr("sb\n");
}

void		ft_ss(t_stacks *stack, int flag)
{
	if (!stack)
		return ;
	stack->isprint = 1;
	ft_sa(stack);
	ft_sb(stack);
	if (!flag)
	{
		ft_putstr("ss\n");
		stack->isprint = 0;
	}
}
