/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 16:03:12 by jupark            #+#    #+#             */
/*   Updated: 2021/06/01 19:29:16 by jupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <limits.h>

int main(int argc, char* argv[])
{
	int			ary[argc - 1];
	int			pivot1;
	int			pivot2;
	t_list		*lst;
	t_list		*lst2;
	t_node		*tmp;
	t_stacks	*stack;

	lst = ft_lstnew();
	lst2 = ft_lstnew();

	if (argc <= 1)
		ft_putstr(NOTENOUGHARG);	
	for(int i = 1; i < argc; i++){
		ary[i - 1] = ft_atoi(argv[i]);
		tmp = ft_nodenew(ft_atoi(argv[i]));
		ft_lstadd_front(lst, tmp);
	}
	ft_get_pivot(ary, argc - 1, &pivot1, &pivot2);
//	printf("pivot1 : %d\npivot2 : %d\n", pivot1, pivot2);
	stack = (t_stacks*)malloc(sizeof(t_stacks));
	stack->lst_a = lst;
	stack->lst_b = lst2;
	stack->p1 = pivot1;
	stack->p2 = pivot2;

	A_to_B(stack, argc - 1);

	return (0);
}
