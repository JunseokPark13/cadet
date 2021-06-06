/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 16:03:12 by jupark            #+#    #+#             */
/*   Updated: 2021/06/06 21:32:49 by jupark           ###   ########.fr       */
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
	t_list		*lst_a;
	t_list		*lst_b;
	t_node		*tmp;
	t_stacks	*stack;

	lst_a = ft_lstnew();
	lst_b = ft_lstnew();
	if (argc <= 1)
		ft_putstr(NOTENOUGHARG);	
	for(int i = 1; i < argc; i++){
		tmp = ft_nodenew(atoi(argv[i]));
		ft_lstadd_front(lst_a, tmp);
	}
	stack = ft_stacknew(lst_a, lst_b);

	//printf("Start : \n"); ft_printlst_two(stack->lst_a, stack->lst_b);
/*
	char k[4];
	while (1)
	{
		scanf("%s", k);
		tester(stack, k);
	}
*/
	if (argc - 1 == 5)
		a_to_b_five(stack, argc - 1);
	else
		a_to_b(stack, argc - 1);

	ft_stacksclear(stack);
	//system("leaks push_swap");
	// printf("\nEnd : \n"); ft_printlst_two(stack->lst_a, stack->lst_b);

	return (0);
}
