/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agtshiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 12:35:39 by agtshiba          #+#    #+#             */
/*   Updated: 2024/05/17 12:51:19 by agtshiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// FREE
int	map_free_after_flood_fill(t_game *game)
{
	int	nbr_of_lines;

	nbr_of_lines = 0;
	if (game->map != NULL)
	{
		while (game->map[nbr_of_lines++])
			free(game->map[nbr_of_lines]);
		free(game->map);
	}
	ft_memset(game, 0, sizeof(t_game));
	return (0);
}

void	map_len(t_game *game)
{
	int	len;

	len = 0;
	while (game->map[0][len])
		len++;
	game->map_width = len;
	ft_printf("map len : %d", game->map_width);
}

void	flood_map(t_game *game, int x, int y)
{
	if (game->map[y][x] == '1' || game->map[y][x] == 'F')
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
	while (game->map[i])
	{
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'C' || game->map[i][j] == 'E')
			{
				ft_printf(" ! error flood fill error ! ");
				return (-1);
			}
			ft_printf("%c", game->map[i][j]);
			j++;
		}
		i++;
		j = 0;
	}
	ft_printf("\n");
	ft_printf("CHECK FLOOD FILL DONE \n");
	return (0);
}

int	check_flood_fill_map(t_game *game)
{
	ft_printf("coucou");
	create_map(game);
	map_len(game);
	display_player_pos(game);
	flood_map(game, game->player_pos_x, game->player_pos_y);
	check_flood_fill(game);
	map_free_after_flood_fill(game);
	ft_printf("\n");
	ft_printf(" !!! check flood fill DONE !!!");
	return (1);
}
