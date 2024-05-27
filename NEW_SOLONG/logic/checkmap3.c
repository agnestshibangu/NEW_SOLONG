/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agtshiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:44:33 by agtshiba          #+#    #+#             */
/*   Updated: 2024/05/27 12:42:42 by agtshiba         ###   ########.fr       */
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

int	count_exit_and_caracter(t_game *game)
{
	int	y;
	int	x;
	int	nb_exit;
	int	nb_caracter;

	nb_exit = 0;
	nb_caracter = 0;
	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width - 1)
		{
			if (game->map[y][x] == 'E')
				nb_exit += 1;
			else if (game->map[y][x] == 'P')
				nb_caracter += 1;
			x++;
		}
		y++;
	}
	if (nb_exit > 1 || nb_caracter > 1)
		return (0);
	return (1);
}

int	check_map(t_game *game)
{
	if (!check_if_rectangle(game))
	{
		ft_printf("Error: map not rectangle\n");
		fflush(stdout);
		return (0);
	}
	if (!check_allowed_caracters(game))
	{
		ft_printf("Error: unallowed caracters\n");
		fflush(stdout);
		return (0);
	}
	if (!count_exit_and_caracter(game))
	{
		ft_printf("Error: more than one exit OR one caracter\n");
		fflush(stdout);
		return (0);
	}
	return (1);
}

int	check_walls(t_game *game)
{
	if (!check_walls_horizontal(game))
	{
		ft_printf("Error: horizontal walls\n");
		fflush(stdout);
		return (0);
	}
	if (!check_walls_vertical(game))
	{
		ft_printf("Error: vertical walls\n");
		fflush(stdout);
		return (0);
	}
	if (!count_collectibles(game))
	{
		ft_printf("Error: Not enought collectibles\n");
		fflush(stdout);
		return (0);
	}
	return (1);
}

int	create_map_for_game(t_game *game, t_gamefile *gamefile)
{
	if (!create_map(game, gamefile))
	{
		ft_printf("Error: Failed to create map\n");
		fflush(stdout);
		return (0);
	}
	map_len(game);
	if (!check_walls(game))
		return (0);
	if (!check_map(game))
		return (0);
	return (1);
}
