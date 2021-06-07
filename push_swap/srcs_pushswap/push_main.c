/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 16:03:12 by jupark            #+#    #+#             */
/*   Updated: 2021/06/07 20:29:50 by jupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int			check_duplicate(int *ary, int size)
{
	int		i;
	int		j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (ary[i] == ary[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static t_stacks		*create_stacks(int *ary, int size)
{
	t_list		*lst_a;
	t_list		*lst_b;
	int			index;

	lst_a = ft_lstnew();
	lst_b = ft_lstnew();
	index = 0;
	
	while (index < size)
	{
		ft_lstadd_front(lst_a, ft_nodenew(ary[index]));
		index++;
	}
	return (ft_stacknew(lst_a, lst_b));
}

int					main(int argc, char *argv[])
{
	int			*ary;
	int			len;
	t_stacks	*stack;

	ary = parse_argv(argc, argv, &len);
	if (check_duplicate(ary, len))
		ft_escape();
	stack = create_stacks(ary, len);
	if (!is_sorted(stack->lst_a, len, 1))
	{
		if (argc - 1 == 5)
			a_to_b_five(stack, len);
		else
			a_to_b(stack, len);
	}
	ft_stacksclear(stack);
	free(ary);
	return (0);
}
