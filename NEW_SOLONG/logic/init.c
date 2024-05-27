/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agtshiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 13:12:40 by agtshiba          #+#    #+#             */
/*   Updated: 2024/05/27 16:16:37 by agtshiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memset(void *b, int c, size_t length)
{
	unsigned char	*p;

	p = (unsigned char *)b;
	while (length--)
	{
		*p++ = (unsigned char)c;
	}
	return (b);
}

// allocating temp to size of map plus NULL
// while map, pass everything in temp
// pass new line in temp
// if temp NULL, free temp
// if strdup fails, free the already allocated memory
// free game
// pass content of temp in game->map
static int if_temp_null(t_game *game, char **temp)
{
	int		y;

	if (!temp)
	{
		y = 0;
		while (y < game->map_height)
		{
			free(temp[y]);
			y++;
		}
			
		free(temp);
		return (0);
	}
	return (1);
}

static char  **manage_temp(t_game *game, char *line)
{
	char	**temp;
	int		i;
	
	i = 0;
	temp = (char **)malloc(sizeof(char *) * (game->map_height + 1));
	if (!temp)
		return (0);
	temp[game->map_height - 1] = NULL;
	while (i < game->map_height - 1)
	{
		temp[i] = game->map[i];
		i++;
	}
	temp[i] = ft_strdup(line);
	if (!temp[i])
	{
		if_temp_null(game, temp);
		return (NULL);
	}
	return (temp);
}

static int	save_line_in_map(t_game *game, char *line)
{
	char 	**temp;
	if (!line)
		return (0);
	game->map_height++;
	temp = manage_temp(game, line);
	if (game->map)
		free(game->map);
	game->map = temp;
	return (1);
}

int	create_map(t_game *game, t_gamefile *gamefile)
{
	int		fd;
	int		i;	
	char	*treated_line;

	i = 0;
	fd = open(gamefile->map_file, O_RDONLY);
	if (fd < 0)
		return (0);
	ft_memset(game, 0, sizeof(t_game));
	treated_line = get_next_line(fd);
	if (!treated_line)
	{
		close(fd);
		return (0);
	}
	while (treated_line)
	{
		save_line_in_map(game, treated_line);
		free(treated_line);
		treated_line = get_next_line(fd);
		i++;
	}
	close(fd);
	return (1);
}

int	map_len(t_game *game)
{
	int	len;

	len = 0;
	while (game->map[0][len])
		len++;
	if (len < 3)
		return (0);
	game->map_width = len;
	return (1);
}

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
				return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}
