/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 16:03:12 by jupark            #+#    #+#             */
/*   Updated: 2021/06/08 15:40:33 by jupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int					main(int argc, char *argv[])
{
	int			*ary;
	int			len;
	t_stacks	*stack;

	ary = parse_argv(argc, argv, &len);
	if (check_duplicate(ary, len))
		ft_escape(ary);
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
