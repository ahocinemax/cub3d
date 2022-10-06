/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsuji <mtsuji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:55:09 by mtsuji            #+#    #+#             */
/*   Updated: 2022/10/05 18:19:54 by mtsuji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	wall_x(t_player *p1)
{
	if (p1->side == EAST || p1->side == WEST)
		p1->wall_x = p1->pos_y + p1->perp_wall_dist * p1->raydir_y;
	else
		p1->wall_x = p1->pos_x + p1->perp_wall_dist * p1->raydir_x;
	p1->wall_x = floor(p1->wall_x);
}

void	prepare_wall(t_cub3d *cub3d, int x, int draw_start, int draw_end)
{
	int	start;

	(void)draw_start;
	(void)draw_end;
	start = 0;
	wall_x(&(cub3d->p1));
	if (cub3d->p1.check_pos == 'N' || cub3d->p1.check_pos == 'E')
		x = cub3d->window.width - x - 1;
	while (start < draw_start)
	{
	}
}
//preparetion_image floor + celling;
