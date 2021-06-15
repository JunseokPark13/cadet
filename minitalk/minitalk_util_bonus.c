/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_util_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 23:50:23 by jupark            #+#    #+#             */
/*   Updated: 2021/06/15 15:44:52 by jupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server_bonus.h"
#include "client_bonus.h"

void		ft_putnbr(int num)
{
	char	c;

	c = num % 10 + 48;
	if (num >= 10)
		ft_putnbr(num / 10);
	write(1, &c, 1);
}

static int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void		ft_putstr(char *str)
{
	int	len;

	len = ft_strlen(str);
	write(1, str, len);
}

int			parse_pidnum(char *nstr)
{
	int	num;
	int	nlen;
	int i;

	num = 0;
	nlen = ft_strlen(nstr);
	i = 0;
	if (nstr[0] < 48 || nstr[0] > 57)
	{
		ft_putstr("pid is inappropriate!\n");
		exit(1);
	}
	while (i < nlen)
	{
		num *= 10;
		num += nstr[i++] - '0';
	}
	return (num);
}
