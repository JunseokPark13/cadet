/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 16:03:12 by jupark            #+#    #+#             */
/*   Updated: 2021/05/31 18:48:18 by jupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char* argv[])
{
	t_list *lst;
	t_node *tmp;

	lst = ft_lstnew();

	if (argc <= 1)
		ft_putstr(NOTENOUGHARG);	
	for(int i = 1; i < argc; i++){
		printf("%d\n", ft_atoi(argv[i]));
		tmp = ft_nodenew(ft_atoi(argv[i]));
		ft_lstadd_front(lst, tmp);
	}

	ft_printlst_front(lst);
	printf("\n");
	ft_printlst_back(lst);
	return (0);
}
