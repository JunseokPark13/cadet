/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_two.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 17:21:43 by jupark            #+#    #+#             */
/*   Updated: 2021/06/06 22:42:08 by jupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		sort_two(t_stacks *stack, t_list *lst, int st)
{
	t_node	*first;
	t_node	*second;

	first = lst->head;
	second = first->next;
	if (st && first->num > second->num)
		ft_sa(stack);
	else if (!st && first->num < second->num)
		ft_sb(stack);
}
