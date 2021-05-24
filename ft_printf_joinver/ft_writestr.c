/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writestr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 22:05:39 by jupark            #+#    #+#             */
/*   Updated: 2021/05/24 19:52:25 by jupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	join_string(char *width, char *str, size_t len, t_format *f, char **outstr)
{
	char	*res;
	size_t	res_len;

	if (!(res = (char*)malloc(sizeof(char) * 1)))
		return (0);
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
	//ft_putstr_fd(res, 1);
	res_len = ft_strlen(res);
	//free(res);
	*outstr = join_strs(*outstr, res);
	return (res_len);
}

static size_t	print_str(char *str, size_t len, t_format *f, char **outstr)
{
	char *width;

	if (!f->dot)
		width = make_str(f->width - len, ' ');
	else
	{
		if (f->precision < (int)len)
			width = make_str(f->width - f->precision, ' ');
		else
			width = make_str(f->width - len, ' ');
	}
	return (join_string(width, str, len, f, outstr));
}

size_t			write_str(char *str, t_format *f, char **outstr)
{
	size_t	len;

	if (f->precision < 0)
		f->dot = 0;
	if (str == NULL)
	{
		len = 6;
		return (print_str("(null)", len, f, outstr));
	}
	else
	{
		len = ft_strlen(str);
		return (print_str(str, len, f, outstr));
	}
}
