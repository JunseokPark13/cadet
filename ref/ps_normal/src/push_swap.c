/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangcpar <sangcpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 04:01:40 by sangcpar          #+#    #+#             */
/*   Updated: 2021/06/01 13:47:20 by jupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int			main(int ac, char **av)
{
	t_list	*a;

	if (ac < 2)
		return (0);
	if (!(a = create_list(ac, av)))
	{
		if (a)
			list_free(a);
		put_msg("Error\n");
		return (0);
	}
	if (num_chk(&a) == 1)
	{
		list_free(a);
		put_msg("Error\n");
		return (0);
	}
	if (lst_size(&a) > 7)
		resolve(&a);
	else
		short_resolve(&a);
}
