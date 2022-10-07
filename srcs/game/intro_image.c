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

int	key_release_other(int key, t_cub3d *cub3d)
{
	if (key == KEY_RIGHT && cub3d->step_of_game >= 2)
		right_key(cub3d);
	else if (key == KEY_LEFT && cub3d->step_of_game >= 2)
		left_key(cub3d);
	else if (key == KEY_RETURN && cub3d->step_of_game == 1)
		;
	else if (key == KEY_ESC)
		ft_free_struct(cub3d);
	return (0);
}

int	key_release(int key, t_cub3d *cub3d)
{
	if (key == KEY_W && cub3d->step_of_game >= 2)
		w_key(cub3d);
	else if (key == KEY_S && cub3d->step_of_game >= 2)
		s_key(cub3d);
	else if (key == KEY_A && cub3d->step_of_game >= 2)
		a_key(cub3d);
	else if (key == KEY_D && cub3d->step_of_game >= 2)
		d_key(cub3d);
	return (key_release_other(key, cub3d));
}

int	key_press_other(int key, t_cub3d *cub3d)
{
	if (key == KEY_RIGHT && cub3d->step_of_game >= 2)
		right_key(cub3d);
	else if (key == KEY_LEFT && cub3d->step_of_game >= 2)
		left_key(cub3d);
	else if ((key == KEY_RETURN || key == 65421) && cub3d->step_of_game == 1)
		game_start(cub3d);
	else if (key == KEY_ESC)
		ft_free_struct(cub3d);
	return (0);
}

int	key_press(int key, t_cub3d *cub3d)
{
	static int counter = 1;
	if (key == KEY_W && cub3d->step_of_game >= 2)
		w_key(cub3d);
	else if (key == KEY_S && cub3d->step_of_game >= 2)
		s_key(cub3d);
	else if (key == KEY_A && cub3d->step_of_game >= 2)
		a_key(cub3d);
	else if (key == KEY_D && cub3d->step_of_game >= 2)
		d_key(cub3d);
	return (counter++, key_press_other(key, cub3d));
}

void	introduction_of_game(t_cub3d *cub3d)
{
	mlx_hook(cub3d->window.win_ptr, 2, 1L << 0, &key_press, cub3d);
	// mlx_hook(cub3d->window.win_ptr, 3, 1L << 0, &key_release, cub3d);
	mlx_hook(cub3d->window.win_ptr, 17, 1L << 2, &ft_free_struct, cub3d);
	mlx_put_image_to_window(cub3d->mlx_ptr, cub3d->window.win_ptr, \
	cub3d->intro.img, 0, 0);
	mlx_loop(cub3d->mlx_ptr);
}
