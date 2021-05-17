/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 18:57:39 by jupark            #+#    #+#             */
/*   Updated: 2021/05/10 11:24:11 by jupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current_n;
	t_list	*next_n;

	if (!lst)
		return ;
	current_n = *lst;
	while (current_n)
	{
		next_n = current_n->next;
		ft_lstdelone(current_n, del);
		current_n = next_n;
	}
	*lst = NULL;
}
