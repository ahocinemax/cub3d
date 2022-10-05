/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_adsw.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuji <mtsuji@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 03:52:42 by msuji             #+#    #+#             */
/*   Updated: 2022/10/05 03:52:46 by msuji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	w_key(t_cub3d *cub3d)
{
	double	x1;
	double	y1;
	double	x2;
	double	y2;

	x1 = (cub3d->p1.pos_x + cub3d->p1.dir_x * cub3d->p1.move_speed);
	y2 = (cub3d->p1.pos_y + cub3d->p1.dir_y * cub3d->p1.move_speed);
	x2 = (cub3d->p1.pos_x);
	y1 = (cub3d->p1.pos_y);
	if (cub3d->map.map[(int)y1][(int)(x1)] != '1')
		cub3d->p1.pos_x = x1;
	if (cub3d->map.map[(int)y2][(int)x2] != '1')
		cub3d->p1.pos_y = y2;
}

void	s_key(t_cub3d *cub3d)
{
	double	x1;
	double	y1;
	double	x2;
	double	y2;

	x1 = (cub3d->p1.pos_x - cub3d->p1.dir_x * cub3d->p1.move_speed);
	y2 = (cub3d->p1.pos_y - cub3d->p1.dir_y * cub3d->p1.move_speed);
	x2 = (cub3d->p1.pos_x);
	y1 = (cub3d->p1.pos_y);
	if (cub3d->map.map[(int)y1][(int)(x1)] != '1')
		cub3d->p1.pos_x = x1;
	if (cub3d->map.map[(int)y2][(int)x2] != '1')
		cub3d->p1.pos_y = y2;
}

void	a_key(t_cub3d *cub3d)
{
	double	x1;
	double	y1;
	double	x2;
	double	y2;

	x1 = (cub3d->p1.pos_x + cub3d->p1.dir_y * cub3d->p1.move_speed);
	y2 = (cub3d->p1.pos_y - cub3d->p1.dir_x * cub3d->p1.move_speed);
	x2 = (cub3d->p1.pos_x);
	y1 = (cub3d->p1.pos_y);
	if (cub3d->map.map[(int)y1][(int)(x1)] != '1')
		cub3d->p1.pos_x = x1;
	if (cub3d->map.map[(int)y2][(int)x2] != '1')
		cub3d->p1.pos_y = y2;
}

void	d_key(t_cub3d *cub3d)
{
	double	x1;
	double	y1;
	double	x2;
	double	y2;

	x1 = (cub3d->p1.pos_x - cub3d->p1.dir_y * cub3d->p1.move_speed);
	y2 = (cub3d->p1.pos_y + cub3d->p1.dir_x * cub3d->p1.move_speed);
	x2 = (cub3d->p1.pos_x);
	y1 = (cub3d->p1.pos_y);
	if (cub3d->map.map[(int)y1][(int)(x1)] != '1')
		cub3d->p1.pos_x = x1;
	if (cub3d->map.map[(int)y2][(int)x2] != '1')
		cub3d->p1.pos_y = y2;
}
