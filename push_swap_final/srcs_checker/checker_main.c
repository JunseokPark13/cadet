/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 20:08:03 by jupark            #+#    #+#             */
/*   Updated: 2021/06/08 17:16:37 by jupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs_pushswap/push_swap.h"

void		read_command(t_stacks *stack)
{
	char	*cmd;
	char	tmp;
	int		cur;

	if (!(cmd = (char*)malloc(sizeof(char) * 4)))
		exit(0);
	cur = 0;
	while ((read(0, &tmp, 1)))
	{
		cmd[cur++] = tmp;
		if (tmp == '\0')
			break ;
		else if (tmp == '\n')
		{
			cmd[cur - 1] = '\0';
			do_command(stack, cmd);
			cur = 0;
		}
	}
	free(cmd);
}

void		checker(int *ary, int len)
{
	t_stacks	*stack;

	stack = create_stacks(ary, len);
	read_command(stack);
	check_issorted(stack);
	ft_stacksclear(stack);
}

int			main(int argc, char *argv[])
{
	int			*ary;
	int			len;

	if (argc == 1)
		exit(0);
	ary = parse_argv(argc, argv, &len);
	if (check_duplicate(ary, len))
		ft_escape(ary);
	checker(ary, len);
	free(ary);
}
