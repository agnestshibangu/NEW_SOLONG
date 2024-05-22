/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agtshiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 13:12:40 by agtshiba          #+#    #+#             */
/*   Updated: 2024/05/20 22:30:28 by agtshiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


void	create_map(t_game *game)
{
	int		fd;
	char	*treated_line;
	char	*name_file;

	name_file = "./ber_files/file2.ber";
	check_extension_file_name(name_file);
	fd = open(name_file, O_RDONLY);
	ft_memset(game, 0, sizeof(t_game));
	treated_line = get_next_line(fd);
	if (!treated_line)
	{
			close(fd);
			// free(treated_line);
			return ;
	}
	while (treated_line){
		save_line_in_map(game, treated_line);
		free(treated_line);
		treated_line = get_next_line(fd);	
	}
	free(treated_line);
	close(fd);
}

// while (1){
	// 	treated_line = get_next_line(fd);
	// 	save_line_in_map(game, treated_line);
	// 	if (!treated_line)
	// 	{
	// 		close(fd);
	// 		free(treated_line);
	// 		get_next_line(-1);
	// 		break ;
	// 	}	
	// }

void	display_image_before(t_game *game, char *path)
{
	void	*img;
	img = mlx_xpm_file_to_image(game->mlx, path, &game->win_w, &game->win_h);
	if (!img){
		//ft_printf("destroy successful");
		mlx_destroy_window(game->mlx, game->win);
		mlx_destroy_display(game->mlx);
		return ;
	}
	mlx_put_image_to_window(game->mlx, game->win, img, 0, 0);
	mlx_do_sync(game->mlx);
	usleep(3000000);
	mlx_destroy_image(game->mlx, img);
	mlx_clear_window(game->mlx, game->win);
	// mlx_destroy_window(game->mlx, game->win);
}

void	window_init(t_game *game)
{
	int	win_w;
	int	win_h;

	win_w = (game->map_width - 1) * 31;
	win_h = game->map_height * 31;
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, win_w, win_h, "game map");
	ft_printf("window size");
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

void init_images_obj(t_game *game)
{
	t_game *g;
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
