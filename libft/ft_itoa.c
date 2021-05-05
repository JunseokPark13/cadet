/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 15:24:49 by jupark            #+#    #+#             */
/*   Updated: 2021/05/05 15:44:32 by jupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_checklength(int n)
{
	int cnt;

	cnt = 0;
	if (n < 0)
	{
		n /= 10;
		n *= -1;
		cnt += 2;
	}
	while (n)
	{
		n /= 10;
		cnt++;
	}
	return (cnt);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*nstr;

	if (n == 0)
		return (ft_strdup("0"));
	len = ft_checklength(n);
	nstr = (char*)malloc(sizeof(char) * len + 1);
	if (!nstr)
		return (NULL);
	nstr[len] = '\0';
	if (n < 0)
	{
		nstr[0] = '-';
		nstr[--len] = ((n % 10) * -1) + 48;
		n /= 10;
		n *= -1;
	}
	while (n)
	{
		nstr[--len] = n % 10 + 48;
		n /= 10;
	}
	return (nstr);
}
