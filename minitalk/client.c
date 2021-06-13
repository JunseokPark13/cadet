/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 16:19:24 by jupark            #+#    #+#             */
/*   Updated: 2021/06/13 17:18:56 by jupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	handler(int signo)
{
	(void)signo;
	printf("client handler\n");
}

int		main(int argc, char *argv[])
{
	pid_t	s_pid;
	
	if (argc != 3)
	{
		printf("Usage: %s pid string\n", argv[0]);
		return (1);
	}
	signal(SIGUSR1, handler);
	s_pid = atoi(argv[1]);
	printf("input pid = %d\n", (int)s_pid);
	printf("SIGUSER1 = %d\n", SIGUSR1);
	while (1)
	{
		printf("kill %d\n", kill(s_pid, SIGUSR1));
		sleep(1);
	}
	
}
