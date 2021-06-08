/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 18:50:05 by jupark            #+#    #+#             */
/*   Updated: 2021/06/08 15:04:52 by jupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	tester(t_stacks *stack, char *str)
{
	static int cnt = 1;

	printf("command : %s\ncnt = %d\n", str, cnt++);
	if (str[0] == 's' && str[1] == 'a')
		ft_sa(stack);
	else if (str[0] == 's' && str[1] == 'b')
		ft_sb(stack);
	else if (str[0] == 's' && str[1] == 's')
		ft_ss(stack, 0);
	else if (str[0] == 'r' && str[1] == 'a')
		ft_ra(stack);
	else if (str[0] == 'r' && str[1] == 'b')
		ft_rb(stack);
	else if (str[0] == 'r' && str[1] == 'r' && str[2] == '\0')
		ft_rr(stack, 0);
	else if (str[0] == 'p' && str[1] == 'a')
		ft_pa(stack);
	else if (str[0] == 'p' && str[1] == 'b')
		ft_pb(stack);
	else if (str[0] == 'r' && str[1] == 'r' && str[2] == 'a')
		ft_rra(stack);
	else if (str[0] == 'r' && str[1] == 'r' && str[2] == 'b')
		ft_rrb(stack);
	else if (str[0] == 'r' && str[1] == 'r' && str[2] == 'r')
		ft_rrr(stack, 0);
	ft_printlst_two(stack->lst_a, stack->lst_b);
}
