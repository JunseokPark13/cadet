/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 15:26:20 by jupark            #+#    #+#             */
/*   Updated: 2021/05/09 21:50:12 by jupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		is_newline(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		if (str[i] == '\n')
			return (i);
	return (-1);
}

int				get_next_line(int fd, char **line)
{
	static	
	char	str[BUFFER_SIZE + 1];
	int		len;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	while((len = (read(fd, str, BUFFER_SIZE))) > 0)
	{
		str[len] = '\0'
	}
	*line = str;
	return (len);
}
