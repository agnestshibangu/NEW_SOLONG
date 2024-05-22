/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agtshiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 13:59:48 by agtshiba          #+#    #+#             */
/*   Updated: 2024/05/20 21:24:42 by agtshiba         ###   ########.fr       */
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
	while (i < len)
	{
		if (game->map[height - 1][i] != '1' || game->map[0][i] != '1')
			return (0);
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

int	check_if_rectancle(t_game *game)
{
	int	init_len;
	int	y;
	int	x;

	init_len = 0;
	y = 1;
	while (game->map[0][init_len])
		init_len++;
	while (y < game->map_height)
	{
		x = 0;
		while (game->map[y][x])
			x++;
		if (x != init_len)
			return (0);
		y++;
	}
	x = 0;
	while (game->map[game->map_height - 1][x])
		x++;
	if (x != init_len + 1)
		return (0);
	return (1);
}

int	check_extension_file_name(char *name)
{
	int			i;
	int			y;
	const char	*needle;

	i = 0;
	y = 0;
	needle = ".ber";
	while (name[i])
	{
		if (name[i] == needle[y])
			y++;
		i++;
	}
	if (y == 4 && name[i] == '\0')
		ft_printf("extension ok\n");
	return (0);
}
