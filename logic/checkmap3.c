/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agtshiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:44:33 by agtshiba          #+#    #+#             */
/*   Updated: 2024/05/17 15:44:35 by agtshiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_map(t_game *game)
{
	check_walls_horizontal(game);
	check_walls_vertical(game);
	check_allowed_caracters(game);
	check_if_rectancle(game);
	return (0);
}
