/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 17:55:45 by jupark            #+#    #+#             */
/*   Updated: 2021/05/04 19:55:58 by jupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t b_len;
	size_t l_len;
	size_t i;

	b_len = ft_strlen(big);
	l_len = ft_strlen(little);
	if (little[0] == '\0')
		return ((char*)big);
	if (b_len < l_len || len < l_len)
		return (0);
	i = 0;
	while (i < b_len && i < len)
	{
		if (big[i] == little[0] && i + l_len <= len)
			if (!ft_memcmp(big + i, little, l_len))
				return (char*)(big + i);
		i++;
	}
	return (0);
}
