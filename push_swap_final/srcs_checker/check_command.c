/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 13:44:06 by jupark            #+#    #+#             */
/*   Updated: 2021/06/08 17:16:30 by jupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs_pushswap/push_swap.h"

static void		cmd_escape(t_stacks *stack, char *cmd)
{
	ft_stacksclear(stack);
	free(cmd);
	ft_putstr(ERRMSG);
	exit(0);
}

static void		cmd_lentwo(t_stacks *stack, char *cmd)
{
	if (!ft_strncmp(cmd, "sa", 2))
		ft_sa(stack);
	else if (!ft_strncmp(cmd, "sb", 2))
		ft_sb(stack);
	else if (!ft_strncmp(cmd, "ss", 2))
		ft_ss(stack, 1);
	else if (!ft_strncmp(cmd, "ra", 2))
		ft_ra(stack);
	else if (!ft_strncmp(cmd, "rb", 2))
		ft_rb(stack);
	else if (!ft_strncmp(cmd, "rr", 2))
		ft_rr(stack, 1);
	else if (!ft_strncmp(cmd, "pa", 2))
		ft_pa(stack);
	else if (!ft_strncmp(cmd, "pb", 2))
		ft_pb(stack);
	else
		cmd_escape(stack, cmd);
}

static void		cmd_lenthree(t_stacks *stack, char *cmd)
{
	if (!ft_strncmp(cmd, "rra", 3))
		ft_rra(stack);
	else if (!ft_strncmp(cmd, "rrb", 3))
		ft_rrb(stack);
	else if (!ft_strncmp(cmd, "rrr", 3))
		ft_rrr(stack, 1);
	else
		cmd_escape(stack, cmd);
}

void			do_command(t_stacks *stack, char *cmd)
{
	stack->isprint = 1;
	if (ft_strlen(cmd) == 2)
		cmd_lentwo(stack, cmd);
	else if (ft_strlen(cmd) == 3)
		cmd_lenthree(stack, cmd);
	else
		cmd_escape(stack, cmd);
}

void			check_issorted(t_stacks *stack)
{
	if (is_sorted(stack->lst_a, stack->lst_a->cnt, 1))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
}
