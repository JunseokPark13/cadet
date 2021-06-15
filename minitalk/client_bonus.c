/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 16:19:24 by jupark            #+#    #+#             */
/*   Updated: 2021/06/15 16:14:20 by jupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client_bonus.h"

int			g_check;

void		wait_sequence(int *bit, int *retry)
{
	int	wait;

	wait = 0;
	while (wait++ < 100)
	{
		if (g_check)
		{
			*bit += 1;
			*retry = 0;
			break ;
		}
		usleep(1);
	}
}

int			send_signal(pid_t s_pid, char c)
{
	int		bit;
	int		retry;

	bit = 0;
	retry = 0;
	while (retry++ < 10)
	{
		g_check = 0;
		if (c & (1 << bit))
			kill(s_pid, SIGUSR1);
		else
			kill(s_pid, SIGUSR2);
		wait_sequence(&bit, &retry);
		if (bit == 8)
			return (1);
	}
	return (0);
}

void		sig_handler(int signo)
{
	(void)signo;
	g_check = 1;
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
	signal(SIGUSR1, sig_handler);
	signal(SIGUSR2, sig_handler);
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
