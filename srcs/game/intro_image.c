/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intro_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsuji <mtsuji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 15:43:07 by mtsuji            #+#    #+#             */
/*   Updated: 2022/10/01 15:43:09 by mtsuji           ###   ########.fr       */
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

void	left_key(t_cub3d *cub3d)
{
	cub3d->p1.old_dir_x = cub3d->p1.dir_x;
	cub3d->p1.dir_x = cub3d->p1.dir_x * cos(-cub3d->p1.rot_speed) - cub3d->p1.dir_y * sin(-cub3d->p1.rot_speed);
	cub3d->p1.dir_y = cub3d->p1.old_dir_x * sin(-cub3d->p1.rot_speed) + cub3d->p1.dir_y * cos(-cub3d->p1.rot_speed);
	cub3d->p1.old_plane_x = cub3d->p1.plane_x;
	cub3d->p1.plane_x = cub3d->p1.plane_x * cos(-cub3d->p1.rot_speed) - cub3d->p1.plane_y * sin(-cub3d->p1.rot_speed);
	cub3d->p1.plane_y = cub3d->p1.old_plane_x * sin(-cub3d->p1.rot_speed) + cub3d->p1.plane_y * cos(-cub3d->p1.rot_speed);
}

void	right_key(t_cub3d *cub3d)
{
	cub3d->p1.old_dir_x = cub3d->p1.dir_x;
	cub3d->p1.dir_x = cub3d->p1.dir_x * cos(cub3d->p1.rot_speed) - cub3d->p1.dir_y * sin(cub3d->p1.rot_speed);
	cub3d->p1.dir_y = cub3d->p1.old_dir_x * sin(cub3d->p1.rot_speed) + cub3d->p1.dir_y * cos(cub3d->p1.rot_speed);
	cub3d->p1.old_plane_x = cub3d->p1.plane_x;
	cub3d->p1.plane_x = cub3d->p1.plane_x * cos(cub3d->p1.rot_speed) - cub3d->p1.plane_y * sin(cub3d->p1.rot_speed);
	cub3d->p1.plane_y = cub3d->p1.old_plane_x * sin(cub3d->p1.rot_speed) + cub3d->p1.plane_y * cos(cub3d->p1.rot_speed);
}

int	key_press_other(int key, t_cub3d *cub3d)
{
	if (key == KEY_RIGHT && cub3d->step_of_game >= 2)
		right_key(cub3d);
	else if (key == KEY_LEFT && cub3d->step_of_game >= 2)
		left_key(cub3d);
	else if (key == KEY_RETURN && cub3d->step_of_game == 1)
		game_start(cub3d);
	else if (key == KEY_ESC)
		free_all_exit(cub3d);
	return (0);
}

int	key_press(int key, t_cub3d *cub3d)
{
	if (key == KEY_W && cub3d->step_of_game >= 2)
		w_key(cub3d);
	else if (key == KEY_S && cub3d->step_of_game >= 2)
		s_key(cub3d);
	else if (key == KEY_A && cub3d->step_of_game >= 2)
		a_key(cub3d);
	else if (key == KEY_D && cub3d->step_of_game >= 2)
		d_key(cub3d);
	return (key_press_other(key, cub3d));
}

void	introduction_of_game(t_cub3d *cub3d)
{
	img_intro(cub3d);
	mlx_key_hook(cub3d->window->win_ptr, &key_press, &cub3d);
	mlx_hook(cub3d->window->win_ptr, 17, 1L << 0, &free_all_exit, &cub3d);
	mlx_put_image_to_window(cub3d->mlx_ptr, cub3d->window->win_ptr, cub3d->intro.img, 0, 0);
	mlx_loop(cub3d->mlx_ptr);
}