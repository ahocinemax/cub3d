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


void	w_key(t_game *game)
{
	double	x1;
	double	y1;
	double	x2;
	double	y2;

	x1 = (game->state->p1->pos_x + game->state->p1->dir_x \
	* game->state->p1->move_speed);
	y2 = (game->state->p1->pos_y + game->state->p1->dir_y \
	* game->state->p1->move_speed);
	x2 = (game->state->p1->pos_x);
	y1 = (game->state->p1->pos_y);
	if (game->map[(int)y1][(int)(x1)] != '1')
		game->state->p1->pos_x = x1;
	if (game->map[(int)y2][(int)x2] != '1')
		game->state->p1->pos_y = y2;
}

void	s_key(t_game *game)
{
	double	x1;
	double	y1;
	double	x2;
	double	y2;

	x1 = (game->state->p1->pos_x - game->state->p1->dir_x \
	* game->state->p1->move_speed);
	y2 = (game->state->p1->pos_y - game->state->p1->dir_y \
	* game->state->p1->move_speed);
	x2 = (game->state->p1->pos_x);
	y1 = (game->state->p1->pos_y);
	if (game->map[(int)y1][(int)(x1)] != '1')
		game->state->p1->pos_x = x1;
	if (game->map[(int)y2][(int)x2] != '1')
		game->state->p1->pos_y = y2;
}

void	a_key(t_game *game)
{
	double	x1;
	double	y1;
	double	x2;
	double	y2;

	x1 = (game->state->p1->pos_x + game->state->p1->dir_y \
	* game->state->p1->move_speed);
	y2 = (game->state->p1->pos_y - game->state->p1->dir_x \
	* game->state->p1->move_speed);
	x2 = (game->state->p1->pos_x);
	y1 = (game->state->p1->pos_y);
	if (game->map[(int)y1][(int)(x1)] != '1')
		game->state->p1->pos_x = x1;
	if (game->map[(int)y2][(int)x2] != '1')
		game->state->p1->pos_y = y2;
}

void	d_key(t_game *game)
{
	double	x1;
	double	y1;
	double	x2;
	double	y2;

	x1 = (game->state->p1->pos_x - game->state->p1->dir_y \
	* game->state->p1->move_speed);
	y2 = (game->state->p1->pos_y + game->state->p1->dir_x \
	* game->state->p1->move_speed);
	x2 = (game->state->p1->pos_x);
	y1 = (game->state->p1->pos_y);
	if (game->map[(int)y1][(int)(x1)] != '1')
		game->state->p1->pos_x = x1;
	if (game->map[(int)y2][(int)x2] != '1')
		game->state->p1->pos_y = y2;
}

void	left_key(t_game *game)
{
	game->state->p1->old_dir_x = game->state->p1->dir_x;
	game->state->p1->dir_x = game->state->p1->dir_x * \
	cos(-game->state->p1->rot_speed) - game->state->p1->dir_y * \
	sin(-game->state->p1->rot_speed);
	game->state->p1->dir_y = game->state->p1->old_dir_x * \
	sin(-game->state->p1->rot_speed) + game->state->p1->dir_y * \
	cos(-game->state->p1->rot_speed);
	game->state->p1->old_plane_x = game->state->p1->plane_x;
	game->state->p1->plane_x = game->state->p1->plane_x * \
	cos(-game->state->p1->rot_speed) - game->state->p1->plane_y * \
	sin(-game->state->p1->rot_speed);
	game->state->p1->plane_y = game->state->p1->old_plane_x * \
	sin(-game->state->p1->rot_speed) + game->state->p1->plane_y * \
	cos(-game->state->p1->rot_speed);
}

void	right_key(t_game *game)
{
	game->state->p1->old_dir_x = game->state->p1->dir_x;
	game->state->p1->dir_x = game->state->p1->dir_x * \
	cos(game->state->p1->rot_speed) - game->state->p1->dir_y * \
	sin(game->state->p1->rot_speed);
	game->state->p1->dir_y = game->state->p1->old_dir_x * \
	sin(game->state->p1->rot_speed) + game->state->p1->dir_y * \
	cos(game->state->p1->rot_speed);
	game->state->p1->old_plane_x = game->state->p1->plane_x;
	game->state->p1->plane_x = game->state->p1->plane_x * \
	cos(game->state->p1->rot_speed) - game->state->p1->plane_y * \
	sin(game->state->p1->rot_speed);
	game->state->p1->plane_y = game->state->p1->old_plane_x * \
	sin(game->state->p1->rot_speed) + game->state->p1->plane_y * \
	cos(game->state->p1->rot_speed);
}

int	key_press_other(int key, t_game *game)
{
	if (key == KEY_RIGHT && game->state->step_of_game >= 2)
		right_key(game);
	else if (key == KEY_LEFT && game->state->step_of_game >= 2)
		left_key(game);
	else if (key == KEY_RETURN && game->state->step_of_game == 1)
		game_start(game);
	else if (key == KEY_ESC)
		free_all_exit(game);
	return (0);
}

int	key_press(int key, t_game *game)
{
	if (key == KEY_W && game->state->step_of_game >= 2)
		w_key(game);
	else if (key == KEY_S && game->state->step_of_game >= 2)
		s_key(game);
	else if (key == KEY_A && game->state->step_of_game >= 2)
		a_key(game);
	else if (key == KEY_D && game->state->step_of_game >= 2)
		d_key(game);
	return (key_press_other(key, game));
}

void	introduction_of_game(t_cub3d *cub3d)
{
	img_intro(cub3d);
	mlx_key_hook(cub3d->window->win_ptr, &key_press, &cub3d);
	mlx_hook(cub3d->window->win_ptr, 17, 1L << 0, &free_all_exit, &cub3d);
	mlx_put_image_to_window(cub3d->mlx_ptr, cub3d->window->win_ptr, \
	cub3d->intro.img, 0, 0);
	mlx_loop(cub3d->mlx_ptr);
}