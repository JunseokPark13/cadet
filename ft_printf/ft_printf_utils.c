/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 16:03:26 by jupark            #+#    #+#             */
/*   Updated: 2021/05/25 15:22:37 by jupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
		return ((char*)(-1));
	str[len] = '\0';
	i = 0;
	while (i < len)
		str[i++] = ch;
	return (str);
}

char			*join_strs(char *left, char *right)
{
	char	*res;

	if (left == (char*)(-1) || right == (char*)(-1))
	{
		if (left != (char*)(-1))
			free(left);
		if (right != (char*)(-1))
			free(right);
		return ((char*)(-1));
	}
	if (!(res = ft_strjoin(left, right)))
		res = (char*)(-1);
	free(left);
	free(right);
	return (res);
}

char			*add_hyphen(char *str)
{
	char	*res;
	char	*hyphen;

	if (!(hyphen = (char*)malloc(sizeof(char) * 2)))
	{
		if (str != (char*)(-1))
			free(str);
		return ((char*)(-1));
	}
	hyphen[0] = '-';
	hyphen[1] = '\0';
	if (!(res = ft_strjoin(str, hyphen)))
		res = (char*)(-1);
	free(hyphen);
	free(str);
	return (res);
}
