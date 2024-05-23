/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agtshiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 13:38:36 by agtshiba          #+#    #+#             */
/*   Updated: 2024/05/17 13:57:55 by agtshiba         ###   ########.fr       */
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

void 	calculate_height_map(t_game *game)
{
	int		fd;
	int 	height;
	char	*treated_line;
	char	*name_file;

	height = 0;
	name_file = "./ber_files/file2.ber";
	check_extension_file_name(name_file);
	fd = open(name_file, O_RDONLY);
	// ft_memset(game, 0, sizeof(t_game));
	treated_line = get_next_line(fd);	
	if (!treated_line)
	{
			close(fd);
			return ;
	}
	while (treated_line){
		height++;
		free(treated_line);
		treated_line = get_next_line(fd);	
	}
	game->map_height = height;
	ft_printf("%d\n",height);
	close(fd);
}


// ALLOC
void	malloc_game(t_game *game)
{
	game = (t_game *)malloc(sizeof(t_game));
	if (game == NULL)
	{
		ft_printf("Allocation de mémoire pour game a échoué");
	}
}

int	calculate_len(t_game *game, char *line)
{
	int	len;

	len = 0;
	while (line[len])
		len++;
	game->map_width = len;
	return (0);
}

// ALLOC

static int save_line_in_map(t_game *game, char *line)
{
    char **temp;
    int i = 0;
	

    if (!line)
        return (0);
    game->map_height++;
	// allocating temp to size of map plus NULL
    temp = (char **)malloc(sizeof(char *) * (game->map_height + 1));
	 if (!temp)
        return (0);
    temp[game->map_height - 1] = NULL;

	// while map, pass everything in temp
    while (i < game->map_height - 1)
    {
        temp[i] = game->map[i];
        i++;
    }
	// pass new line in temp
	temp[i] = ft_strdup(line);
	// if temp NULL, free temp
	if (!temp[i])
	{
    	//If strdup fails, free the already allocated memory
		int y = 0;
		while (y < game->map_height)
		{
			free(temp[y]);
			y++;
		}  
		free(temp);
		return (0);
	}
	// free game
	if (game->map)
        free(game->map);
	// pass content of temp in game->map
    game->map = temp;
	
    return (1);
}


int	check_rectangle(t_game *game)
{
	int	height;
	int	i;

	height = game->map_height;
	i = 0;
	while (i < height)
		i++;
	return (1);
}
