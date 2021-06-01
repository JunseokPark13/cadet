/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_tool1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangcpar <sangcpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 04:19:59 by sangcpar          #+#    #+#             */
/*   Updated: 2021/05/28 04:20:01 by sangcpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int			sort(t_list **lst)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = *lst;
	while (tmp->next)
	{
		if (tmp->content > tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int			lst_size(t_list **lst)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = *lst;
	while (tmp->next)
	{
		tmp = tmp->next;
		i++;
	}
	i++;
	return (i);
}

void		ft_swap(int *a, int *b)
{
	int		tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void		list_free(t_list *lst)
{
	t_list	*tmp;

	while (lst)
	{
		tmp = lst;
		lst = lst->next;
		if (tmp)
			free(tmp);
	}
	lst = NULL;
}

void		add_stack(t_list **a, int n)
{
	t_list	*new;
	t_list	*tmp;

	tmp = *a;
	new = malloc(sizeof(t_list));
	new->content = n;
	new->next = NULL;
	if (*a)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	else
		*a = new;
}
