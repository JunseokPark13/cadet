/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 15:26:20 by jupark            #+#    #+#             */
/*   Updated: 2021/06/10 17:12:04 by jupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		is_newline(char *str)
{
	int		i;

	i = -1;
	while (str[++i])
		if (str[i] == '\n')
			return (i);
	return (-1);
}

static int		cut_by_index(char **before_s, char **line, int index)
{
	size_t	len;
	char	*tmp_b;

	len = ft_strlen(*before_s);
	*line = ft_substr(*before_s, 0, index);
	tmp_b = ft_substr(*before_s, index + 1, len - index + 1);
	free(*before_s);
	*before_s = tmp_b;
	return (1);
}

static int		cut_left_string(char **before_s, char **line)
{
	int		newline_i;

	if (!*before_s)
	{
		*line = ft_strdup("");
		return (0);
	}
	else if ((newline_i = is_newline(*before_s)) >= 0)
		return (cut_by_index(before_s, line, newline_i));
	else
	{
		*line = *before_s;
		*before_s = 0;
		return (0);
	}
}

int				get_next_line(int fd, char **line)
{
	static char		*another_f[OPEN_MAX];
	char			*str;
	int				len;
	int				newline_i;
	int				output;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!(str = (char*)malloc(sizeof(char*) * (BUFFER_SIZE + 1))))
		return (0);
	while ((len = (read(fd, str, BUFFER_SIZE))) > 0)
	{
		str[len] = '\0';
		another_f[fd] = ft_strjoin(another_f[fd], str);
		if ((newline_i = is_newline(another_f[fd])) >= 0)
		{
			free(str);
			return (cut_by_index(&another_f[fd], line, newline_i));
		}
	}
	free(str);
	if (len < 0)
		return (-1);
	output = cut_left_string(&another_f[fd], line);
	return (output);
}
