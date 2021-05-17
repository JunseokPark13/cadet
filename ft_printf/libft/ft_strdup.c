/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 10:13:17 by jupark            #+#    #+#             */
/*   Updated: 2021/05/05 17:15:38 by jupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*tmp;
	size_t	s_len;
	size_t	i;

	s_len = ft_strlen(s1);
	tmp = (char*)malloc(sizeof(char) * (s_len + 1));
	if (!tmp)
		return (NULL);
	i = -1;
	while (++i < s_len)
		tmp[i] = s1[i];
	tmp[i] = '\0';
	return (tmp);
}
