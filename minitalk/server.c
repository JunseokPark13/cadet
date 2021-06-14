/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 16:07:03 by jupark            #+#    #+#             */
/*   Updated: 2021/06/15 00:43:28 by jupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static void		handler(int signo, siginfo_t *sig)
{
	static int data;
	static int bit;

	if (!sig->si_pid || kill(sig->si_pid, signo))
		return ;
	if (signo == SIGUSR1)
		data |= (1 << bit);
	if (++bit == 8)
	{
		if (data)
			write(1, &data, 1);
		else
			write(1, "\n", 1);
		bit = 0;
		data = 0;
	}
}

static void		ft_putnbr(int n)
{
	char	c;

	c = n % 10 + '0';
	if (n >= 10)
		ft_putnbr(n / 10);
	write(1, &c, 1);
}

int main(void)
{
	struct sigaction	sigact;
	pid_t				s_pid;

	s_pid = getpid();
	write(1, "pid = ", 6);
	ft_putnbr(s_pid);
	write(1, "\n", 1);

	sigact.sa_flags = SA_SIGINFO;
	sigact.sa_sigaction = (void *)handler;
	sigemptyset(&sigact.sa_mask);
	sigaddset(&sigact.sa_mask, SIGUSR1);
	sigaddset(&sigact.sa_mask, SIGUSR2);
	if (sigaction(SIGUSR1, &sigact, NULL) || sigaction(SIGUSR2, &sigact, NULL))
	{
		printf("error\n");
		return (1);
	}
	while(1)
		pause();
}
