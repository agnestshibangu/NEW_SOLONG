/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agtshiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:44:33 by agtshiba          #+#    #+#             */
/*   Updated: 2024/05/17 15:44:35 by agtshiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	count_collectibles(t_game *game)
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
	if (game->nb_collectibles < 1)
	{
		return (0);
	}
	return (1);
}

int	check_map(t_game *game)
{
	if(!check_walls_horizontal(game))
	{
		ft_printf("Error: horizontal walls\n");
		return (0);
	}
	if (!check_walls_vertical(game))
	{
		ft_printf("Error: vertical walls\n");
		return (0);
	}
	if (!check_allowed_caracters(game))
	{
		ft_printf("Error: unallowed caracters\n");
		return (0);
	}
	if (!check_if_rectangle(game))
	{
		ft_printf("Error: map not rectangle\n");
		return (0);
	}
	ft_printf(" !!! checking map DONE !!!");
	return (0);
}

int 	create_map_for_game(t_game *game, t_gamefile *gamefile)
{
	if (!create_map(game, gamefile))
	{
		ft_printf("Error: Failed to create map\n");
		return (0);
	}
    if (!map_len(game))
	{
		ft_printf("Error: Failed to calculate map length\n");
		return (0);
	}
    check_map(game);
    if (!count_collectibles(game))
	{
		ft_printf("Error: Not enought collectibles\n");
		return (0);
	}
	ft_printf(" !!! creating the map DONE !!!");
	return (1);
}