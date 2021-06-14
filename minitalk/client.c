/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 16:19:24 by jupark            #+#    #+#             */
/*   Updated: 2021/06/15 00:43:06 by jupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int			g_check;

int			send_signal(pid_t s_pid, char c)
{
	int		bit;
	int		wait;
	int		retry;

	bit = 0;
	retry = 0;
	while (retry++ < 10)
	{
		wait = 0;
		g_check = 0;	
		if (c & (1 << bit))
			kill(s_pid, SIGUSR1);
		else
			kill(s_pid, SIGUSR2);
		while (wait++ < 100)
		{
			if (g_check)
			{
				bit++;
				retry = 0;
				break;
			}
			usleep(1);
		}
		if (bit == 8)
			return (1);
	}
	return (0);
}

void	sig_handler(int signo)
{
	(void)signo;
	g_check = 1;
}

int		main(int argc, char *argv[])
{
	pid_t	s_pid;
	int		i;
	
	if (argc != 3)
	{
		write(1, "Not enough argument!\n", 21);
		return (1);
	}
	signal(SIGUSR1, sig_handler);
	signal(SIGUSR2, sig_handler);
	s_pid = atoi(argv[1]);
	i = 0;
	while (1)
	{
		if (!send_signal(s_pid, argv[2][i]))
		{
			send_signal(s_pid, '\0');
			write(1, "There is some Error\n", 20);
			break;
		}
		if (argv[2][i++] == '\0')
			break;
	}
	return (1);
}
