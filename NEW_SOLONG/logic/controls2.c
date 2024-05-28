/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agtshiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 22:02:39 by agtshiba          #+#    #+#             */
/*   Updated: 2024/05/26 19:57:02 by agtshiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	move_up(t_game *game)
{
	int	x;
	int	y;

	x = game->player_pos_x;
	y = game->player_pos_y;
	if (game->map[y - 1][x] == '1')
		return (0);
	else
	{
		game->player_pos_y -= 1;
		game->player_sprite = 1;
		walking(game);
		if (game->map[y - 1][x] == 'C')
		{
			game->got_collectibles++;
			game->map[y - 1][x] = '0';
		}
	}
	draw_grid(game);
	portal(game);
	return (0);
}

int	move_down(t_game *game)
{
	int	x;
	int	y;

	x = game->player_pos_x;
	y = game->player_pos_y;
	if (game->map[y + 1][x] == '1')
		return (0);
	else
	{
		game->player_pos_y += 1;
		game->player_sprite = 3;
		walking(game);
		if (game->map[y + 1][x] == 'C')
		{
			game->got_collectibles++;
			game->map[y + 1][x] = '0';
		}
	}
	draw_grid(game);
	portal(game);
	return (0);
}

int	close_window(t_game *game)
{
	ft_printf("ESC");
	mlx_destroy_window(game->mlx, game->win);
	return (0);
}

// void init_display(t_game *game)
// {
//     game->dpy = XOpenDisplay(NULL);
//     if (!game->dpy)
//     {
//         fprintf(stderr, "Unable to open X display\n");
//         exit(1);
//     }
//}

int	controls_working(int keysym, t_game *game)
{
	if (keysym == XK_d)
	{
		move_right(game);
	}
	else if (keysym == XK_a)
	{
		move_left(game);
	}
	else if (keysym == XK_w)
	{
		move_up(game);
	}
	else if (keysym == XK_s)
	{
		move_down(game);
	}
	else if (keysym == XK_Escape)
	{
		close_window(game);
	}
	return (1);
}

void	run_game(t_game *game)
{
	draw_grid(game);
	mlx_key_hook(game->win, controls_working, game);
	mlx_hook(game->win, 17, 0, close_window, game);
	mlx_loop(game->mlx);
	// XCloseDisplay(game->dpy);
}
