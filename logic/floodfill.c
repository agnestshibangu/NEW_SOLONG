/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agtshiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 12:35:39 by agtshiba          #+#    #+#             */
/*   Updated: 2024/05/26 20:05:27 by agtshiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	map_free_after_flood_fill(t_game *game)
{
	int		nbr_of_lines;

	nbr_of_lines = 0;
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
	return (1);
}

void	flood_map(t_game *game, int x, int y)
{
	if (game->map[y][x] == 'P' || game->map[y][x] == '1' || game->map[y][x] == 'F')
		return ;
	game->map[y][x] = 'F';
	flood_map(game, x, y + 1);
	flood_map(game, x, y - 1);
	flood_map(game, x + 1, y);
	flood_map(game, x - 1, y);
}

int	check_flood_fill(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	flood_map(game, game->player_pos_x, game->player_pos_y);
	ft_printf("flood map done\n");
	while (i < game->map_height)
	{
		while (j < game->map_width)
		{
			if (game->map[i][j] == 'C' || game->map[i][j] == 'E')
			{
				return (0);
			}
			ft_printf("%c", game->map[i][j]);
			j++;
		}
		i++;
		j = 0;
	}
	ft_printf("\n");
	ft_printf("CHECK FLOOD FILL DONE \n");
	return (1);
}

int	check_flood_fill_map(t_game *game, t_gamefile *gamefile)
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
	if (!check_map(game))
	{
		fflush(stdout);
		ft_printf("Error: Found error while checking map\n");
		return (0);
	}
	if (!display_player_pos(game))
	{
		ft_printf("Error: Failed to retreive player position\n");
		return (0);
	}
	flood_map(game, game->player_pos_x, game->player_pos_y);
	if (!check_flood_fill(game))
	{
		ft_printf("Error: Failed flood map\n");
		return (0);
	}
	if (!map_free_after_flood_fill(game))
	{
		ft_printf("Error: Failed to free map after flood fill\n");
		return (0);
	}
	ft_printf(" !!! check flood fill DONE !!!");
	return (1);
}
