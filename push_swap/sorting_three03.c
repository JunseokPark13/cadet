/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_three03.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 17:21:43 by jupark            #+#    #+#             */
/*   Updated: 2021/06/03 19:54:58 by jupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three_case_01(t_stacks *stack, int cs)
{
	if (cs == 1)
	{
		ft_sb(stack);
		ft_rb(stack);
		ft_sb(stack);
		ft_rrb(stack);
	}
	else if (cs == 2)
	{
		ft_rb(stack);
		ft_sb(stack);
		ft_rrb(stack);
		ft_sb(stack);
	}
	else if (cs == 3)
	{
		ft_rb(stack);
		ft_sb(stack);
		ft_rrb(stack);
	}
}

static void	sort_three_case_02(t_stacks *stack, int cs)
{
	if (cs == 4)
		ft_sb(stack);
	else if (cs == 6)
	{
		ft_sb(stack);
		ft_rb(stack);
		ft_sb(stack);
		ft_rrb(stack);
		ft_sb(stack);
	}
}

void		sort_b_notthree(t_stacks *stack, t_node *a, t_node *b, t_node *c)
{
	int		cs;
	
	cs = cmp_three(a->num, b->num, c->num);
	if (cs == 1 || cs == 2 || cs == 3)
		sort_three_case_01(stack, cs);
	else
		sort_three_case_02(stack, cs);
}
