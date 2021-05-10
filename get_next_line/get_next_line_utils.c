/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 21:50:24 by jupark            #+#    #+#             */
/*   Updated: 2021/05/10 21:19:05 by jupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *s1)
{
	char	*tmp;
	size_t	s_len;
	size_t	i;

	s_len = ft_strlen(s1);
	if(!(tmp = (char*)malloc(sizeof(char) * (s_len + 1))))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		tmp[i] = s1[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*tmp;
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;

	if (!s1 && !s2)
		return (NULL);
	else if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (ft_strdup(s1));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (!(tmp = (char*)malloc(sizeof(char) * (s1_len + s2_len + 1))))
		return (NULL);
	i = -1;
	while (s1[++i])
		tmp[i] = s1[i];
	i = -1;
	while (s2[++i])
		tmp[s1_len + i] = s2[i];
	tmp[s1_len + i] = '\0';
	free(s1);
	return (tmp);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*tmp;
	size_t	i;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (s_len - start <= len)
		len = s_len - start;
	if (start >= s_len)
		tmp = (char*)malloc(sizeof(char));
	else
		tmp = (char*)malloc(sizeof(char) * (len + 1));
	if (!tmp)
		return (NULL);
	i = 0;
	while (i < len && start < s_len)
		tmp[i++] = s[start++];
	tmp[i] = '\0';
	return (tmp);
}
