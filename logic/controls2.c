/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agtshiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 22:02:39 by agtshiba          #+#    #+#             */
/*   Updated: 2024/05/20 22:09:49 by agtshiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	drawGrid(game);
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
	drawGrid(game);
	portal(game);
	return (0);
}

int	controls_working(int command, t_game *game)
{
	if (command == 100)
	{
		move_right(game);
	}
	else if (command == 97)
	{
		move_left(game);
	}
	else if (command == 119)
	{
		move_up(game);
	}
	else if (command == 115)
	{
		move_down(game);
	}
	return (1);
}
