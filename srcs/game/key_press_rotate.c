/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 21:23:08 by ahocine           #+#    #+#             */
/*   Updated: 2022/10/07 21:23:10 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	left_key(t_cub3d *cub3d)
{
	cub3d->p1.old_dir_x = cub3d->p1.dir_x;
	cub3d->p1.dir_x = cub3d->p1.dir_x * cos(-cub3d->p1.rot_speed) - \
	cub3d->p1.dir_y * sin(-cub3d->p1.rot_speed);
	cub3d->p1.dir_y = cub3d->p1.old_dir_x * sin(-cub3d->p1.rot_speed) + \
	cub3d->p1.dir_y * cos(-cub3d->p1.rot_speed);
	cub3d->p1.old_plane_x = cub3d->p1.plane_x;
	cub3d->p1.plane_x = cub3d->p1.plane_x * cos(-cub3d->p1.rot_speed) - \
	cub3d->p1.plane_y * sin(-cub3d->p1.rot_speed);
	cub3d->p1.plane_y = cub3d->p1.old_plane_x * sin(-cub3d->p1.rot_speed) + \
	cub3d->p1.plane_y * cos(-cub3d->p1.rot_speed);
}

void	right_key(t_cub3d *cub3d)
{
	cub3d->p1.old_dir_x = cub3d->p1.dir_x;
	cub3d->p1.dir_x = cub3d->p1.dir_x * cos(cub3d->p1.rot_speed) - \
	cub3d->p1.dir_y * sin(cub3d->p1.rot_speed);
	cub3d->p1.dir_y = cub3d->p1.old_dir_x * sin(cub3d->p1.rot_speed) + \
	cub3d->p1.dir_y * cos(cub3d->p1.rot_speed);
	cub3d->p1.old_plane_x = cub3d->p1.plane_x;
	cub3d->p1.plane_x = cub3d->p1.plane_x * cos(cub3d->p1.rot_speed) - \
	cub3d->p1.plane_y * sin(cub3d->p1.rot_speed);
	cub3d->p1.plane_y = cub3d->p1.old_plane_x * sin(cub3d->p1.rot_speed) + \
	cub3d->p1.plane_y * cos(cub3d->p1.rot_speed);
}
