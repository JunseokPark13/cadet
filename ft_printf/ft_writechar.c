/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writechar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 15:55:18 by jupark            #+#    #+#             */
/*   Updated: 2021/05/21 18:38:37 by jupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		print_char(char c, t_format *f)
{
	char *width;

	if (f->zero && c == '%' && !f->hyphen)
		width = make_str(f->width - 1, '0');
	else
		width = make_str(f->width - 1, ' ');
	if (!f->hyphen)
		ft_putstr_fd(width, 1);
	ft_putchar_fd(c, 1);
	if (f->hyphen)
		ft_putstr_fd(width, 1);
	free(width);
}

size_t			write_char(int ch, t_format *f)
{
	char c;

	c = (char)ch;
	print_char(c, f);
	if (!f->width)
		return (1);
	else
		return ((size_t)f->width);
}
