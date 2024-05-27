/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agtshiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 12:34:23 by agtshiba          #+#    #+#             */
/*   Updated: 2024/05/27 15:45:07 by agtshiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	free_images_function(t_game *game, void **images, int images_count)
{
	int		i;

	i = 0;
	while (i < images_count)
	{
		if (images[i])
		{
			mlx_destroy_image(game->mlx, images[i]);
			images[i] = NULL;
		}
		i++;
	}
}

void	free_images(t_game *game)
{
	void	*images[12];
	int		images_count;

	images[0] = game->img.x_i_c;
	images[1] = game->img.x_i_c_rr;
	images[2] = game->img.x_i_c_u;
	images[3] = game->img.x_i_c_uu;
	images[4] = game->img.x_i_c_l;
	images[5] = game->img.x_i_c_ll;
	images[6] = game->img.x_i_c_d;
	images[7] = game->img.x_i_c_dd;
	images[8] = game->img.xiwal;
	images[9] = game->img.xigro;
	images[10] = game->img.xicol;
	images[11] = game->img.xidoo;
	images_count = sizeof(images) / sizeof(images[0]);
	free_images_function(game, images, images_count);
	ft_printf("all images freed");
}

void	free_mlx(t_game *game)
{
	free_images(game);
	if (game->win != NULL)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx != NULL)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		game->mlx = NULL;
	}
}

// FREE - debbug I need to find a solution to free the game 
int	free_game(t_game *game)
{
	int	nbr_of_lines;

	nbr_of_lines = 0;
	if (game == NULL)
		return (-1);
	if (game->map != NULL)
	{
		while (nbr_of_lines < game->map_height)
		{
			free(game->map[nbr_of_lines]);
			game->map[nbr_of_lines] = NULL;
			nbr_of_lines++;
		}
		free(game->map);
	}
	free_mlx(game);
	exit (0);
	return (0);
}
