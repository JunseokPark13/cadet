/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 16:33:50 by jupark            #+#    #+#             */
/*   Updated: 2021/05/05 16:37:54 by jupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstsize(t_list *lst)
{
	t_list	*next_n;
	int		cnt;

	cnt = 0;
	next_n = lst;
	while (next_n)
	{
		next_n = next_n->next;
		cnt++;
	}
	return (cnt);
}
