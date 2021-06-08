/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 13:44:06 by jupark            #+#    #+#             */
/*   Updated: 2021/06/08 15:16:34 by jupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs_pushswap/push_swap.h"
#include <stdio.h>

static void		cmd_escape(t_stacks *stack, char *cmd)
{
	ft_stacksclear(stack);
	free(cmd);
	ft_putstr(ERRMSG);
	exit(1);
}

void			do_command(t_stacks *stack, char *cmd)
{
	stack->isprint = 1;
	if (!ft_strncmp(cmd, "sa", ft_strlen(cmd)))
		ft_sa(stack);
	else if (!ft_strncmp(cmd, "sb", ft_strlen(cmd)))
		ft_sb(stack);
	else if (!ft_strncmp(cmd, "ss", ft_strlen(cmd)))
		ft_ss(stack, 1);
	else if (!ft_strncmp(cmd, "ra", ft_strlen(cmd)))
		ft_ra(stack);
	else if (!ft_strncmp(cmd, "rb", ft_strlen(cmd)))
		ft_rb(stack);
	else if (!ft_strncmp(cmd, "rr", ft_strlen(cmd)))
		ft_rr(stack, 1);
	else if (!ft_strncmp(cmd, "rra", ft_strlen(cmd)))
		ft_rra(stack);
	else if (!ft_strncmp(cmd, "rrb", ft_strlen(cmd)))
		ft_rrb(stack);
	else if (!ft_strncmp(cmd, "rrr", ft_strlen(cmd)))
		ft_rrr(stack, 1);
	else if (!ft_strncmp(cmd, "pa", ft_strlen(cmd)))
		ft_pa(stack);
	else if (!ft_strncmp(cmd, "pb", ft_strlen(cmd)))
		ft_pb(stack);
	else
		cmd_escape(stack, cmd);
}

void			check_issorted(t_stacks *stack)
{
	if (is_sorted(stack->lst_a, stack->lst_a->cnt, 1))
		ft_putstr("OK");
	else
		ft_putstr("KO");
}
