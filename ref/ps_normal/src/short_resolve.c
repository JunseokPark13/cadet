/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_resolve.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangcpar <sangcpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 04:20:43 by sangcpar          #+#    #+#             */
/*   Updated: 2021/05/30 04:20:46 by sangcpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		push_b(int size, t_list **a, t_list **b)
{
	int		j;
	int		i;

	i = 0;
	while (i++ < 2)
	{
		j = 0;
		if (find_pos(a, find_min(*a)) < size / 2)
			j = 1;
		while ((*a)->content != find_min(*a))
		{
			if (j)
				ra(a, 0);
			else
				rra(a, 0);
		}
		pb(a, b, 0);
	}
}

void		short_resolve(t_list **a)
{
	int		size;
	t_list	*b;
	t_info	*info;

	info = malloc(sizeof(t_info));
	size = lst_size(a);
	if (sort(a))
		return ;
	if (size > 3)
		push_b(size, a, &b);
	while (!sort(a))
	{
		if ((*a)->content >= find_max(a))
			ra(a, 0);
		else if ((*a)->content > (*a)->next->content)
			sa(a, 0);
		else
			ra(a, 0);
	}
	if (size > 3)
	{
		pa(a, &b, 0);
		pa(a, &b, 0);
	}
	free(info);
}
