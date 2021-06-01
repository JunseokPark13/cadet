/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stack2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangcpar <sangcpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 10:06:25 by sangcpar          #+#    #+#             */
/*   Updated: 2021/05/30 10:06:27 by sangcpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		rra(t_list **a, int i)
{
	t_list	*cp;
	t_list	*tmp;

	if (!(*a) || !(*a)->next)
		return ;
	tmp = *a;
	cp = *a;
	while (tmp->next)
	{
		if (cp->next->next)
			cp = cp->next;
		tmp = tmp->next;
	}
	cp->next = NULL;
	tmp->next = *a;
	*a = tmp;
	if (i == 0)
		put_msg("rra\n");
}

void		rrb(t_list **b, int i)
{
	t_list	*cp;
	t_list	*tmp;

	if (!(*b) || !(*b)->next)
		return ;
	tmp = *b;
	cp = *b;
	while (tmp->next)
	{
		if (cp->next->next)
			cp = cp->next;
		tmp = tmp->next;
	}
	cp->next = NULL;
	tmp->next = *b;
	*b = tmp;
	if (i == 0)
		put_msg("rrb\n");
}

void		rrr(t_list **a, t_list **b, int i)
{
	rra(a, 1);
	rrb(b, 1);
	if (i == 0)
		put_msg("rrr\n");
}
