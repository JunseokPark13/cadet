/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_num.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangcpar <sangcpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 04:22:10 by sangcpar          #+#    #+#             */
/*   Updated: 2021/06/01 12:10:25 by sangcpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int			find_min(t_list *list)
{
	int		min;

	min = 2147483647;
	while (list->next)
	{
		if (list->content < min)
			min = list->content;
		list = list->next;
	}
	if (list->content < min)
		min = list->content;
	return (min);
}

int			find_mid(t_list **a, int size)
{
	int		*tmp;
	t_list	*temp;
	int		i;
	int		j;

	tmp = malloc(sizeof(int) * size);
	i = 0;
	temp = *a;
	while (i < size)
	{
		tmp[i] = temp->content;
		temp = temp->next;
		i++;
	}
	i = -1;
	while (++i < size - 1)
	{
		j = -1;
		while (++j < size - 1 - i)
			if (tmp[j] > tmp[j + 1])
				ft_swap(&tmp[j], &tmp[j + 1]);
	}
	i = tmp[size / 2];
	free(tmp);
	return (i);
}

int			find_max(t_list **lst)
{
	int		max;
	t_list	*b;

	max = -2147483648;
	b = *lst;
	while (b->next)
	{
		if (b->content > max)
			max = b->content;
		b = b->next;
	}
	if (b->content > max)
		max = b->content;
	return (max);
}

int			find_pos(t_list **lst, int n)
{
	int		i;
	t_list	*b;

	i = 0;
	b = *lst;
	while (b->next)
	{
		if (b->content == n)
			return (i);
		i++;
		b = b->next;
	}
	if (b->content == n)
		return (i);
	return (-1);
}

int			num_chk(t_list **a)
{
	int		temp;
	t_list	*tmp1;
	t_list	*tmp2;
	int		i;

	tmp1 = *a;
	while (tmp1->next)
	{
		temp = tmp1->content;
		tmp2 = *a;
		i = 0;
		while (tmp2->next)
		{
			if (temp == tmp2->content)
				i++;
			tmp2 = tmp2->next;
		}
		if (temp == tmp2->content)
			i++;
		if (i > 1)
			return (1);
		tmp1 = tmp1->next;
	}
	return (0);
}
