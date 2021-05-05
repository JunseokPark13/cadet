/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 11:14:49 by jupark            #+#    #+#             */
/*   Updated: 2021/05/05 17:17:59 by jupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tmp;
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	tmp = (char*)malloc(sizeof(char) * (s1_len + s2_len + 1));
	i = -1;
	while (++i < s1_len)
		tmp[i] = s1[i];
	i = -1;
	while (++i < s2_len)
		tmp[s1_len + i] = s2[i];
	tmp[s1_len + i] = '\0';
	return (tmp);
}
