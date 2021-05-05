/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 13:26:01 by jupark            #+#    #+#             */
/*   Updated: 2021/05/05 10:48:11 by jupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*tmp_d;
	const unsigned char *tmp_s;

	if (!dst && !src)
	{
		return (0);
	}
	tmp_d = (unsigned char*)dst;
	tmp_s = (unsigned char*)src;
	while (n--)
	{
		*tmp_d++ = *tmp_s++;
	}
	return (dst);
}
