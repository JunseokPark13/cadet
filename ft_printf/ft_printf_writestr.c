/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_writestr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 22:05:39 by jupark            #+#    #+#             */
/*   Updated: 2021/05/19 22:58:03 by jupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_str(char *str, int len, t_format *f)
{
	char *width;
	int	 i;

	i = 0;
	if (f->precision == -1)
		width = make_str(f->width - len, ' ');
	else
	{
		if (f->precision < len)
			width = make_str(f->width - f->precision, ' ');
		else
			width = make_str(f->width - len, ' ');
	}
	if (!f->hyphen)
		ft_putstr_fd(width, 1);
	if (f->precision != -1)
		while (i < len && i < f->precision)
			ft_putchar_fd(str[i++], 1);
	else
		while (i < len)
			ft_putchar_fd(str[i++], 1);
	if (f->hyphen)
		ft_putstr_fd(width, 1);
	free(width);
}

static int	get_length(int len, t_format *f)
{
	if (f->precision == -1)
	{
		if (f->width < len)
			return (len);
		else
			return (f->width);
	}
	if (f->precision < len)
	{
		if (f->width < f->precision)
			return (f->precision);
		else
			return (f->width);
	}
	else
	{
		if (f->width < len)
			return (len);
		else
			return (f->width);
	}
}

int			write_str(char *str, t_format *f)
{
	int		len;

	len  = ft_strlen(str);
	print_str(str, len, f);
	return (get_length(len, f));
}
