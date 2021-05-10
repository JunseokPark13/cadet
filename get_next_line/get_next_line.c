/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 15:26:20 by jupark            #+#    #+#             */
/*   Updated: 2021/05/10 21:20:01 by jupark           ###   ########.fr       */
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

int				get_next_line(int fd, char **line)
{
	static char		*another_f[OPEN_MAX];
	char		str[BUFFER_SIZE + 1];
	int			len;
	int			newline_i;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	while((len = (read(fd, str, BUFFER_SIZE))) > 0)
	{
		str[len] = '\0';
		printf("read : %s , %d, %d\n", str, len, BUFFER_SIZE);
		another_f[fd] = ft_strjoin(another_f[fd], str);
		if ((newline_i = is_newline(another_f[fd])) >= 0){
			return(cut_by_index(&another_f[fd], line, newline_i));
		}
	}
	if (len < 0)
		return (-1);
	if (another_f[fd] && (newline_i = is_newline(another_f[fd]) >= 0))
	{
		printf("case1 : %d\n", len);
		printf("newline_i = %d\n", newline_i);
		return(cut_by_index(&another_f[fd], line, newline_i));
	}
	else if (another_f[fd])
	{
		printf("case2 : %d\n", len);
		*line = another_f[fd];
		another_f[fd] = 0;
		return (0);
	}
		printf("case3 : %d\n", len);
	*line = ft_strdup("");

	return (0);
}
