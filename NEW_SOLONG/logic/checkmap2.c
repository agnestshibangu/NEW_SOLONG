/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agtshiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 13:59:48 by agtshiba          #+#    #+#             */
/*   Updated: 2024/05/26 19:44:05 by agtshiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_walls_horizontal(t_game *game)
{
	int	height;
	int	len;
	int	i;

	len = game->map_width;
	height = game->map_height;
	i = 0;
	while (i < len - 1)
	{
		if (game->map[0][i] != '1' || game->map[height - 1][i] != '1')
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_walls_vertical(t_game *game)
{
	int	height;
	int	len;
	int	i;

	len = game->map_width - 1;
	height = game->map_height;
	i = 0;
	while (i < height)
	{
		if (game->map[i][len - 1] != '1' || game->map[i][0] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_allowed_caracters(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width - 1)
		{
			if (game->map[y][x] != '1' && game->map[y][x] != '0' &&
				game->map[y][x] != 'P' && game->map[y][x] != 'E' &&
					game->map[y][x] != 'C')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	check_if_rectangle(t_game *game)
{
	int	init_len;
	int	y;
	int	x;

	init_len = game->map_width - 1;
	y = 0;
	while (y < game->map_height - 1)
	{
		x = 0;
		while (x < init_len)
			x++;
		if (x != init_len)
			return (0);
		y++;
	}
	x = 0;
	return (1);
}
