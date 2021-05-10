/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 16:14:13 by jupark            #+#    #+#             */
/*   Updated: 2021/05/08 11:11:29 by jupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*tmp_n;

	tmp_n = (t_list*)malloc(sizeof(t_list));
	if (!tmp_n)
		return (NULL);
	tmp_n->content = content;
	tmp_n->next = NULL;
	return (tmp_n);
}
