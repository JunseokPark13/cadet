/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 16:07:03 by jupark            #+#    #+#             */
/*   Updated: 2021/06/15 14:25:40 by jupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server_bonus.h"

static void		handler(int signo, siginfo_t *sig, void *context)
{
	static int data;
	static int bit;

	(void)context;
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

void			print_pid(void)
{
	ft_putstr("server pid = ");
	ft_putnbr(getpid());
	ft_putstr("\n");
}

int				main(void)
{
	struct sigaction	sigact;

	print_pid();
	sigact.sa_flags = SA_SIGINFO;
	sigact.sa_sigaction = &handler;
	if (sigaction(SIGUSR1, &sigact, NULL) || sigaction(SIGUSR2, &sigact, NULL))
	{
		ft_putstr("sigaction error\n");
		return (1);
	}
	while (1)
		pause();
}
