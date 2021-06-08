/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 16:41:36 by jupark            #+#    #+#             */
/*   Updated: 2021/06/07 19:15:26 by jupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_strchr(const char *s, char c)
{
	char			*tmp_s;
	unsigned char	val;
	size_t			len;
	size_t			i;
	
	tmp_s = (char*)s;
	val = (unsigned char)c;
	len = ft_strlen((char*)s);
	i = 0;
	while (i <= len)
	{
		if (tmp_s[i] == val)
			return (1);
		i++;
	}
	return (0);
}

int		ft_onlychr(const char *s, char c)
{
	char			*tmp_s;
	unsigned char	val;
	size_t			len;
	size_t			i;

	tmp_s = (char*)s;
	val = (unsigned char)c;
	len = ft_strlen((char*)s);
	i = -1;
	while (++i < len)
	{
		if (tmp_s[i] != val)
			return (0);
	}
	return (1);
}
