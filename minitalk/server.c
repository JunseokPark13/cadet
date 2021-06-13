/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 16:07:03 by jupark            #+#    #+#             */
/*   Updated: 2021/06/13 17:18:42 by jupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	handler(int signo)
{
	(void)signo;
	printf("what?\n");
}

int main(void)
{
	 pid_t	s_pid;

	 s_pid = getgid();
	printf("pid = %d\n", getpid());
	printf("s_pid = %d\n", s_pid);
//	signal(SIGUSR1, handler);
	while(1)
	{
		pause();
//		printf("YES!\n");
//		sleep(1);
	}

}
