/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 14:50:22 by ahocine           #+#    #+#             */
/*   Updated: 2022/10/01 14:50:35 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	ft_init_texture(t_cub3d *cub3d)
{
	cub3d->no.path = NULL;
	cub3d->so.path = NULL;
	cub3d->ea.path = NULL;
	cub3d->we.path = NULL;
	cub3d->floor.green = 0;
	cub3d->celling.green = 0;
	cub3d->floor.blue = 0;
	cub3d->celling.blue = 0;
	cub3d->floor.red = 0;
	cub3d->celling.red = 0;
}

static void	ft_free_texture(t_cub3d *cub3d)
{
	free(cub3d->no.path);
	free(cub3d->so.path);
	free(cub3d->ea.path);
	free(cub3d->we.path);
}

static void	ft_init_map(t_cub3d *cub3d)
{
	cub3d->map.map = NULL;
	cub3d->map.large = 0;
	cub3d->map.longu = 0;
	cub3d->map.x = 0;
	cub3d->map.y = 0;
}

void	ft_init_struct(t_cub3d *cub3d)
{
	ft_init_texture(cub3d);
	ft_init_map(cub3d);
	cub3d->exit_code = SUCCESS;
	cub3d->level_name = NULL;
	cub3d->fd = -1;
}

void	ft_free_struct(t_cub3d *cub3d)
{
	if (cub3d->level_name)
		free(cub3d->level_name);
	if (cub3d->fd > 2)
		close(cub3d->fd);
	ft_free_texture(cub3d);
	ft_free_array((void **)cub3d->map.map, free);
}
