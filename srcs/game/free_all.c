/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsuji <mtsuji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 13:08:39 by mtsuji            #+#    #+#             */
/*   Updated: 2022/10/03 13:08:41 by mtsuji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	free_texture(t_cub3d *cub3d)
{
	if (cub3d->step_of_game >= 3)
	{
		if (cub3d->no.img.mlx_img)
			mlx_destroy_image(cub3d->mlx_ptr, cub3d->no.img.mlx_img);
		if (cub3d->so.img.mlx_img)
			mlx_destroy_image(cub3d->mlx_ptr, cub3d->so.img.mlx_img);
		if (cub3d->we.img.mlx_img)
			mlx_destroy_image(cub3d->mlx_ptr, cub3d->we.img.mlx_img);
		if (cub3d->ea.img.mlx_img)
			mlx_destroy_image(cub3d->mlx_ptr, cub3d->ea.img.mlx_img);
	}
}

void	free_img(t_cub3d *cub3d, t_img *img)
{
	if (img->mlx_img)
		mlx_destroy_image(cub3d->mlx_ptr, img->mlx_img);
	if (img)
		free(img);
}

void	free_pics(t_cub3d *cub3d, t_pic *pic)
{
	if (pic->img)
		mlx_destroy_image(cub3d->mlx_ptr, pic->img);
	if (pic)
		free(pic);
}

void	free_game_and_mlx(t_cub3d *cub3d)
{
	if (cub3d->step_of_game >= 3)
		free_img(cub3d, &(cub3d->screen));
	free_pics(cub3d, &(cub3d->intro));
	if (cub3d->window.win_ptr)
		mlx_destroy_window(cub3d->mlx_ptr, cub3d->window.win_ptr);
	if (cub3d->mlx_ptr)
	{
		mlx_destroy_display(cub3d->mlx_ptr);
		free(cub3d->mlx_ptr);
	}
}

int	free_all(t_cub3d *cub3d)
{
	free_texture(cub3d);
	free_img(cub3d, &(cub3d->screen));
	free_game_and_mlx(cub3d);
	return (0);
}

int	free_all_exit(t_cub3d *cub3d)
{
	free_texture(cub3d);
	if (cub3d->step_of_game >= 3)
		free_img(cub3d, &(cub3d->screen));
	free_cub3d_and_mlx(cub3d);
	exit(EXIT_SUCCESS);
}