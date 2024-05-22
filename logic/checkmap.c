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
// static int save_line_in_map(t_game *game, char *line) {
//     char **new_map;

//     if (!line)
//         return 0;

//     Increment map height
//     game->map_height++;

//     Reallocate memory for the map to accommodate the new line
//     new_map = (char **)realloc(game->map, sizeof(char *) * game->map_height);
//     if (!new_map)
//         return 0; // Memory reallocation failed

//     new_map[game->map_height - 1] = ft_strdup(line); 

//     game->map = new_map;

//     return 1;
// }


// static int save_line_in_map(t_game *game, char *line)
// {
// 	char	**temporary;
// 	int		i;

// 	if (!line)
// 		return (0);
// 	i = 0;
// 	 game->map_height++;
// 	temporary = (char **)malloc(sizeof(char *) * ( game->map_height + 1));
// 	temporary[ game->map_height] = NULL;
// 	while (i <  game->map_height - 1)
// 	{
// 		temporary[i] = game->map[i];
// 		i++;
// 	}
// 	temporary[i] = line;
// 	if (game->map)
// 		free(game->map);
// 	game->map = temporary;
// 	return (1);
// }

static int save_line_in_map(t_game *game, char *line)
{
    char **temp;
    int i = 0;

	//ft_printf("game map height %d \n\n", game->map_height);

    if (!line)
        return (0);

    ft_printf("save line in map\n");
    ft_printf("%s\n", line);

    game->map_height++;
    ft_printf("game map height %d \n\n", game->map_height);
    temp = (char **)malloc(sizeof(char *) * (game->map_height + 1));
    temp[game->map_height] = NULL;

    while (i < game->map_height - 1)
    {
		ft_printf("MAP i am in map : %s\n", game->map[i]);
        temp[i] = game->map[i];
		//ft_printf("TEMP i am in map : %s\n", temp[i]);
        i++;
    }

    // Assign the new line to temp
    temp[i] = ft_strdup(line);
	i = 0;
	while (i < game->map_height)
    {
        
    	ft_printf("TEMP i am in map : %s\n", temp[i]);
        i++;
    }
    ft_printf("je suis ici %s\n", temp[i]);

    if (game->map)
    {
        free(game->map);
        ft_printf("the map array has been freed\n");
    }
    game->map = temp;

	i = 0;
	 while (i < game->map_height)
    {
        
    	ft_printf("LOOP i am in map : %s\n", game->map[i]);
        i++;
    }
    return (1);
}


// static int	save_line_in_map(t_game *game, char *line)
// {
// 	char	**temp;
// 	int		i = 0;
// 	//int 	nbr_of_lines = 0;
	
// 	if (!line)
// 		return (0);
// 	ft_printf("save line in map\n");
// 	ft_printf(line);
// 	ft_printf("\n");

// 	game->map_height++;
// 	ft_printf("game map height %d \n\n", game->map_height);

// 	temp = (char **)malloc(sizeof(char *) * (game->map_height + 1));
// 	temp[game->map_height] = NULL;
// 	//int y = 0;
// 	// if (game->map_height > 1)
// 	// {
// 	// 	ft_printf("PRINT EXISTING MAP\n");
// 	// 	while (y < game->map_height)
// 	// 	{
// 	// 		ft_printf("%s\n", game->map[nbr_of_lines]);
// 	// 		y++;
// 	// 	}
// 	// }

// 	// while (i < game->map_height - 1)
// 	// {
// 	//  	temp[i] = game->map[i];
// 	//  	i++;
// 	// }
// 	temp = (char **)malloc(sizeof(char *) * (game->map_height + 1));
// 	temp[game->map_height] = NULL;
	
// 	// free map 
// 	// if (game->map != NULL) {
//     //     while (nbr_of_lines < game->map_height) {
//     //         ft_printf("Freeing line %d: %s\n", nbr_of_lines, game->map[nbr_of_lines]);
//     //         free(game->map[nbr_of_lines]);
//     //         game->map[nbr_of_lines] = NULL;
//     //         nbr_of_lines++;
//     //     }
//     //     ft_printf("All lines freed.\n\n\n");
//     //     //free(game->map);
//     // }
// 	game->map[0] = temp[0];
// 	ft_printf("%s", game->map[0]);


	
// 	ft_printf("i am in map : %s", game->map[0]);
	
// 	return (1);
// }

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
