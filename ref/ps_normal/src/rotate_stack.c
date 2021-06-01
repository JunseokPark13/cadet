/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangcpar <sangcpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 08:06:54 by sangcpar          #+#    #+#             */
/*   Updated: 2021/05/28 08:06:56 by sangcpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		put_msg(char *s)
{
	int		i;

	i = 0;
	while (s[i])
		write(1, &s[i++], 1);
}

void		ra(t_list **a, int i)
{
	t_list	*tmp;
	t_list	*new;

	if (!(*a) || !(*a)->next)
		return ;
	new = *a;
	tmp = (*a)->next;
	while ((*a)->next)
		(*a) = (*a)->next;
	(*a)->next = new;
	new->next = NULL;
	*a = tmp;
	if (i == 0)
		put_msg("ra\n");
}

void		rb(t_list **b, int i)
{
	t_list	*tmp;
	t_list	*new;

	if (!(*b) || !(*b)->next)
		return ;
	new = *b;
	tmp = (*b)->next;
	while ((*b)->next)
		(*b) = (*b)->next;
	(*b)->next = new;
	new->next = NULL;
	*b = tmp;
	if (i == 0)
		put_msg("rb\n");
}

void		rr(t_list **a, t_list **b, int i)
{
	ra(a, 1);
	rb(b, 1);
	if (i == 0)
		put_msg("rr\n");
}
