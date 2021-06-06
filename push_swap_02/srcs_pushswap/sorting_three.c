/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 17:21:43 by jupark            #+#    #+#             */
/*   Updated: 2021/06/06 22:41:37 by jupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			cmp_three(int a, int b, int c)
{
	if(a < c && c < b)
		return (1);
	else if (b < a && a < c)
		return (2);
	else if (b < c && c < a)
		return (3);
	else if (c < a && a < b)
		return (4);
	else if (c < b && b < a)
		return (5);
	else
		return (6);
}

static void	sort_a_onlythree(t_stacks *stack, int a, int b, int c)
{
	int		cs;

	cs = cmp_three(a, b, c);
	if (cs == 1)
	{
		ft_rra(stack);
		ft_sa(stack);
	}
	else if (cs == 2)
		ft_sa(stack);
	else if (cs == 3)
		ft_ra(stack);
	else if (cs == 4)
		ft_rra(stack);
	else if (cs == 5)
	{
		ft_sa(stack);
		ft_rra(stack);
	}
}

static void	sort_b_onlythree(t_stacks *stack, int a, int b, int c)
{
	int		cs;
	cs = cmp_three(a, b, c);
	if (cs == 1)
		ft_rb(stack);
	else if (cs == 2)
		ft_rrb(stack);
	else if (cs == 3)
	{
		ft_rrb(stack);
		ft_sb(stack);
	}
	else if (cs == 4)
		ft_sb(stack);
	else if (cs == 6)
	{
		ft_sb(stack);
		ft_rrb(stack);
	}	
}

void		sort_three(t_stacks *stack, t_list *lst, int st)
{
	int	f;
	int s;
	int t;

	f = (lst->head)->num;
	s = (lst->head->next)->num;
	t = (lst->head->next->next)->num;
	if (ft_lstcnt(lst) == 3)
	{
		if (st)
			sort_a_onlythree(stack, f, s, t);
		else
			sort_b_onlythree(stack, f, s, t);
	}
	else
	{
		if (st)
			sort_a_notthree(stack, f, s, t);
		else
			sort_b_notthree(stack, f, s, t);
	}
}

