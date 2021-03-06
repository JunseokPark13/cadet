/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 16:19:24 by jupark            #+#    #+#             */
/*   Updated: 2021/06/15 16:13:36 by jupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int			send_signal(pid_t s_pid, char c)
{
	int		bit;

	bit = 0;
	while (bit < 8)
	{
		if (c & (1 << bit))
			kill(s_pid, SIGUSR1);
		else
			kill(s_pid, SIGUSR2);
		bit++;
		usleep(100);
		if (bit == 8)
			return (1);
	}
	return (0);
}

int			main(int argc, char *argv[])
{
	pid_t	s_pid;
	int		i;

	if (argc != 3)
	{
		ft_putstr("Not enough argument!\n");
		return (1);
	}
	s_pid = parse_pidnum(argv[1]);
	i = 0;
	while (1)
	{
		if (!send_signal(s_pid, argv[2][i]))
		{
			send_signal(s_pid, '\0');
			ft_putstr("There is some Error\n");
			break ;
		}
		if (argv[2][i++] == '\0')
			break ;
	}
	return (1);
}
