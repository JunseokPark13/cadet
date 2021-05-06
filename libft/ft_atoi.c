/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 20:25:25 by jupark            #+#    #+#             */
/*   Updated: 2021/05/06 18:12:12 by jupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_skipspace(const char *str)
{
	int		i;

	i = 0;
	while ((8 <= str[i] && str[i] <= 13) || str[i] == ' ')
		i++;
	return (i);
}

int		ft_atoi(const char *nptr)
{
	long				sign;
	long				num;
	int					i;
	
	num = 0;
	sign = 1;
	i = ft_skipspace(nptr);
	if (nptr[i] == '-')
		sign = -1;
	if (nptr[i] == '-' || nptr[i] == '+')
		i++;
	while (48 <= nptr[i] && nptr[i] <= 57)
	{
		num *= 10;
		num += nptr[i++] - 48;
		if (num > 2147483647 && sign == 1)
			return (-1);
		if (num > 2147483648 && sign == -1)
			return (0);
	}
	return ((num * sign));
}
