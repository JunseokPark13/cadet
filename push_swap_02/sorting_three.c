/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 17:21:43 by jupark            #+#    #+#             */
/*   Updated: 2021/06/04 19:30:10 by jupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_a_onlythree(t_stacks *stack, t_node *a, t_node *b, t_node *c)
{
	int		cs;

	cs = cmp_three(a->num, b->num, c->num);
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

static void	sort_b_onlythree(t_stacks *stack, t_node *a, t_node *b, t_node *c)
{
	int		cs;
	cs = cmp_three(a->num, b->num, c->num);
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
	t_node	*f;
	t_node	*s;
	t_node	*t;

	f = lst->head;
	s = f->next;
	t = s->next;
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

