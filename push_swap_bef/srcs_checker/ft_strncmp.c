/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 19:56:27 by jupark            #+#    #+#             */
/*   Updated: 2021/06/08 13:48:35 by jupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs_pushswap/push_swap.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*tmp_s1;
	unsigned char	*tmp_s2;
	size_t			i;

	tmp_s1 = (unsigned char*)s1;
	tmp_s2 = (unsigned char*)s2;
	i = 0;
	while (i < n)
	{
		if (tmp_s1[i] != tmp_s2[i] || tmp_s1[i] == '\0' || tmp_s2[i] == '\0')
			return (tmp_s1[i] - tmp_s2[i]);
		i++;
	}
	return (0);
}
