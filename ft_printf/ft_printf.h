/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 11:18:14 by jupark            #+#    #+#             */
/*   Updated: 2021/05/17 20:03:39 by jupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "./libft/libft.h"

# include <stdio.h>

typedef struct	s_format
{
	int			hyphen;
	int			zero;
	int			width;
	int			precision;
	int			base;
	int			sign;
	char		type;

}				t_format;


int				ft_printf(const char *format, ...);

int				write_nums(unsigned long long num, t_format *f);

void			init_f(t_format *f);
void			print_format(t_format *f);
#endif
