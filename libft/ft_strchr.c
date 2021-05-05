/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 16:41:36 by jupark            #+#    #+#             */
/*   Updated: 2021/05/05 10:46:28 by jupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*tmp_s;
	char	val;
	size_t	len;
	size_t	i;

	tmp_s = (char*)s;
	val = (char)c;
	len = ft_strlen(s);
	i = 0;
	while (i <= len)
	{
		if (tmp_s[i] == val)
			return (tmp_s + i);
		i++;
	}
	return (0);
}
