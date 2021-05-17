/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 11:15:39 by jupark            #+#    #+#             */
/*   Updated: 2021/05/17 19:32:07 by jupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		check_digit(char *digit, t_format *f, va_list arg)
{
	if (digit[0] == '*')
	{
		if (*(digit - 1) == '.')
			f->precision = va_arg(arg, int);
		else
			f->width = va_arg(arg, int);
	}
	else if (digit[0] != '0')
	{
		if (*(digit - 1)  == '.')
			f->precision = ft_atoi(digit);
		else
			f->width = ft_atoi(digit);
	}
}

static void		check_flags(char *format, t_format *f, int i, va_list arg)
{
	if (format[i] == '0' && f->width == 0 && f->precision == -1)
		f->zero = 1;
	else if (format[i] == '-')
		f->hyphen = 1;
	else if (format[i] == '.')
		f->precision = 0;
	else if (ft_isdigit(format[i]) || format[i] == '*')
		check_digit(format + i, f, arg);
}

static void		write_arg(t_format *f, va_list arg)
{
	if(f->type == 'd' || f->type == 'i')
	{
		write_nums(va_arg(arg, int), f);
		//ft_putstr_fd(ft_itoa(va_arg(arg, int)), 1);
	}
	else if (f->type == 'c')
		ft_putchar_fd(va_arg(arg, int), 1);
	else if (f->type == 's')
		ft_putstr_fd(va_arg(arg, char*), 1);
	else if (f->type == 'p')
		printf("%lld", va_arg(arg, unsigned long long));
	else if (f->type == 'x' || f->type == 'X' || f->type == 'u')
		printf("%x", va_arg(arg, unsigned int));
}

static int	check_format(char *format, va_list arg, int *index)
{
	int i;
	t_format *f;

	if(!(f = (t_format*)malloc(sizeof(t_format))))
		return (0);
	init_f(f);
	i = 0;
	while (!ft_strchr("cspdiuxX", format[i]) && format[i] && !ft_isalpha(format[i]))
		check_flags(format, f, i++, arg);
	f->type = format[i++];
	//print_format(f);
	write_arg(f, arg);
	*index += i + 1;
	return (i);
}

int		ft_printf(const char *format, ...)
{
	int		i;
	int		len;
	va_list arg;

	va_start(arg, format);
	i = 0;
	len = 0;
	while (format[i])
	{
		while (format[i] != '%' && format[i])
		{
			ft_putchar_fd(format[i], 1);
			i++;
			len++;
		}
		if (format[i] == '%')
			len += check_format((char*)format + i + 1, arg, &i);
	}

	va_end(arg);

	return (0);
}
