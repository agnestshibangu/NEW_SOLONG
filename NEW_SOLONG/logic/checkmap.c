/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agtshiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 13:38:36 by agtshiba          #+#    #+#             */
/*   Updated: 2024/05/28 21:21:52 by agtshiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
		return (1);
	return (0);
}

int	does_file_exist(char *name)
{
	int		fd;

	fd = open(name, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("the file does not exist");
		return (0);
	}
	else
		return (1);
}

void	malloc_game(t_game *game)
{
	game = (t_game *)malloc(sizeof(t_game));
	if (game == NULL)
	{
		ft_printf("Allocation de mémoire pour game a échoué");
	}
}

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
