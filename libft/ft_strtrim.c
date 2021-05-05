/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 11:30:12 by jupark            #+#    #+#             */
/*   Updated: 2021/05/05 12:25:47 by jupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcheck(char const *s1, char const *set, int dir)
{
	size_t s1_len;
	size_t i;
	size_t output;

	s1_len = ft_strlen(s1);
	i = -1;
	if (!dir)
	{
		while (++i < s1_len)
			if (!ft_strchr(set, s1[i]))
				break ;
		output = i;
	}
	else
	{
		while (++i < s1_len)
			if (!ft_strchr(set, s1[s1_len - i - 1]))
				break ;
		output = s1_len - i;
	}
	return (output);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*tmp;
	int		side[2];

	if (!set)
		return (ft_strdup(s1));
	if (!s1)
		return (NULL);
	side[0] = ft_strcheck(s1, set, 0);
	side[1] = ft_strcheck(s1, set, 1);
	if (side[0] >= side[1])
		return (ft_strdup(""));
	tmp = (char*)malloc(sizeof(char) * (side[1] - side[0] + 1));
	if (!tmp)
		return (NULL);
	ft_strlcpy(tmp, (char*)(s1 + side[0]), side[1] - side[0] + 1);
	return (tmp);
}
