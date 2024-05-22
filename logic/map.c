/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agtshiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 17:57:07 by agtshiba          #+#    #+#             */
/*   Updated: 2024/05/20 22:47:39 by agtshiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	animation_caracter(t_game *game, int x, int y)
{
	t_game	*g;
	int	w;
	int	h;

	g = game;
	w = x * g->x_w;
	h = y * g->x_h;
	if ((g->player_sprite == 0) && (g->steps % 2 == 0))
		mlx_put_image_to_window(g->mlx, g->win, g->img.x_i_c, w, h);
	else if ((g->player_sprite == 0) && (g->steps % 2 != 0))
		mlx_put_image_to_window(g->mlx, g->win, g->img.x_i_c_rr, w, h);
	if ((g->player_sprite == 1) && (g->steps % 2 == 0))
		mlx_put_image_to_window(g->mlx, g->win, g->img.x_i_c_u, w, h);
	else if ((g->player_sprite == 1) && (g->steps % 2 != 0))
		mlx_put_image_to_window(g->mlx, g->win, g->img.x_i_c_uu, w, h);
	else if ((g->player_sprite == 2) && (g->steps % 2 == 0))
		mlx_put_image_to_window(g->mlx, g->win, g->img.x_i_c_l, w, h);
	else if ((g->player_sprite == 2) && (g->steps % 2 != 0))
		mlx_put_image_to_window(g->mlx, g->win, g->img.x_i_c_ll, w, h);
	else if ((g->player_sprite == 3) && (g->steps % 2 == 0))
		mlx_put_image_to_window(g->mlx, g->win, g->img.x_i_c_d, w, h);
	else if ((g->player_sprite == 3) && (g->steps % 2 != 0))
		mlx_put_image_to_window(g->mlx, g->win, g->img.x_i_c_dd, w, h);
}

void	drawGrid(t_game *game)
{
	t_game	*g;
	int	y;
	int	x;

	g = game;
	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width - 1)
		{
			if ((game->player_pos_y == y) && (game->player_pos_x == x))
				animation_caracter(game, x, y);
			else if (g->map[y][x] == '1')
				mlx_put_image_to_window(g->mlx, g->win, g->img.xiwal, x * g->x_w, y * g->x_h);
			else if (g->map[y][x] == '0')
				mlx_put_image_to_window(g->mlx, g->win, g->img.xigro, x * g->x_w, y * g->x_h);
			else if (g->map[y][x]  == 'C')  
				mlx_put_image_to_window(g->mlx, g->win, g->img.xicol, x * g->x_w, y * g->x_h);
			else if (g->map[y][x]  == 'E')
				mlx_put_image_to_window(g->mlx, g->win, g->img.xidoo, x * g->x_w, y * g->x_h);
			x++;
		}
		y++;
	}
}

void	count_collectibles(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width - 1)
		{
			if (game->map[y][x] == 'C')
				game->nb_collectibles += 1;
			x++;
		}
		y++;
	}
}
