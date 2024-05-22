/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agtshiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 12:34:23 by agtshiba          #+#    #+#             */
/*   Updated: 2024/05/17 12:34:30 by agtshiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// void 	free_images(t_game *game)
// {
// 	mlx_destroy_image(game->mlx, game->img.x_p_c);
// 	mlx_destroy_image(game->mlx, game->img.x_p_c_rr);
// 	mlx_destroy_image(game->mlx, game->img.x_p_c_u);
// 	mlx_destroy_image(game->mlx, game->img.x_p_c_uu);
// 	mlx_destroy_image(game->mlx, game->img.x_p_c_l);
// 	mlx_destroy_image(game->mlx, game->img.x_p_c_ll);
// 	mlx_destroy_image(game->mlx, game->img.x_p_c_d);
// 	mlx_destroy_image(game->mlx, game->img.x_p_c_dd);
// 	mlx_destroy_image(game->mlx, game->img.xpw);
// 	mlx_destroy_image(game->mlx, game->img.xpg);
// 	mlx_destroy_image(game->mlx, game->img.xpcoll);
// 	mlx_destroy_image(game->mlx, game->img.xpd);
// 	mlx_destroy_image(game->mlx, game->img.x_i_c);
// 	mlx_destroy_image(game->mlx, game->img.x_i_c_rr);
// 	mlx_destroy_image(game->mlx, game->img.x_i_c_u);
// 	mlx_destroy_image(game->mlx, game->img.x_i_c_uu);
// 	mlx_destroy_image(game->mlx, game->img.x_i_c_l);
// 	mlx_destroy_image(game->mlx, game->img.x_i_c_ll);
// 	mlx_destroy_image(game->mlx, game->img.x_i_c_d);
// 	mlx_destroy_image(game->mlx, game->img.x_i_c_dd);
// 	mlx_destroy_image(game->mlx, game->img.xiwal);
// 	mlx_destroy_image(game->mlx, game->img.xigro);
// 	mlx_destroy_image(game->mlx, game->img.xicol);
// 	mlx_destroy_image(game->mlx, game->img.xidoo);
// }

void free_images(t_game *game) {
    if (game->img.x_i_c) {
        mlx_destroy_image(game->mlx, game->img.x_i_c);
        game->img.x_i_c = NULL;
    }
    if (game->img.x_i_c_rr) {
        mlx_destroy_image(game->mlx, game->img.x_i_c_rr);
        game->img.x_i_c_rr = NULL;
    }
    if (game->img.x_i_c_u) {
        mlx_destroy_image(game->mlx, game->img.x_i_c_u);
        game->img.x_i_c_u = NULL;
    }
    if (game->img.x_i_c_uu) {
        mlx_destroy_image(game->mlx, game->img.x_i_c_uu);
        game->img.x_i_c_uu = NULL;
    }
    if (game->img.x_i_c_l) {
        mlx_destroy_image(game->mlx, game->img.x_i_c_l);
        game->img.x_i_c_l = NULL;
    }
    if (game->img.x_i_c_ll) {
        mlx_destroy_image(game->mlx, game->img.x_i_c_ll);
        game->img.x_i_c_ll = NULL;
    }
    if (game->img.x_i_c_d) {
        mlx_destroy_image(game->mlx, game->img.x_i_c_d);
        game->img.x_i_c_d = NULL;
    }
    if (game->img.x_i_c_dd) {
        mlx_destroy_image(game->mlx, game->img.x_i_c_dd);
        game->img.x_i_c_dd = NULL;
    }
    if (game->img.xiwal) {
        mlx_destroy_image(game->mlx, game->img.xiwal);
        game->img.xiwal = NULL;
    }
    if (game->img.xigro) {
        mlx_destroy_image(game->mlx, game->img.xigro);
        game->img.xigro = NULL;
    }
    if (game->img.xicol) {
        mlx_destroy_image(game->mlx, game->img.xicol);
        game->img.xicol = NULL;
    }
    if (game->img.xidoo) {
        mlx_destroy_image(game->mlx, game->img.xidoo);
        game->img.xidoo = NULL;
    }
}



// FREE 
int	free_game(t_game *game)
{
	int	nbr_of_lines;

	nbr_of_lines = 0;

	if (game == NULL)
		return (-1);

	if (game->map != NULL)
	{
		while (game->map[nbr_of_lines])
		{
			free(game->map[nbr_of_lines]);
			game->map[nbr_of_lines] = NULL;
            nbr_of_lines++;
		}
		free(game->map);
		game->map = NULL;
		ft_printf("game map freed successfully\n");
	}
	free_images(game);
	if (game->win != NULL)
	{
		mlx_destroy_window(game->mlx, game->win);
		game->win = NULL;
		ft_printf("window destroyed !\n");
	}
	if (game->mlx != NULL)
	{
        //free(game->mlx);
		mlx_destroy_display(game->mlx);
    	ft_printf("mlx destroy successfully\n");
		free(game->mlx);
		//game->mlx = NULL;
	}
    free(game);
    game = NULL;
    ft_printf("free game successful");
	exit (0);
}

