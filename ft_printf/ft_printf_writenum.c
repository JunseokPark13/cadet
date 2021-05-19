/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_writenum.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 19:28:30 by jupark            #+#    #+#             */
/*   Updated: 2021/05/19 22:11:11 by jupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		print_nums(char *width, char *join, t_format *f)
{
	if (f->sign == -1 && f->zero)
		ft_putchar_fd('-', 1);
	if (!f->hyphen)
		ft_putstr_fd(width, 1);
	if (f->sign == -1 && !f->zero)
		ft_putchar_fd('-', 1);
	ft_putstr_fd(join, 1);
	if (f->hyphen)
		ft_putstr_fd(width, 1);
}


static void		assemble_nums(char *nbr, size_t len, t_format *f)
{
	char *prec;
	char *width;
	char *join;

	prec = make_str(f->precision - len, '0');
	if (f->sign == -1)
		len++;
	if (f->zero)
		width = make_str(f->width - (len + ft_strlen(prec)), '0');
	else
		width = make_str(f->width - (len + ft_strlen(prec)), ' ');
	join = ft_strjoin(prec, nbr);
	print_nums(width, join, f);
	free(width);
	free(prec);
	free(nbr);
	free(join);
}

static int		get_length(t_format *f, int len)
{
	if (f->width < f->precision)
	{
		if (f->sign == -1)
			return (f->precision + 1);
		else
			return (f->precision);
	}
	else if (f->width < (int)len && f->precision < (int)len)
		return (len);
	else
		return (f->width);
}

int				write_nums(unsigned long long num, t_format *f)
{
	size_t		len;
	char		*nbr;

	if ((f->type == 'd' || f->type == 'i') && (int)num < 0)
	{
		f->sign = -1;
		num = num * (-1);
	}
	if (f->precision != -1)
		f->zero = 0;
	nbr = nbr_to_base(num, f);
	len = ft_strlen(nbr);
	assemble_nums(nbr, len, f);
	return (get_length(f, len));
}
