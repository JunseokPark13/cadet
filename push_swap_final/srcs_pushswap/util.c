/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 16:53:00 by jupark            #+#    #+#             */
/*   Updated: 2021/06/08 15:53:47 by jupark           ###   ########.fr       */
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
}

int			ft_isdigit(char c)
{
	if (48 <= c && c <= 57)
		return (1);
	else
		return (0);
}

void		ft_escape(int *ary)
{
	free(ary);
	write(2, ERRMSG, 6);
	exit(1);
}
