/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 15:38:08 by jupark            #+#    #+#             */
/*   Updated: 2021/05/06 18:03:56 by jupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*tmp_d;
	const unsigned char	*tmp_s;

	if (!dst && !src)
		return (NULL);
	tmp_d = (unsigned char*)dst;
	tmp_s = (unsigned char*)src;
	if (dst < src)
		while (len--)
			*tmp_d++ = *tmp_s++;
	else
		while (len--)
			*(tmp_d + len) = *(tmp_s + len);
	return (dst);
}
