/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writenum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 19:28:30 by jupark            #+#    #+#             */
/*   Updated: 2021/05/24 20:13:38 by jupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	join_nums(char *width, char *join, t_format *f, char **outstr)
{
	char	*res;
	size_t	len;

	if (!(res = (char*)malloc(sizeof(char) * 1)))
		return (0);
	res[0] = '\0';
	if (f->sign == -1 && f->zero)
		res = add_hyphen(res);
	if (!f->hyphen)
		res = join_strs(res, width);
	if (f->sign == -1 && !f->zero)
		res = add_hyphen(res);
	res = join_strs(res, join);
	if (f->hyphen)
		res = join_strs(res, width);
	//ft_putstr_fd(res, 1);
	len = ft_strlen(res);
	*outstr = join_strs(*outstr, res);
	//free(res);
	return (len);
}

static size_t	assemble_nums(char *nbr, size_t len, t_format *f, char **outstr)
{
	char	*prec;
	char	*width;
	char	*join;
	size_t	res_len;

	prec = make_str(f->precision - len, '0');
	if (f->sign == -1)
		len++;
	if (f->zero && (!(f->dot && !f->precision)))
		width = make_str(f->width - (len + ft_strlen(prec)), '0');
	else
		width = make_str(f->width - (len + ft_strlen(prec)), ' ');
	join = ft_strjoin(prec, nbr);
	free(prec);
	free(nbr);
	res_len = join_nums(width, join, f, outstr);
	return (res_len);
}

size_t			write_nums(unsigned long long num, t_format *f, char **outstr)
{
	size_t		len;
	char		*nbr;

	if ((f->type == 'd' || f->type == 'i') && (int)num < 0)
	{
		f->sign = -1;
		num = num * (-1);
	}
	if (f->type == 'p' && !num && !f->precision)
		nbr = ft_strdup("0x");
	else
		nbr = nbr_to_base(num, f);
	len = ft_strlen(nbr);
	if ((f->dot == -1 && !f->width && num == 0) || f->precision >= 0)
		f->zero = 0;
	if (f->type != 'p' && f->precision >= 0 && num == 0)
		return (assemble_nums(NULL, 0, f, outstr));
	else
		return (assemble_nums(nbr, len, f, outstr));
}
