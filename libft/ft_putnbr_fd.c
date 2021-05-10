/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 16:09:12 by jupark            #+#    #+#             */
/*   Updated: 2021/05/10 11:38:14 by jupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	write_num(int n, int fd)
{
	char c;

	if (n != 0)
	{
		c = n % 10 + 48;
		n /= 10;
		write_num(n, fd);
		write(fd, &c, 1);
	}
}

void		ft_putnbr_fd(int n, int fd)
{
	char c;

	if (fd < 0)
		return ;
	if (n == 0)
		write(fd, "0", 1);
	if (n < 0)
	{
		write(fd, "-", 1);
		c = ((n % 10) * -1) + 48;
		n /= 10;
		n *= -1;
		write_num(n, fd);
		write(fd, &c, 1);
	}
	else
		write_num(n, fd);
}
