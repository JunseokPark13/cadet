/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 18:06:37 by jupark            #+#    #+#             */
/*   Updated: 2021/06/07 11:32:33 by jupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_optimize(t_stacks *stack, int size, int st)
{
	if (st)
	{
		if (is_sorted(stack->lst_a, size, 1))
			return ;
		if (size == 2)
			sort_two(stack, stack->lst_a, 1);
		else if (size == 3)
			sort_three(stack, stack->lst_a, 1);
		return ;
	}
	else
	{
		if (!is_sorted(stack->lst_b, size, 0))
		{
			if (size == 2)
				sort_two(stack, stack->lst_b, 0);
			else if (size == 3)
				sort_three(stack, stack->lst_b, 0);
		}
		while (size--)
			ft_pa(stack);
		return ;
	}
}
