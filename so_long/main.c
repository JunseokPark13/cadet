/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 13:58:31 by jupark            #+#    #+#             */
/*   Updated: 2021/07/08 17:39:59 by jupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

t_img	*create_img(t_game *game, char* img_path)
{
	t_img	*img;

	img = (t_img*)malloc(sizeof(t_img));
	img->img_ptr = mlx_xpm_file_to_image(game->mlx_ptr, img_path, &img->width, &img->height);
	return (img);
}

t_game	*create_game(void)
{
	t_game	*game;

	game = (t_game*)malloc(sizeof(t_game));
	game->mlx_ptr = mlx_init();
	game->win_ptr = mlx_new_window(game->mlx_ptr, 800, 800, "game_test");

	return (game);
}


void	set_map(t_game *game)
{
	int x;
	int y;
	int map[ROW][COL] = {
{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1},
	{1, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 1, 0, 1},
	{1, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1},
	{1, 0, 1, 1, 0, 1, 1, 0, 0, 0, 1, 0, 1, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1},
	{1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1},
	{1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1},
	{1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1},
	{1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
	{1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}	
	};
	y = 0;
	while (y < COL)
	{
		x = 0;
		while (x < ROW)
		{
			game->map[y][x] = map[y][x];
			x++;
		}
		y++;
	}
}

void	draw_map(t_game *game, t_img *wall, t_img *space)
{
	int		width;
	int		height;
	int		x;
	int		y;

	height = 0;
	while (height < COL)
	{
		width = 0;
		while (width < ROW)
		{
			x = width * wall->width;
			y = height * wall->height;
			if (!game->map[height][width])
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, wall->img_ptr, x, y);
			else
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, space->img_ptr, x, y);
			width++;
		}
		height++;
	}
}


int main(void){

	t_game	*game;
	t_img	*wall;
	t_img	*coin;

	game = create_game();
	wall = create_img(game, "./grassDirtBlock.xpm");
	coin = create_img(game, "./coin.xpm");
	game->wall = wall;

	printf("block width  : %d\n", wall->width);
	printf("block height : %d\n", wall->height);
	printf("coin width  : %d\n", coin->width);
	printf("coin height : %d\n", coin->height);

	set_map(game);
	draw_map(game, wall, coin);

	for(int i = 0; i < COL; i++){
		for(int j = 0; j < ROW; j++){
			printf("%d ", game->map[i][j]);
		}
		printf("\n");
	}

	mlx_loop(game->mlx_ptr);

}
