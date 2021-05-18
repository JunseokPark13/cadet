/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 16:03:26 by jupark            #+#    #+#             */
/*   Updated: 2021/05/18 18:16:47 by jupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
void	print_format(t_format *f)
{
	printf("\n---------------------------\n");
	printf("hyphen = %d\n", f->hyphen);
	printf("zero = %d\n", f->zero);
	printf("width = %d\n", f->width);
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
	f->precision = -1;
	f->base = 10;
	f->sign = 1;
	f->type = 0;
}

char			*make_str(int len, char ch)
{
	int		i;
	char	*str;

	if (len < 0)
		len = 0;
	if (!(str = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	str[len] = '\0';
	i = 0;
	while (i < len)
		str[i++] = ch;
	return (str);
}

static int		count_base(unsigned long long n, t_format *f)
{
	int	cnt;

	cnt = 0;
	while (n)
	{
		n /= f->base;
		cnt++;
	}
	if (f->type == 'p')
		cnt += 2;
	return (cnt);
}

char			*nbr_to_base(unsigned long long n, t_format *f)
{
	int		i;
	int		len;
	char	*nstr;

	len = count_base(n, f);
	if(!(nstr = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 1;
	while (n)
	{
		if (f->type == 'X')
			nstr[len - (i++)] = HEXUPPER[n % f->base];
		else
			nstr[len - (i++)] = HEXLOWER[n % f->base];
		n /= f->base;
	}
	if (f->type == 'p')
	{
		nstr[0] = '0';
		nstr[1] = 'x';
	}
	nstr[len] = '\0';
	return (nstr);
}
