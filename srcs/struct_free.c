/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 03:37:56 by ahocine           #+#    #+#             */
/*   Updated: 2022/10/05 03:37:58 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	ft_free_mlx(t_cub3d *cub3d)
{
	if (cub3d->intro.img)
	{
		mlx_destroy_image(cub3d->mlx_ptr, cub3d->intro.img);
		free(cub3d->intro.img);
	}
	if (cub3d->window.win_ptr)
	{
		mlx_destroy_window(cub3d->mlx_ptr, cub3d->window.win_ptr);
		free(cub3d->window.win_ptr);
	}
	if (cub3d->mlx_ptr)
	{
		mlx_destroy_display(cub3d->mlx_ptr);
		free(cub3d->mlx_ptr);
	}
}

static void	ft_free_texture(t_cub3d *cub3d)
{
	free(cub3d->no.path);
	free(cub3d->so.path);
	free(cub3d->ea.path);
	free(cub3d->we.path);
}

void	ft_free_struct(t_cub3d *cub3d)
{
	if (cub3d->level_name)
		free(cub3d->level_name);
	if (cub3d->fd > 2)
		close(cub3d->fd);
	ft_free_texture(cub3d);
	ft_free_array((void **)cub3d->map.map, free);
	ft_free_mlx(cub3d);
}
