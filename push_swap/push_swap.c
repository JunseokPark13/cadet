/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 16:03:12 by jupark            #+#    #+#             */
/*   Updated: 2021/06/01 00:27:29 by jupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char* argv[])
{
	t_list *lst;
	t_list *lst2;
	t_node *tmp;

	lst = ft_lstnew();
	lst2 = ft_lstnew();

	if (argc <= 1)
		ft_putstr(NOTENOUGHARG);	
	for(int i = 1; i < argc; i++){
		printf("%d\n", ft_atoi(argv[i]));
		tmp = ft_nodenew(ft_atoi(argv[i]));
		ft_lstadd_front(lst, tmp);
	}

	tmp = ft_nodenew(10);
	ft_lstadd_front(lst2, tmp);
	tmp = ft_nodenew(15);
	ft_lstadd_front(lst2, tmp);
	tmp = ft_nodenew(20);
	ft_lstadd_front(lst2, tmp);
	

	printf("lst : \n");
	ft_printlst_front(lst);
	printf("\n");
	
	printf("lst2 : \n");
	ft_printlst_front(lst2);
	printf("\n");
	printf("\n");
	printf("\n");

	ft_push(lst, lst2);
	printf("lst : \n");
	ft_printlst_front(lst);
	printf("\n");
	printf("lst2 : \n");
	ft_printlst_front(lst2);
	printf("\n");

	return (0);
}
