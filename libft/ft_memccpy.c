/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 14:19:16 by jupark            #+#    #+#             */
/*   Updated: 2021/05/10 11:33:58 by jupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned char		*tmp_d;
	const unsigned char	*tmp_s;
	unsigned char		ch;

	tmp_d = (unsigned char*)dst;
	tmp_s = (unsigned char*)src;
	ch = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		tmp_d[i] = tmp_s[i];
		if (tmp_s[i] == ch)
			return (dst + i + 1);
		i++;
	}
	return (0);
}
