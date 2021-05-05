/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 20:25:25 by jupark            #+#    #+#             */
/*   Updated: 2021/05/05 10:45:14 by jupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_skipspace(const unsigned char *str)
{
	int		i;

	i = 0;
	while ((8 <= str[i] && str[i] <= 13) || str[i] == ' ')
		i++;
	return (i);
}

int		ft_atoi(const char *nptr)
{
	int					sign;
	int					num;
	int					i;
	const unsigned char *tmp;

	tmp = (unsigned char *)nptr;
	num = 0;
	sign = 1;
	i = ft_skipspace(tmp);
	if (tmp[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (tmp[i] == '+')
		i++;
	while (48 <= tmp[i] && tmp[i] <= 57)
	{
		num *= 10;
		num += tmp[i++] - 48;
	}
	return (num * sign);
}
