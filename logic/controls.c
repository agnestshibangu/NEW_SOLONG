/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agtshiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 21:51:07 by agtshiba          #+#    #+#             */
/*   Updated: 2024/05/20 22:02:01 by agtshiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	display_player_pos(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width - 1)
		{
			if (game->map[y][x] == 'P')
			{
				game->player_pos_x = x;
				game->player_pos_y = y;
				game->map[y][x] = '0';
				return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}

void	portal(t_game *game)
{
	char	*path;
	path = "./images_op_end/image_end.xpm";
	if (game->got_collectibles == game->nb_collectibles
		&& game->map[game->player_pos_y][game->player_pos_x] == 'E')
	{
		free_game(game);
	}
}

void	walking(t_game *game)
{
	game->steps += 1;
}

int	move_right(t_game *game)
{
	int	x;
	int	y;

	x = game->player_pos_x;
	y = game->player_pos_y;
	if (game->map[y][x + 1] == '1')
		return (0);
	else
	{
		game->player_pos_x += 1;
		game->player_sprite = 0;
		walking(game);
		if (game->map[y][x + 1] == 'C')
		{
			game->got_collectibles++;
			game->map[y][x + 1] = '0';
		}
	}
	drawGrid(game);
	portal(game);
	return (0);
}

int	move_left(t_game *game)
{
	int	x;
	int	y;

	x = game->player_pos_x;
	y = game->player_pos_y;
	if (game->map[y][x - 1] == '1')
		return (0);
	else
	{
		game->player_pos_x -= 1;
		game->player_sprite = 2;
		walking(game);
		if (game->map[y][x - 1] == 'C')
		{
			game->got_collectibles++;
			game->map[y][x - 1] = '0';
		}
	}
	drawGrid(game);
	portal(game);
	return (0);
}
