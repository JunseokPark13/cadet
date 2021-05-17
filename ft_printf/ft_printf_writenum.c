/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_writenum.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 19:28:30 by jupark            #+#    #+#             */
/*   Updated: 2021/05/17 20:27:57 by jupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char*	make_str(int len, char ch)
{
	int 	i;
	char 	*str;

	if(!(str = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	str[len] = '\0';
	i = 0;
	while(i < len)
		str[i++] = ch;
	return (str);
}


int		write_nums(unsigned long long num, t_format *f)
{
	
	int		len;
	char	*prec;
	char	*width;
	char	*nbr;

	if ((int)num < 0)
	{
		f->sign = -1;
		num = num * (-1);
	}

	nbr = ft_itoa(num);
	len = ft_strlen(nbr);
	prec = make_str(f->precision - len, '0');
	if (f->sign == -1)
		len++;
	width = make_str(f->width - (len + ft_strlen(prec)), ' ');
	//printf("width len : %d\n", f->width);
	//printf("len : %d\n", len);
	//printf("precision eln : %d\n", f->precision);
	//printf("width : %s\nwidth len = %d\n", width, f->width - len - f->precision);
	ft_putstr_fd(width, 1);
	if (f->sign == -1)
		ft_putchar_fd('-', 1);
	ft_putstr_fd(ft_strjoin(prec, nbr), 1);
	return (0);
}
