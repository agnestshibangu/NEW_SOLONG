/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agtshiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 13:12:40 by agtshiba          #+#    #+#             */
/*   Updated: 2024/05/20 22:30:28 by agtshiba         ###   ########.fr       */
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


int 	create_map(t_game *game) {
   
    int fd;
    char *treated_line;
    const char *name_file = "./ber_files/file2.ber";
	int i;

	i = 0;
    fd = open(name_file, O_RDONLY);
    if (fd < 0) {
        return (0);
    }
    ft_memset(game, 0, sizeof(t_game));
    treated_line = get_next_line(fd);
    if (!treated_line) {
        close(fd);
        return (0);
    }
    while (treated_line) {
        save_line_in_map(game, treated_line);
        free(treated_line);
        treated_line = get_next_line(fd);
		i++;
    }
    close(fd);
	return (1);
}

int		map_len(t_game *game)
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

void 	display_map(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width - 1)
		{
			ft_printf("%c", game->map[y][x]);
			x++;
		}
		ft_printf("\n");
		y++;
	}
}

void	display_image_before(t_game *game, char *path)
{
	void	*img;
	img = mlx_xpm_file_to_image(game->mlx, path, &game->win_w, &game->win_h);
	if (!img){
		return ;
	}
	mlx_put_image_to_window(game->mlx, game->win, img, 0, 0);
	mlx_do_sync(game->mlx);
	usleep(3000000);
	mlx_destroy_image(game->mlx, img);
	mlx_clear_window(game->mlx, game->win);
	// mlx_destroy_window(game->mlx, game->win);
}

void	window_init(t_game *game)
{
	int	win_w;
	int	win_h;

	ft_printf("window init width %d\n", game->map_width);
	ft_printf("window init height %d", game->map_height);

	win_w = (game->map_width - 1) * 31;
	win_h = game->map_height * 31;
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, win_w, win_h, "game map");
	//ft_printf("window size");
}

void	init_images_character(t_game *game)
{
	t_game	*g;
	void	*m;
	int		*h;
	int		*w;

	g = game;
	m = g->mlx;
	h = &g->x_h;
	w = &g->x_w;
	g->img.x_p_c = "./images/perso.xpm";
	g->img.x_p_c_rr = "./images/perso_right_right.xpm";
	g->img.x_p_c_u = "./images/perso_up.xpm";
	g->img.x_p_c_uu = "./images/perso_up_up.xpm";
	g->img.x_p_c_l = "./images/perso_left.xpm";
	g->img.x_p_c_ll = "./images/perso_left_left.xpm";
	g->img.x_p_c_d = "./images/perso_down.xpm";
	g->img.x_p_c_dd = "./images/perso_down_down.xpm";
	g->img.x_i_c = mlx_xpm_file_to_image(m, g->img.x_p_c, w, h);
	g->img.x_i_c_rr = mlx_xpm_file_to_image(m, g->img.x_p_c_rr, w, h);
	g->img.x_i_c_u = mlx_xpm_file_to_image(m, g->img.x_p_c_u, w, h);
	g->img.x_i_c_uu = mlx_xpm_file_to_image(m, g->img.x_p_c_uu, w, h);
	g->img.x_i_c_l = mlx_xpm_file_to_image(m, g->img.x_p_c_l, w, h);
	g->img.x_i_c_ll = mlx_xpm_file_to_image(m, g->img.x_p_c_ll, w, h);
	g->img.x_i_c_d = mlx_xpm_file_to_image(m, g->img.x_p_c_d, w, h);
	g->img.x_i_c_dd = mlx_xpm_file_to_image(m, g->img.x_p_c_dd, w, h);
}

void init_images_obj(t_game *game)
{
	t_game *g;
	void	*m;
	int		*h;
	int		*w;

	g = game;
	m = g->mlx;
	h = &g->x_h;
	w = &g->x_w;
	g->img.xpw = "./images/wall.xpm";
	g->img.xpg = "./images/ground.xpm";
	g->img.xpcoll = "./images/collectible.xpm";
	g->img.xpd = "./images/portal.xpm";
	g->img.xiwal = mlx_xpm_file_to_image(m, g->img.xpw, w, h);
	g->img.xigro = mlx_xpm_file_to_image(m, g->img.xpg, w, h);
	g->img.xicol = mlx_xpm_file_to_image(m, g->img.xpcoll, w, h);
	g->img.xidoo = mlx_xpm_file_to_image(m, g->img.xpd, w, h);
}

void 	initialize_window(t_game *game)
{
	window_init(game);
	init_images_character(game);
	init_images_obj(game);
	display_player_pos(game);
}