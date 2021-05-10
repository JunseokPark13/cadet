/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 16:52:58 by jupark            #+#    #+#             */
/*   Updated: 2021/05/10 11:34:29 by jupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*tmp_s;
	unsigned char		ch;
	size_t				i;

	i = 0;
	tmp_s = (unsigned char*)s;
	ch = (unsigned char)c;
	while (i < n)
	{
		if (tmp_s[i] == ch)
			return ((void*)&tmp_s[i]);
		i++;
	}
	return (0);
}
