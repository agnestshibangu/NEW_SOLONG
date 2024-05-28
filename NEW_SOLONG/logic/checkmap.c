/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agtshiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 13:38:36 by agtshiba          #+#    #+#             */
/*   Updated: 2024/05/26 19:42:25 by agtshiba         ###   ########.fr       */
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

int does_file_exist(char *name)
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
