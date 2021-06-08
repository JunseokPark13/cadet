/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 16:58:47 by jupark            #+#    #+#             */
/*   Updated: 2021/06/08 16:47:38 by jupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		free_sstr(char **sstr)
{
	int		i;

	i = -1;
	while (sstr[++i])
		free(sstr[i]);
	free(sstr);
}

int			ft_sstrlen(char **sstr)
{
	int		i;

	i = 0;
	while (sstr[i])
		i++;
	if (!i)
		return (0);
	else
		return (i - 1);
}

void		add_sstr(int *newary, char **sstr, int *index)
{
	int	j;

	j = -1;
	while (++j < ft_sstrlen(sstr) + 1)
	{
		newary[*index] = ft_atoi(sstr[j], newary);
		*index += 1;
	}
	*index -= 1;
	free_sstr(sstr);
}

int			*get_new_ary(int *ary, int *beflen, int newlen, char **sstr)
{
	int		*newary;
	int		i;

	if (!(newary = (int*)malloc(sizeof(int) * (newlen))))
		exit(0);
	i = -1;
	while (++i < *beflen)
		newary[i] = ary[i];
	free(ary);
	add_sstr(newary, sstr, beflen);
	return (newary);
}

int			*parse_argv(int argc, char *argv[], int *arylen)
{
	int		*ary;
	int		len;
	int		i;
	int		j;
	char	**sstr;

	len = argc - 1;
	if (!(ary = (int*)malloc(sizeof(int) * len)))
		exit(0);
	i = 0;
	j = 0;
	while (++j < argc)
	{
		if (ft_strchr(argv[j], ' ') && !ft_onlychr(argv[j], ' '))
		{
			sstr = ft_split(argv[j], ' ');
			len += ft_sstrlen(sstr);
			ary = get_new_ary(ary, &i, len, sstr);
		}
		else
			ary[i] = ft_atoi(argv[j], ary);
		i++;
	}
	*arylen = len;
	return (ary);
}
