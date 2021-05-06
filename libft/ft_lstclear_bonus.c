/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 18:57:39 by jupark            #+#    #+#             */
/*   Updated: 2021/05/06 15:15:59 by jupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current_n;
	t_list	*next_n;

	if (del)
	{
		current_n = *lst;
		while (current_n)
		{
			next_n = current_n->next;
			del(current_n->content);
			free(current_n);
			current_n = next_n;
		}
		*lst = NULL;
	}
}
