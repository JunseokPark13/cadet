/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 17:56:01 by jupark            #+#    #+#             */
/*   Updated: 2021/06/01 19:50:17 by jupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	A_to_B(t_stacks *stack, int size)
{
	
	t_node	*head;
	int		ra_cnt;
	int		rb_cnt;
	int		i;

	ra_cnt = 0;
	rb_cnt = 0;
	i = 0;
	//	ft_printlst_two(stack->lst_a, stack->lst_b);
//	printf("p1 = %d\np2 = %d\n\n", stack->p1, stack->p2);

	head = stack->lst_a->head;
	while (size--)
	{
		if (head->num >= stack->p2)
		{
			ft_ra(stack);
			ra_cnt++;
		}
		else
		{
			ft_pb(stack);
			if (stack->lst_b->head->num >= stack->p1)
			{
				ft_rb(stack);
				rb_cnt++;
			}
		}
		head = stack->lst_a->head;
	}
	printf("%d %d\n", ra_cnt, rb_cnt);
	while (i < ra_cnt && i++ < rb_cnt)
		ft_rrr(stack);
	ft_printlst_two(stack->lst_a, stack->lst_b);
}
