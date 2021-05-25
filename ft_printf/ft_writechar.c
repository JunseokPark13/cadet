/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writechar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 15:55:18 by jupark            #+#    #+#             */
/*   Updated: 2021/05/25 11:31:54 by jupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		print_char(char c, t_format *f)
{
	char *width;

	if (f->zero && c == '%' && !f->hyphen)
		width = make_str(f->width - 1, '0');
	else
		width = make_str(f->width - 1, ' ');
	if (width == (char*)(-1))
		return (-1);
	if (!f->hyphen)
		ft_putstr_fd(width, 1);
	ft_putchar_fd(c, 1);
	if (f->hyphen)
		ft_putstr_fd(width, 1);
	free(width);
	return (1);
}

int				write_char(int ch, t_format *f)
{
	char c;

	c = (char)ch;
	if (print_char(c, f) == -1)
		return (-1);
	if (!f->width)
		return (1);
	else
		return (f->width);
}
