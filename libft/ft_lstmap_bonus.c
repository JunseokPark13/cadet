/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 14:17:43 by jupark            #+#    #+#             */
/*   Updated: 2021/05/06 15:11:49 by jupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*tmp_n;
	t_list	*next_n;

	new_lst = NULL;
	next_n = lst;
	while (next_n)
	{
		tmp_n = ft_lstnew(f(next_n->content));
		if (!tmp_n)
		{
			del(tmp_n->content);
			free(tmp_n);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, tmp_n);
		tmp_n = tmp_n->next;
		next_n = next_n->next;
	}
	return (new_lst);
}
