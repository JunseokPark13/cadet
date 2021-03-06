/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 11:15:39 by jupark            #+#    #+#             */
/*   Updated: 2021/05/25 13:53:27 by jupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		check_digit(char *digit, t_format *f, va_list arg)
{
	if (digit[0] == '*')
	{
		if (*(digit - 1) == '.' && f->dot != 0)
		{
			if ((f->precision = va_arg(arg, int)) < 0)
				f->dot = -1;
		}
		else if (!f->width)
		{
			if ((f->width = va_arg(arg, int)) < 0)
			{
				f->width = f->width * (-1);
				f->hyphen = 1;
				f->zero = 0;
			}
		}
	}
	else if (digit[0] != '0')
	{
		if (f->dot == 1 && !f->precision)
			f->precision = ft_atoi(digit);
		else if (!f->width && f->dot == 0)
			f->width = ft_atoi(digit);
	}
}

static void		check_flags(char *format, t_format *f, int i, va_list arg)
{
	if (format[i] == '0' && f->width == 0 && f->dot == 0 && !f->hyphen)
		f->zero = 1;
	else if (format[i] == '-')
	{
		f->hyphen = 1;
		f->zero = 0;
	}
	else if (format[i] == '.')
	{
		f->precision = 0;
		f->dot = 1;
	}
	else if (ft_isdigit(format[i]) || format[i] == '*')
		check_digit(format + i, f, arg);
}

static int		write_arg(t_format *f, va_list arg)
{
	int		output;

	output = 0;
	if (f->type == 'x' || f->type == 'X' || f->type == 'p')
		f->base = 16;
	if (f->type == 'd' || f->type == 'i')
		output = write_nums(va_arg(arg, int), f);
	else if (f->type == 'c')
		output = write_char(va_arg(arg, int), f);
	else if (f->type == 's')
		output = write_str(va_arg(arg, char*), f);
	else if (f->type == 'p')
		output = write_nums(va_arg(arg, unsigned long long), f);
	else if (f->type == 'x' || f->type == 'X' || f->type == 'u')
		output = write_nums(va_arg(arg, unsigned int), f);
	else if (f->type == '%')
		output = write_char('%', f);
	else
		output = write_char(f->type, f);
	free(f);
	return (output);
}

static int		check_format(char *format, va_list arg, int *index)
{
	int			i;
	t_format	*f;

	if (!(f = (t_format*)malloc(sizeof(t_format))))
		return (-1);
	init_f(f);
	i = 0;
	while (!ft_strchr("cspdiuxX%", format[i]) && format[i]
			&& !ft_isalpha(format[i]))
		check_flags(format, f, i++, arg);
	f->type = format[i++];
	*index += i + 1;
	return (write_arg(f, arg));
}

int				ft_printf(const char *format, ...)
{
	int		i;
	int		len;
	int		tmp;
	va_list arg;

	va_start(arg, format);
	i = 0;
	len = 0;
	while (format[i])
	{
		while (format[i] != '%' && format[i])
		{
			ft_putchar_fd(format[i++], 1);
			len++;
		}
		if (format[i] == '%')
		{
			tmp = len;
			len += check_format((char*)format + i + 1, arg, &i);
			if (tmp > len)
				return (-1);
		}
	}
	va_end(arg);
	return (len);
}
