/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 11:15:39 by jupark            #+#    #+#             */
/*   Updated: 2021/05/24 20:12:06 by jupark           ###   ########.fr       */
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
	if (format[i] == '0' && f->width == 0 && f->dot == 0)
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

static size_t	write_arg(t_format *f, va_list arg, char **outstr)
{
	size_t	output;

	output = 0;
	if (f->type == 'x' || f->type == 'X' || f->type == 'p')
		f->base = 16;
	if (f->type == 'd' || f->type == 'i')
		output = write_nums(va_arg(arg, int), f, outstr);
	else if (f->type == 'c')
		output = write_char(va_arg(arg, int), f, outstr);
	else if (f->type == 's')
		output = write_str(va_arg(arg, char*), f, outstr);
	else if (f->type == 'p')
		output = write_nums(va_arg(arg, unsigned long long), f, outstr);
	else if (f->type == 'x' || f->type == 'X' || f->type == 'u')
		output = write_nums(va_arg(arg, unsigned int), f, outstr);
	else if (f->type == '%')
		output = write_char('%', f, outstr);
	free(f);
	return (output);
}

static size_t	check_format(char *format, va_list arg, int *index, char **outstr)
{
	int			i;
	t_format	*f;

	if (!(f = (t_format*)malloc(sizeof(t_format))))
		return (0);
	init_f(f);
	i = 0;
	while (!ft_strchr("cspdiuxX%", format[i]) && format[i]
			&& !ft_isalpha(format[i]))
		check_flags(format, f, i++, arg);
	f->type = format[i++];
	*index += i + 1;
	return (write_arg(f, arg, outstr));
}

int				ft_printf(const char *format, ...)
{
	int		i;
	int		s;
	size_t	len;
	va_list arg;
	char	*outstr;

	va_start(arg, format);
	i = 0;
	s = 0;
	len = 0;
	if(!(outstr = (char*)malloc(sizeof(char))))
		return (0);
	outstr[0] = '\0';
	while (format[i])
	{
		while (format[i] != '%' && format[i])
		{
			//ft_putchar_fd(format[i++], 1);
			i++;
			len++;
		}
		if (format[i] == '%')
		{
			//printf("\ns = %d, i = %d\n", s, i);
			outstr = join_strs(outstr, ft_substr(format, s, i - s));
			
			//ft_putstr_fd(outstr, 1);
			//printf("\noutstr = %s\n", outstr);
			len += check_format((char*)format + i + 1, arg, &i, &outstr);	
			//printf("\noutstr = %s\n", outstr);
			s = i;
		}
	}
	outstr = join_strs(outstr, ft_substr(format, s, i - s));
	ft_putstr_fd(outstr, 1);
	//printf("\noutstr = %s\n", outstr);
	free(outstr);
	va_end(arg);
	return ((int)len);
}
