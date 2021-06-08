/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_three02.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 17:21:43 by jupark            #+#    #+#             */
/*   Updated: 2021/06/07 11:41:31 by jupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three_case_01(t_stacks *stack, int cs)
{
	if (cs == 1)
	{
		ft_ra(stack);
		ft_sa(stack);
		ft_rra(stack);
	}
	else if (cs == 2)
		ft_sa(stack);
	else if (cs == 3)
	{
		ft_sa(stack);
		ft_ra(stack);
		ft_sa(stack);
		ft_rra(stack);
	}
}

static void	sort_three_case_02(t_stacks *stack, int cs)
{
	if (cs == 4)
	{
		ft_ra(stack);
		ft_sa(stack);
		ft_rra(stack);
		ft_sa(stack);
	}
	else if (cs == 5)
	{
		ft_sa(stack);
		ft_ra(stack);
		ft_sa(stack);
		ft_rra(stack);
		ft_sa(stack);
	}
}

void		sort_a_notthree(t_stacks *stack, int a, int b, int c)
{
	int		cs;

	cs = cmp_three(a, b, c);
	if (cs == 1 || cs == 2 || cs == 3)
		sort_three_case_01(stack, cs);
	else
		sort_three_case_02(stack, cs);
}
