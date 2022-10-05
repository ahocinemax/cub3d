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

static void	ft_init_img(t_img *img)
{
	img->mlx_img = NULL;
	img->addr = NULL;
	img->line_len = 0;
	img->endian = 0;
	img->width = 0;
	img->height = 0;
}

static void	ft_init_texture(t_texture *texture, t_direction dir)
{
	texture->path = NULL;
	texture->direction = dir;
	ft_init_img(&(texture->img));
}

void	init_picture(t_pic *intro)
{
	intro->img = NULL;
	intro->width = 0;
	intro->height = 0;
}

void	init_struct_pos(t_pos *pos)
{
	pos->check_pos = 0;
	pos->pos_x = 0;
	pos->pos_y = 0;
}

static void	ft_init_texture_color(t_cub3d *cub3d)
{
	cub3d->celling.green = 0;
	cub3d->celling.blue = 0;
	cub3d->celling.red = 0;
	cub3d->floor.green = 0;
	cub3d->floor.blue = 0;
	cub3d->floor.red = 0;
	ft_init_texture(&(cub3d->no), NORTH);
	ft_init_texture(&(cub3d->so), SOUTH);
	ft_init_texture(&(cub3d->ea), EAST);
	ft_init_texture(&(cub3d->we), WEST);
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
}

void	init_player(t_player *p1)
{
	p1->pos_x = 0;
	p1->pos_y = 0;
	p1->dir_x = 0;
	p1->dir_y = 0;
	p1->plane_x = 0;
	p1->plane_y = 0;
	p1->move_speed = 0.3;
	p1->rot_speed = 0.5;
	p1->camera_x = 0;
	p1->map_x = 0;
	p1->map_y = 0;
	p1->delta_dist_x = 0;
	p1->delta_dist_y = 0;
	p1->hit = 0;
	p1->raydir_x = 0;
	p1->raydir_y = 0;
}

t_error_code	ft_init_window(t_cub3d *cub3d)
{
	cub3d->window.height = 800;
	cub3d->window.width = 1200;
	cub3d->window.win_ptr = mlx_new_window(cub3d->mlx_ptr, \
	cub3d->window.width, cub3d->window.height, "Welcome to my home");
	if (cub3d->window.win_ptr == NULL)
		return (ft_print_error(cub3d, ERROR_MLX));
	return (SUCCESS);
}

t_error_code	ft_init_struct(t_cub3d *cub3d)
{
	ft_init_texture_color(cub3d);
	ft_init_map(cub3d);
	ft_init_img(&(cub3d->screen));
	cub3d->mlx_ptr = NULL;
	init_player(&(cub3d->p1));
	init_picture(&(cub3d->intro));
	init_struct_pos(&(cub3d->pos));
	cub3d->exit_code = SUCCESS;
	cub3d->step_of_game = 1;
	cub3d->level_name = NULL;
	cub3d->fd = -1;
	return (SUCCESS);
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
