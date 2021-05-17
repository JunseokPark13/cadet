/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 13:41:45 by jupark            #+#    #+#             */
/*   Updated: 2021/05/08 17:17:45 by jupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list *next_n;

	if (!lst || !f)
		return ;
	next_n = lst;
	while (next_n)
	{
		f(next_n->content);
		next_n = next_n->next;
	}
}
