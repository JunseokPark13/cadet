/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 13:32:00 by jupark            #+#    #+#             */
/*   Updated: 2021/06/08 16:46:41 by jupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int			ft_countword(char const *s, char c)
{
	int		i;
	int		cnt;

	cnt = 0;
	i = 0;
	while (s[i])
	{
		if (s[i++] != c)
		{
			cnt++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
	}
	return (cnt);
}

static char			*ft_sep(char const *s, char c, int pos)
{
	int		cur;
	int		i;
	char	*tmp;

	cur = pos++;
	while (s[pos] != c && s[pos] != '\0')
		pos++;
	tmp = (char*)malloc(sizeof(char) * (pos - cur + 1));
	if (!tmp)
		exit(0);
	i = 0;
	while (cur < pos)
		tmp[i++] = s[cur++];
	tmp[i] = '\0';
	return (tmp);
}

static char			**ft_freeall(char **s)
{
	unsigned int i;

	i = -1;
	while (s[++i])
		free(s[i]);
	free(s);
	return (NULL);
}

char				**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		flag;
	char	**tmp;

	if (!s)
		return (NULL);
	if (!(tmp = (char**)malloc(sizeof(char*) * (ft_countword(s, c) + 1))))
		exit(0);
	i = 0;
	j = -1;
	flag = 1;
	while (s[++j])
	{
		if (flag && s[j] != c)
		{
			if (!(tmp[i++] = ft_sep(s, c, j)))
				return (ft_freeall(tmp));
			flag = 0;
		}
		if (s[j] == c)
			flag = 1;
	}
	tmp[i] = NULL;
	return (tmp);
}
