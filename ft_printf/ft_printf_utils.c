/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 16:03:26 by jupark            #+#    #+#             */
/*   Updated: 2021/05/17 20:03:31 by jupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_f(t_format *f)
{
	f->hyphen = 0;
	f->zero = 0;
	f->width = 0;
	f->precision = -1;
	f->base = 10;
	f->sign = 1;
	f->type = 0;
}

void	print_format(t_format *f)
{
	printf("---------------------------\n");
	printf("hyphen = %d\n", f->hyphen);
	printf("zero = %d\n", f->zero);
	printf("width = %d\n", f->width);
	printf("precision = %d\n", f->precision);
	printf("base = %d\n", f->base);
	printf("type = %c\n", f->type);
	printf("---------------------------\n");
}
