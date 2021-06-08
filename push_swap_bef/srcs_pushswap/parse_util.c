/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 16:03:12 by jupark            #+#    #+#             */
/*   Updated: 2021/06/08 15:33:35 by jupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			check_duplicate(int *ary, int size)
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

t_stacks		*create_stacks(int *ary, int size)
{
	t_list		*lst_a;
	t_list		*lst_b;
	int			index;

	lst_a = ft_lstnew();
	lst_b = ft_lstnew();
	index = 0;
	while (index < size)
		ft_lstadd_front(lst_a, ft_nodenew(ary[index++]));
	return (ft_stacknew(lst_a, lst_b));
}
