/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangcpar <sangcpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 05:54:11 by sangcpar          #+#    #+#             */
/*   Updated: 2021/05/28 05:54:13 by sangcpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		move_b(t_list **a, t_list **b, t_info **info)
{
	int		temp;

	temp = (*info)->a_size;
	while (temp && (*info)->a_size > 2)
	{
		if ((*a)->content <= (*info)->pivot)
		{
			pb(a, b, 0);
			if ((*b)->next && (*b)->content < find_mid(b, (*info)->b_size))
			{
				if ((*a)->content > (*info)->pivot)
					rr(a, b, 0);
				else
					rb(b, 0);
			}
			(*info)->a_size--;
			(*info)->b_size++;
		}
		else
			ra(a, 0);
		temp--;
	}
}

void		push_max(t_list **a, t_list **b, t_info **info)
{
	int		m;
	int		flag;

	m = (*info)->max;
	flag = 0;
	if ((*b)->content < m)
	{
		while ((*b)->content != m)
		{
			if ((*b)->next->content == m)
			{
				sb(b, 0);
				pa(a, b, 0);
				flag = 1;
				return ;
			}
			if ((*info)->flag == 1)
				rb(b, 0);
			else
				rrb(b, 0);
		}
	}
	if (!flag)
		pa(a, b, 0);
}

void		move_a(t_list **a, t_list **b, t_info **info)
{
	int		temp;
	int		t;

	temp = (*info)->b_size;
	while ((*info)->b_size > 2)
	{
		(*info)->flag = 0;
		if (*b)
			(*info)->max = find_max(b);
		if ((t = find_pos(b, (*info)->max)) < (*info)->b_size / 2)
			(*info)->flag = 1;
		else
			(*info)->flag = 0;
		push_max(a, b, info);
		(*info)->a_size++;
		(*info)->b_size--;
	}
}

void		resolve(t_list **a)
{
	t_info	*info;
	t_list	*b;

	if (sort(a))
		return ;
	info = malloc(sizeof(t_info));
	b = NULL;
	info->b_size = 0;
	info->a_size = lst_size(a);
	while (info->a_size > 2)
	{
		info->pivot = find_mid(a, info->a_size);
		move_b(a, &b, &info);
	}
	pb(a, &b, 0);
	pb(a, &b, 0);
	info->b_size += 2;
	move_a(a, &b, &info);
	pa(a, &b, 0);
	pa(a, &b, 0);
	if ((*a)->content > (*a)->next->content)
		sa(a, 0);
	free(info);
}
