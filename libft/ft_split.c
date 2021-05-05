/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 13:32:00 by jupark            #+#    #+#             */
/*   Updated: 2021/05/05 18:53:27 by jupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_countword(char const *s, char c)
{
	int		i;
	int		flag;
	int		cnt;

	cnt = 0;
	i = -1;
	flag = 1;
	while (s[++i])
	{
		if (flag && s[i] != c)
		{
			i++;
			cnt++;
			while (s[i] != c && s[i] != '\0')
				i++;
			flag = 0;
		}
		if (s[i] == c)
			flag = 1;
	}
	return (cnt);
}

char	*ft_seperate(char const *s, char c, int pos)
{
	int		cur;

	cur = pos++;
	while (s[pos] != c && s[pos] != '\0')
		pos++;
	return (ft_substr(s, cur, pos - cur));
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		flag;
	char	**tmp;

	if (!(tmp = (char**)malloc(sizeof(char*) * (ft_countword(s, c) + 1))))
		return (NULL);
	i = 0;
	j = -1;
	flag = 1;
	while (s[++j])
	{
		if (flag && s[j] != c)
		{
			tmp[i++] = ft_seperate(s, c, j);
			flag = 0;
		}
		if (s[j] == c)
			flag = 1;
	}
	tmp[i] = NULL;
	return (tmp);
}
