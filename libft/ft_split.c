/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 13:32:00 by jupark            #+#    #+#             */
/*   Updated: 2021/05/06 14:14:42 by jupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_countword(char const *s, char c)
{
	int		i;
	int		flag;
	int		cnt;

	cnt = 0;
	i = 0;
	flag = 1;
	while (s[i])
	{
		if (flag && s[i++] != c)
		{
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

char		*ft_sep(char const *s, char c, int pos)
{
	int		cur;
	int		i;
	char	*tmp;

	cur = pos++;
	while (s[pos] != c && s[pos] != '\0')
		pos++;
	tmp = (char*)malloc(sizeof(char) * (pos - cur + 1));
	if (!tmp)
		return (NULL);
	i = 0;
	while (cur < pos)
		tmp[i++] = s[cur++];
	tmp[i] = '\0';
	return (tmp);
}

char		**ft_split(char const *s, char c)
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
			tmp[i++] = ft_sep(s, c, j);
			flag = 0;
		}
		if (s[j] == c)
			flag = 1;
	}
	tmp[i] = NULL;
	return (tmp);
}
