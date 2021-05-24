/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writechar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 15:55:18 by jupark            #+#    #+#             */
/*   Updated: 2021/05/24 21:18:55 by jupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		print_char(char c, t_format *f, char **outstr)
{
	char *str;
	char *width;

	if(!(str = (char*)malloc(sizeof(char) * 2)))
		return (-1);
	str[0] = c;
	str[1] = '\0';
	
	if (f->zero && c == '%' && !f->hyphen)
		width = make_str(f->width - 1, '0');
	else
		width = make_str(f->width - 1, ' ');
	if (!f->hyphen)
		str = join_strs(width, str);
	else
		str = join_strs(str, width);
	 *outstr = join_strs(*outstr, str);
	return (1);
}

size_t			write_char(int ch, t_format *f, char **outstr)
{
	char c;

	c = (char)ch;
	print_char(c, f, outstr);
	if (!f->width)
		return (1);
	else
		return ((size_t)f->width);
}
