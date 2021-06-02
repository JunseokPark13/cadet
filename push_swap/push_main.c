/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 16:03:12 by jupark            #+#    #+#             */
/*   Updated: 2021/06/02 19:14:34 by jupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <limits.h>

void	print_ary(int *ary, int size)
{
	for(int i = 0; i < size; i++)
		printf("%d ", ary[i]);
	printf("\n");
}

int main(int argc, char* argv[])
{
//	int			ary[argc - 1];
	t_list		*lst;
	t_list		*lst2;
	t_node		*tmp;
	t_stacks	*stack;

	lst = ft_lstnew();
	lst2 = ft_lstnew();

	if (argc <= 1)
		ft_putstr(NOTENOUGHARG);	
	for(int i = 1; i < argc; i++){
//		ary[i - 1] = ft_atoi(argv[i]);
		tmp = ft_nodenew(ft_atoi(argv[i]));
		ft_lstadd_front(lst, tmp);
	}
	/*
	ft_get_pivot(ary, argc - 1, &pivot1, &pivot2);
	print_ary(ary, argc - 1);
	printf("pivot1 : %d\npivot2 : %d\n", pivot1, pivot2);
	*/
	stack = (t_stacks*)malloc(sizeof(t_stacks));
	stack->lst_a = lst;
	stack->lst_b = lst2;
	ft_printlst_two(stack->lst_a, stack->lst_b);
	//get_pivot_from_lst(stack, lst, argc - 1);

	ft_pb(stack);
	ft_pb(stack);
	ft_pb(stack);
	ft_pb(stack);
	ft_pa(stack);
	//a_to_b(stack, argc - 1);

	ft_printlst_two(stack->lst_a, stack->lst_b);
	//printf("pivot1 : %d\npivot2 : %d\n", stack->p1, stack->p2);

	return (0);
}
