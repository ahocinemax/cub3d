/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsuji <mtsuji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 17:08:28 by mtsuji            #+#    #+#             */
/*   Updated: 2022/09/27 17:08:30 by mtsuji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_valid_position(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

int	ft_no_void(char c)
{
	return (c == '1' || c == '0');
}

int ft_check_void(t_cub3d *cub3d, char **map)
{
	if (!ft_no_void(map[cub3d->pos_y][cub3d->pos_x - 1]))
		ft_print_error(cub3d, MAP_ERROR);
	else if (!ft_no_void(map[cub3d->pos_y - 1][cub3d->pos_x]))
		ft_print_error(cub3d, MAP_ERROR);
	else if (!ft_no_void(map[cub3d->pos_y][cub3d->pos_x + 1]))
		ft_print_error(cub3d, MAP_ERROR);
	else if (!ft_no_void(map[cub3d->pos_y + 1][cub3d->pos_x]))
		ft_print_error(cub3d, MAP_ERROR);
	return (0);
}

int    check_player_position(char **map, t_cub3d *cub3d)
{
    int x;
    int y;

    y = 0;
    while (map[++y])
    {
        x = 0;
        while (map[y][++x])
        {
            if (ft_valid_position(map[y][x]))
            {
                cub3d->check_pos++;
                if (cub3d->check_pos > 1)
		            ft_print_error(cub3d, MAP_ERROR);
                cub3d->pos = map[y][x];
                cub3d->pos_x = x;
                cub3d->pos_y = y;
                ft_check_void(cub3d, map);
            }
        }
    }
    if (!cub3d->check_pos)
        ft_print_error(cub3d, MAP_ERROR);
    return (0);
} 

