/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 14:50:22 by ahocine           #+#    #+#             */
/*   Updated: 2022/10/05 03:37:46 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_struct_pos(t_pos *pos)
{
	pos->check_pos = 0;
	pos->pos_x = 0;
	pos->pos_y = 0;
}

static void	init_player2(t_player *p1)
{
	p1->side = 0;
	p1->line_height = 0;
	p1->rot_speed = 0.15;
	p1->move_speed = 0.2;
	p1->tex_start = 0;
}

void	init_player(t_player *p1)
{
	p1->pos_x = 0;
	p1->pos_y = 0;
	p1->dir_x = 0;
	p1->dir_y = 0;
	p1->plane_x = 0;
	p1->plane_y = 0;
	p1->time = 0;
	p1->old_time = 0;
	p1->old_dir_x = 0;
	p1->old_plane_x = 0;
	p1->raydir_x = 0;
	p1->raydir_y = 0;
	p1->camera_x = 0;
	p1->map_x = 0;
	p1->map_y = 0;
	p1->step_x = 0;
	p1->step_y = 0;
	p1->check_pos = 0;
	p1->side_dist_x = 0;
	p1->side_dist_y = 0;
	p1->delta_dist_x = 0;
	p1->delta_dist_y = 0;
	p1->perp_wall_dist = 0;
	p1->hit = 0;
	init_player2(p1);
}

void	init_picture(t_pic *pic)
{
	pic->img = NULL;
	pic->width = 0;
	pic->height = 0;
}
