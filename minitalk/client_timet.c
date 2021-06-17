/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 16:19:24 by jupark            #+#    #+#             */
/*   Updated: 2021/06/15 16:09:21 by jupark           ###   ########.fr       */
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

#include <time.h>
#include <sys/time.h>
#include <stdio.h>

int			main(int argc, char *argv[])
{
	struct timeval tv;
	pid_t	s_pid;
	int		i;

	gettimeofday(&tv, NULL);
	double start = (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000;
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
	gettimeofday(&tv, NULL);
	double end = (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000;
	printf("%.10f\n", (end - start) / 1000);
	return (1);
}
