/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangcpar <sangcpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 12:28:00 by sangcpar          #+#    #+#             */
/*   Updated: 2021/06/01 13:47:56 by jupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int				err_free(t_list *list, t_info *info)
{
	if (list)
		list_free(list);
	free(info);
	write(2, "Error\n", 6);
	return (0);
}

static int		split(char *line, t_list **a, t_list **b)
{
	if (!(ft_strcmp(line, "ra")))
		ra(a, 1);
	else if (!(ft_strcmp(line, "rb")))
		rb(b, 1);
	else if (!(ft_strcmp(line, "rr")))
		rr(a, b, 1);
	else if (!(ft_strcmp(line, "sa")))
		sa(a, 1);
	else if (!(ft_strcmp(line, "sb")))
		sb(b, 1);
	else if (!(ft_strcmp(line, "ss")))
		ss(a, b, 1);
	else if (!(ft_strcmp(line, "rra")))
		rra(a, 1);
	else if (!(ft_strcmp(line, "rrb")))
		rrb(b, 1);
	else if (!(ft_strcmp(line, "rrr")))
		rrr(a, b, 1);
	else if (!(ft_strcmp(line, "pa")))
		pa(a, b, 1);
	else if (!(ft_strcmp(line, "pb")))
		pb(a, b, 1);
	else
		return (0);
	return (1);
}

int				checker(t_list **a, t_list **b)
{
	int			ret;
	t_list		*tmp;
	char		*line;

	tmp = *a;
	tmp = *b;
	while ((ret = get_next_line(0, &line)) > 0)
	{
		if (ret == -1)
		{
			free(line);
			return (0);
		}
		if (!(split(line, a, b)))
		{
			free(line);
			return (0);
		}
		free(line);
	}
	return (1);
}

void			free_ab(t_list **a, t_list **b)
{
	if (*b)
		list_free(*b);
	if (*a)
		list_free(*a);
}

int				main(int ac, char **av)
{
	int			ret;
	t_info		*info;
	t_list		*a;
	t_list		*b;

	if (ac < 2)
		return (0);
	b = NULL;
	ret = 1;
	if (!(info = malloc(sizeof(t_info))))
		return (0);
	if (!(a = create_list(ac, av)))
		return (err_free(a, info));
	if (num_chk(&a) == 1)
		return (err_free(a, info));
	if ((ret = checker(&a, &b)) == 0)
		return (err_free(a, info));
	if (a && sort(&a) && !b)
		write(1, "OK\n", 3);
	else
		write(2, "KO\n", 3);
	free_ab(&a, &b);
	free(info);
	return (0);
}
