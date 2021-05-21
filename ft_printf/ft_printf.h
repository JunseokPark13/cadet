/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 11:18:14 by jupark            #+#    #+#             */
/*   Updated: 2021/05/21 18:38:00 by jupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "./libft/libft.h"

# include <stdio.h>

# define HEXUPPER "0123456789ABCDEF"
# define HEXLOWER "0123456789abcdef"
# define DEC "0123456789"

typedef struct	s_format
{
	int			hyphen;
	int			zero;
	int			width;
	int			dot;
	int			precision;
	int			base;
	int			sign;
	char		type;

}				t_format;

int				ft_printf(const char *format, ...);

size_t			write_nums(unsigned long long num, t_format *f);
size_t			write_char(int ch, t_format *f);
size_t			write_str(char *str, t_format *f);

void			init_f(t_format *f);
char			*make_str(int len, char ch);
char			*join_strs(char *left, char *right);
char			*add_hyphen(char *str);

char			*nbr_to_base(unsigned long long n, t_format *f);

void			print_format(t_format *f);
#endif
