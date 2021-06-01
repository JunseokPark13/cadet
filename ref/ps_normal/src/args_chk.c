/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_chk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangcpar <sangcpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 19:53:45 by sangcpar          #+#    #+#             */
/*   Updated: 2021/06/01 12:03:40 by sangcpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int		check_arg(char *s, int i)
{
	int			len;

	while (s[i])
	{
		len = 0;
		if (((!ft_isdigit(s[i]) && (s[i] != '-' && s[i] != '+')) ||
				(s[i] == '-' && (!ft_isdigit(s[i + 1]))) || ((s[i] == '-'
				|| s[i] == '+') && (s[i + 1] == '+' || s[i + 1] == '-'))))
			return (0);
		while (ft_isdigit(s[i]))
		{
			len++;
			if (len == 10 && ((s[i] > '7' || ft_isdigit(s[i + 1])) &&
						s[i - len] != '-') && (ft_atoi(&s[(i - 9)]) == 0))
				return (0);
			if (len == 10 && ((s[i] > '8' || ft_isdigit(s[i + 1])) &&
						s[i - len] == '-') && (ft_atoi(&s[(i - len)]) == -1))
				return (0);
			i++;
		}
		if (((s[i] == ' ' || ((s[i] == '-') && ft_isdigit(s[i + 1])) ||
						((s[i] == '+') && ft_isdigit(s[i + 1]))) && s[i + 1]))
			i++;
	}
	return (1);
}

t_list			*fill_list(t_list *list, int ac, char **av)
{
	int			i;
	int			j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			add_stack(&list, ft_atoi(&av[i][j]));
			while (ft_isdigit(av[i][j]) || av[i][j] == '-' ||
					av[i][j] == '+')
				j++;
			if (av[i][j] == ' ')
				j++;
		}
		i++;
	}
	return (list);
}

t_list			*create_list(int ac, char **av)
{
	t_list		*list;
	int			i;

	i = 1;
	list = NULL;
	while (i < ac)
	{
		if (!(check_arg(av[i], 0)) || !av[1][0])
			return (0);
		i++;
	}
	list = fill_list(list, ac, av);
	return (list);
}
