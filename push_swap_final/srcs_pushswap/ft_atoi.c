/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 16:53:00 by jupark            #+#    #+#             */
/*   Updated: 2021/06/08 12:24:29 by jupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_skipspace(const char *str)
{
	int		i;

	i = 0;
	while ((8 <= str[i] && str[i] <= 13) || str[i] == ' ')
		i++;
	return (i);
}

int			ft_atoi(const char *nptr, int *ary)
{
	long	sign;
	long	num;
	int		i;

	num = 0;
	sign = 1;
	i = ft_skipspace(nptr);
	if (nptr[i] == '-')
		sign = -1;
	if (nptr[i] == '-' || nptr[i] == '+')
		i++;
	if (!ft_isdigit(nptr[i]))
		ft_escape(ary);
	while (48 <= nptr[i] && nptr[i] <= 57)
	{
		num *= 10;
		num += nptr[i++] - 48;
		if ((num > 2147483647 && sign == 1) ||
				((num > 2147483648) && sign == -1))
			ft_escape(ary);
	}
	return ((num * sign));
}
