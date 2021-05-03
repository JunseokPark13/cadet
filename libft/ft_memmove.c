/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 15:38:08 by jupark            #+#    #+#             */
/*   Updated: 2021/05/03 16:08:21 by jupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *tmp_d;
	const unsigned char *tmp_s;
	unsigned char for_move[len];

	if (!dst && !src)
	{
		return (0);
	}
	tmp_d = (unsigned char*)dst;
	tmp_s = (unsigned char*)src;
	
	ft_memcpy(for_move, tmp_s, len);
	ft_memcpy(tmp_d, for_move, len);
	return (dst);
}
