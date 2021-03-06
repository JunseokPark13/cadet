/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 16:07:03 by jupark            #+#    #+#             */
/*   Updated: 2021/06/15 15:30:20 by jupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static void		handler(int signo)
{
	static int data;
	static int bit;

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
	print_pid();
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (1)
		pause();
}
