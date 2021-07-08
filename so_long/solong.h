/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 13:54:24 by jupark            #+#    #+#             */
/*   Updated: 2021/07/08 17:37:48 by jupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mlx.h>

# define	ROW 16
# define	COL 16

typedef struct	s_img
{
	void	*img_ptr;
	int		width;
	int		height;
}				t_img;

typedef struct	s_game
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	*wall;
	int		map[COL][ROW];
}				t_game;

void			mapcpy(int **dst, int **src, int x, int y);

#endif
