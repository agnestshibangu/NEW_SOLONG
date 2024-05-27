/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agtshiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 17:57:07 by agtshiba          #+#    #+#             */
/*   Updated: 2024/05/27 16:51:25 by agtshiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	animation_caracter(t_game *game, int x, int y)
{
	t_game	*g;
	int		w;
	int		h;

	g = game;
	w = x * g->x_w;
	h = y * g->x_h;
	if ((g->player_sprite == 0) && (g->steps % 2 == 0))
		mlx_put_image_to_window(g->mlx, g->win, g->img.x_i_c, w, h);
	else if ((g->player_sprite == 0) && (g->steps % 2 != 0))
		mlx_put_image_to_window(g->mlx, g->win, g->img.x_i_c_rr, w, h);
	else if ((g->player_sprite == 1) && (g->steps % 2 == 0))
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

void	draw_image(t_game *game, char tile, int w, int h)
{
	if (tile == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->img.xiwal, w, h);
	else if (tile == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->img.xigro, w, h);
	else if (tile == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->img.xicol, w, h);
	else if (tile == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->img.xidoo, w, h);
}

void	draw_grid(t_game *game)
{
	t_game	*g;
	int		y;
	int		x;
	int		h;
	int		w;

	g = game;
	y = 0;
	while (y < game->map_height)
	{
		h = y * g->x_h;
		x = 0;
		while (x < game->map_width - 1)
		{
			w = x * g->x_w;
			if ((game->player_pos_y == y) && (game->player_pos_x == x))
				animation_caracter(game, x, y);
			else
				draw_image(game, game->map[y][x], w, h);
			x++;
		}
		y++;
	}
}
