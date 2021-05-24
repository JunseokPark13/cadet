/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 16:03:26 by jupark            #+#    #+#             */
/*   Updated: 2021/05/21 17:54:18 by jupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			print_format(t_format *f)
{
	printf("\n---------------------------\n");
	printf("hyphen = %d\n", f->hyphen);
	printf("zero = %d\n", f->zero);
	printf("width = %d\n", f->width);
	printf("dot = %d\n", f->dot);
	printf("precision = %d\n", f->precision);
	printf("base = %d\n", f->base);
	printf("type = %c\n", f->type);
	printf("---------------------------\n");
}

void			init_f(t_format *f)
{
	f->hyphen = 0;
	f->zero = 0;
	f->width = 0;
	f->dot = 0;
	f->precision = -1;
	f->base = 10;
	f->sign = 1;
	f->type = 0;
}

char			*make_str(int len, char ch)
{
	int		i;
	char	*str;

	if (len <= 0)
		len = 0;
	if (!(str = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	str[len] = '\0';
	i = 0;
	while (i < len)
		str[i++] = ch;
	return (str);
}

char			*join_strs(char *left, char *right)
{
	char	*res;

	res = ft_strjoin(left, right);
	free(left);
	free(right);
	return (res);
}

char			*add_hyphen(char *str)
{
	char	*res;
	char	*hyphen;

	if (!(hyphen = (char*)malloc(sizeof(char) * 2)))
		return (NULL);
	hyphen[0] = '-';
	hyphen[1] = '\0';
	res = ft_strjoin(str, hyphen);
	free(hyphen);
	free(str);
	return (res);
}
