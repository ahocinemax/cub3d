/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 14:50:22 by ahocine           #+#    #+#             */
/*   Updated: 2022/10/05 03:37:46 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_init_texture_color(t_cub3d *cub3d)
{
	cub3d->no.path = NULL;
	ft_init_img(&(cub3d->no.img));
	ft_init_img(&(cub3d->so.img));
	ft_init_img(&(cub3d->we.img));
	ft_init_img(&(cub3d->ea.img));
	cub3d->so.path = NULL;
	cub3d->ea.path = NULL;
	cub3d->we.path = NULL;
	cub3d->celling.green = 0;
	cub3d->celling.blue = 0;
	cub3d->celling.red = 0;
	cub3d->celling.nb = 0;
	cub3d->celling.trgb = 0;
	cub3d->floor.green = 0;
	cub3d->floor.blue = 0;
	cub3d->floor.red = 0;
	cub3d->floor.nb = 0;
	cub3d->floor.trgb = 0;
}

void	ft_init_map(t_map *map)
{
	map->map = NULL;
	map->large = 0;
	map->longu = 0;
}

t_error_code	ft_init_window(t_cub3d *cub3d)
{
	cub3d->step_of_game = 1;
	cub3d->window.height = 800;
	cub3d->window.width = 1200;
	cub3d->mlx_ptr = mlx_init();
	if (!cub3d->mlx_ptr)
		return (ft_print_error(cub3d, ERROR_MLX));
	cub3d->window.win_ptr = mlx_new_window(cub3d->mlx_ptr, \
	cub3d->window.width, cub3d->window.height, "Welcome to my home");
	if (cub3d->window.win_ptr == NULL)
		return (ft_print_error(cub3d, ERROR_MLX));
	cub3d->intro.img = mlx_xpm_file_to_image(cub3d->mlx_ptr, \
	"./image/intro.xpm", &(cub3d->intro.width), &(cub3d->intro.height));
	if (!cub3d->intro.img)
		return (ft_print_error(cub3d, ERROR_IMAGE));
	return (SUCCESS);
}

void	ft_init_img(t_img *img)
{
	img->mlx_img = NULL;
	img->line_len = 0;
	img->addr = NULL;
	img->endian = 0;
	img->height = 0;
	img->width = 0;
	img->bpp = 0;
}

t_error_code	ft_init_struct(t_cub3d *cub3d)
{
	ft_init_texture_color(cub3d);
	ft_init_map(&(cub3d->map));
	ft_init_img(&(cub3d->screen));
	ft_init_img(&(cub3d->minimap.img));
	init_player(&(cub3d->p1));
	init_picture(&(cub3d->intro));
	init_struct_pos(&(cub3d->pos));
	cub3d->mlx_ptr = NULL;
	cub3d->level_name = NULL;
	cub3d->step_of_game = 0;
	cub3d->nb_player = 0;
	cub3d->exit_code = SUCCESS;
	cub3d->window.win_ptr = NULL;
	cub3d->intro.img = NULL;
	cub3d->fd = -1;
	return (SUCCESS);
}
