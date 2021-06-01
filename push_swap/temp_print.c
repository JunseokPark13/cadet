/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 11:25:14 by jupark            #+#    #+#             */
/*   Updated: 2021/06/01 12:02:12 by jupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_printlst_front(t_list *lst)
{
	t_node	*head;
	int		k;

	k = 0;
	head = lst->head;
	while(1)
	{
		if(k > 0 && head == lst->head)
			break;
		printf("%d :	%d\n", k++, head->num);
		head = head->next;
	}
	printf("cnt = %d\n\n", lst->cnt);
}

void	ft_printlst_two(t_list *lst1, t_list *lst2)
{
	t_node	*head_1;
	t_node	*head_2;
	int		k;

	k = 0;
	head_1 = lst1->head;
	head_2 = lst2->head;
	k = lst1->cnt > lst2->cnt ? lst1->cnt : lst2->cnt;
	while(k)
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
