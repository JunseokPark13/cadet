/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 16:41:36 by jupark            #+#    #+#             */
/*   Updated: 2021/05/05 10:48:30 by jupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*tmp_s;
	char	val;
	size_t	len;

	tmp_s = (char*)s;
	val = (char)c;
	len = ft_strlen(s);
	while (len > 0)
	{
		if (tmp_s[len] == val)
			return (tmp_s + len);
		len--;
	}
	if (tmp_s[0] == val)
		return (tmp_s);
	return (0);
}
