/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agtshiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 16:53:09 by agtshiba          #+#    #+#             */
/*   Updated: 2024/05/27 16:54:25 by agtshiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	window_init(t_game *game)
{
	int	win_w;
	int	win_h;

	win_w = (game->map_width - 1) * 31;
	win_h = game->map_height * 31;
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, win_w, win_h, "game map");
}

void	init_images_character(t_game *game)
{
	t_game	*g;
	void	*m;
	int		*h;
	int		*w;

	g = game;
	m = g->mlx;
	h = &g->x_h;
	w = &g->x_w;
	g->img.x_p_c = "./images/perso.xpm";
	g->img.x_p_c_rr = "./images/perso_right_right.xpm";
	g->img.x_p_c_u = "./images/perso_up.xpm";
	g->img.x_p_c_uu = "./images/perso_up_up.xpm";
	g->img.x_p_c_l = "./images/perso_left.xpm";
	g->img.x_p_c_ll = "./images/perso_left_left.xpm";
	g->img.x_p_c_d = "./images/perso_down.xpm";
	g->img.x_p_c_dd = "./images/perso_down_down.xpm";
	g->img.x_i_c = mlx_xpm_file_to_image(m, g->img.x_p_c, w, h);
	g->img.x_i_c_rr = mlx_xpm_file_to_image(m, g->img.x_p_c_rr, w, h);
	g->img.x_i_c_u = mlx_xpm_file_to_image(m, g->img.x_p_c_u, w, h);
	g->img.x_i_c_uu = mlx_xpm_file_to_image(m, g->img.x_p_c_uu, w, h);
	g->img.x_i_c_l = mlx_xpm_file_to_image(m, g->img.x_p_c_l, w, h);
	g->img.x_i_c_ll = mlx_xpm_file_to_image(m, g->img.x_p_c_ll, w, h);
	g->img.x_i_c_d = mlx_xpm_file_to_image(m, g->img.x_p_c_d, w, h);
	g->img.x_i_c_dd = mlx_xpm_file_to_image(m, g->img.x_p_c_dd, w, h);
}

void	init_images_obj(t_game *game)
{
	t_game	*g;
	void	*m;
	int		*h;
	int		*w;

	g = game;
	m = g->mlx;
	h = &g->x_h;
	w = &g->x_w;
	g->img.xpw = "./images/wall.xpm";
	g->img.xpg = "./images/ground.xpm";
	g->img.xpcoll = "./images/collectible.xpm";
	g->img.xpd = "./images/portal.xpm";
	g->img.xiwal = mlx_xpm_file_to_image(m, g->img.xpw, w, h);
	g->img.xigro = mlx_xpm_file_to_image(m, g->img.xpg, w, h);
	g->img.xicol = mlx_xpm_file_to_image(m, g->img.xpcoll, w, h);
	g->img.xidoo = mlx_xpm_file_to_image(m, g->img.xpd, w, h);
}

void	initialize_window(t_game *game)
{
	window_init(game);
	init_images_character(game);
	init_images_obj(game);
	display_player_pos(game);
}
