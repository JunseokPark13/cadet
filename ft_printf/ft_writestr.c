/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writestr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 22:05:39 by jupark            #+#    #+#             */
/*   Updated: 2021/05/25 14:55:24 by jupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		join_string(char *width, char *str, int len, t_format *f)
{
	char	*res;
	int		res_len;

	if (!(res = (char*)malloc(sizeof(char) * 1)))
		return (-2);
	res[0] = '\0';
	if (!f->hyphen)
		res = join_strs(width, res);
	if (f->dot)
	{
		if ((int)len < f->precision)
			res = join_strs(res, ft_substr(str, 0, len));
		else
			res = join_strs(res, ft_substr(str, 0, f->precision));
	}
	else
		res = join_strs(res, ft_substr(str, 0, len));
	if (f->hyphen)
		res = join_strs(res, width);
	if (res == (char*)(-1))
		return (-1);
	ft_putstr_fd(res, 1);
	res_len = ft_strlen(res);
	free(res);
	return (res_len);
}

static int		print_str(char *str, size_t len, t_format *f)
{
	char	*width;
	int		out;

	if (!f->dot)
		width = make_str(f->width - len, ' ');
	else
	{
		if (f->precision < (int)len)
			width = make_str(f->width - f->precision, ' ');
		else
			width = make_str(f->width - len, ' ');
	}
	if (width == (char*)(-1))
		return (-1);
	out = join_string(width, str, len, f);
	if (out == -2)
	{
		free(width);
		return (-1);
	}
	return (out);
}

int				write_str(char *str, t_format *f)
{
	int		len;

	if (f->precision < 0)
		f->dot = 0;
	if (str == NULL)
	{
		len = 6;
		return (print_str("(null)", len, f));
	}
	else
	{
		len = ft_strlen(str);
		return (print_str(str, len, f));
	}
}
