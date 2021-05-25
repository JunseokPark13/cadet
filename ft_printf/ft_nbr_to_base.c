/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr_to_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 11:24:25 by jupark            #+#    #+#             */
/*   Updated: 2021/05/25 11:15:09 by jupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		count_base(unsigned long long n, t_format *f)
{
	int cnt;

	cnt = 0;
	if (!n)
		cnt = 1;
	else
		while (n)
		{
			n /= f->base;
			cnt++;
		}
	if (f->type == 'p')
		cnt += 2;
	return (cnt);
}

static char		convert_nums(unsigned long long n, t_format *f)
{
	if (f->type == 'x' || f->type == 'p')
		return (HEXLOWER[n % f->base]);
	else if (f->type == 'X')
		return (HEXUPPER[n % f->base]);
	else
		return (DEC[n % f->base]);
}

char			*nbr_to_base(unsigned long long n, t_format *f)
{
	int		i;
	int		len;
	char	*nstr;

	len = count_base(n, f);
	if (!(nstr = (char*)malloc(sizeof(char) * (len + 1))))
		return ((char*)(-1));
	i = 1;
	if (!n)
		nstr[len - 1] = '0';
	while (n)
	{
		nstr[len - (i++)] = convert_nums(n, f);
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
