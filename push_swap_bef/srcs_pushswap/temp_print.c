/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 11:25:14 by jupark            #+#    #+#             */
/*   Updated: 2021/06/07 14:48:43 by jupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

void	ft_printlst_two(t_list *lst1, t_list *lst2)
{
	t_node	*head_1;
	t_node	*head_2;
	int		k;

	k = 0;
	head_1 = lst1->head;
	head_2 = lst2->head;
	k = lst1->cnt > lst2->cnt ? lst1->cnt : lst2->cnt;
	while (k)
	{
		if (k <= lst1->cnt && k <= lst2->cnt)
		{
			printf("%d : 	%d		%d\n", k, head_1->num, head_2->num);
			head_1 = head_1->next;
			head_2 = head_2->next;
		}
		else if (k <= lst1->cnt)
		{
			printf("%d :	%d		  \n", k, head_1->num);
			head_1 = head_1->next;
		}
		else if (k <= lst2->cnt)
		{
			printf("%d :			%d\n", k, head_2->num);
			head_2 = head_2->next;
		}
		k--;
	}
	printf("cnt:	%d		%d\n\n", lst1->cnt, lst2->cnt);
}
