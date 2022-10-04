/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct_game.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsuji <mtsuji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:34:10 by mtsuji            #+#    #+#             */
/*   Updated: 2022/09/28 16:34:12 by mtsuji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	set_player_view(t_cub3d *cub3d, t_player *p1)
{
	if (cub3d->pos.pos == 'N')
	{
		p1->dir_x = 0;
		p1->dir_y = -1;
		p1->plane_x = -0.66;
		p1->plane_y = 0;
	}
	else if (cub3d->pos.pos == 'S')
	{
		p1->dir_x = 0;
		p1->dir_y = 1;
		p1->plane_x = -0.66;
		p1->plane_y = 0;
	}
    	if (cub3d->pos.pos == 'W')
	{
		p1->dir_x = -1;
		p1->dir_y = 0;
		p1->plane_x = 0;
		p1->plane_y = -0.66;
	}
	else if (cub3d->pos.pos == 'E')
	{
		p1->dir_x = 1;
		p1->dir_y = 0;
		p1->plane_x = 0;
		p1->plane_y = -0.66;
	}
}
