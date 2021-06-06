/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 18:50:05 by jupark            #+#    #+#             */
/*   Updated: 2021/06/04 19:08:46 by jupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tester(t_stacks *stack, char *str)
{
	static int cnt = 1;
	printf("command : %s\n", str);
	printf("cnt = %d\n", cnt++);
	if (str[0] == 's' && str[1] == 'a')
		ft_sa(stack);
	else if (str[0] == 's' && str[1] == 'b')
		ft_sb(stack);
	else if (str[0] == 's' && str[1] == 's')
		ft_ss(stack);
	else if (str[0] == 'r' && str[1] == 'a')
		ft_ra(stack);
	else if (str[0] == 'r' && str[1] == 'b')
		ft_rb(stack);
	else if (str[0] == 'r' && str[1] == 'r' && str[2] == '\0')
		ft_rr(stack);
	else if (str[0] == 'p' && str[1] == 'a')
		ft_pa(stack);
	else if (str[0] == 'p' && str[1] == 'b')
		ft_pb(stack);
	else if (str[0] == 'r' && str[1] == 'r' && str[2] == 'a')
		ft_rra(stack);
	else if (str[0] == 'r' && str[1] == 'r' && str[2] == 'b')
		ft_rrb(stack);
	else if (str[0] == 'r' && str[1] == 'r' && str[2] == 'r')
		ft_rrr(stack);
	ft_printlst_two(stack->lst_a, stack->lst_b);
	printf("\n");
}
