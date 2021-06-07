/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 16:53:00 by jupark            #+#    #+#             */
/*   Updated: 2021/06/07 14:46:35 by jupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t		ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void		ft_putstr(char *str)
{
	size_t	len;

	len = ft_strlen(str);
	write(1, str, len);
	write(1, "\n", 1);
}

int			ft_isdigit(char c)
{
	if (48 <= c && c <= 57)
		return (1);
	else
		return (0);
}

static int	ft_skipspace(const char *str)
{
	int		i;

	i = 0;
	while ((8 <= str[i] && str[i] <= 13) || str[i] == ' ')
		i++;
	return (i);
}

int			ft_atoi(const char *nptr)
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
		ft_escape();
	while (48 <= nptr[i] && nptr[i] <= 57)
	{
		num *= 10;
		num += nptr[i++] - 48;
		if ((num > 2147483647 && sign == 1) ||
				((num > 2147483648) && sign == -1))
			ft_escape();
	}
	return ((num * sign));
}
