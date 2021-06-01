/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangcpar <sangcpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 08:02:46 by sangcpar          #+#    #+#             */
/*   Updated: 2021/05/28 08:02:49 by sangcpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		sa(t_list **a, int i)
{
	t_list	*tmp;
	int		temp;

	tmp = *a;
	tmp = tmp->next;
	temp = tmp->content;
	tmp->content = (*a)->content;
	(*a)->content = temp;
	if (i == 0)
		put_msg("sa\n");
}

void		sb(t_list **b, int i)
{
	t_list	*tmp;
	int		temp;

	tmp = *b;
	tmp = tmp->next;
	temp = tmp->content;
	tmp->content = (*b)->content;
	(*b)->content = temp;
	if (i == 0)
		put_msg("sb\n");
}

void		ss(t_list **a, t_list **b, int i)
{
	sa(a, 1);
	sb(b, 1);
	if (i == 0)
		put_msg("ss\n");
}

void		pb(t_list **a, t_list **b, int i)
{
	t_list	*tmp;

	if (!(*a))
		return ;
	tmp = *a;
	(*a) = (*a)->next;
	tmp->next = *b;
	*b = tmp;
	if (i == 0)
		put_msg("pb\n");
}

void		pa(t_list **a, t_list **b, int i)
{
	t_list	*tmp;

	if (!(*b))
		return ;
	tmp = *b;
	(*b) = (*b)->next;
	tmp->next = *a;
	*a = tmp;
	if (i == 0)
		put_msg("pa\n");
}
