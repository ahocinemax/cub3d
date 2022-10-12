/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsuji <mtsuji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:55:09 by mtsuji            #+#    #+#             */
/*   Updated: 2022/10/05 18:19:54 by mtsuji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	wall_tex_init(t_cub3d *cub3d)
{
	if (cub3d->no.path)
		put_img_wall_to_mlx(cub3d, cub3d->no.path, &(cub3d->no.img));
	if (cub3d->so.path)
		put_img_wall_to_mlx(cub3d, cub3d->so.path, &(cub3d->so.img));
	if (cub3d->ea.path)
		put_img_wall_to_mlx(cub3d, cub3d->ea.path, &(cub3d->ea.img));
	if (cub3d->we.path)
		put_img_wall_to_mlx(cub3d, cub3d->we.path, &(cub3d->we.img));
	else
		ft_print_error_exit(cub3d, ERROR_IMAGE);
}

void	wall_x(t_player *p1)
{
	if (p1->side == EAST || p1->side == WEST)
		p1->wall_x = p1->pos_y + p1->perp_wall_dist * p1->raydir_y;
	else
		p1->wall_x = p1->pos_x + p1->perp_wall_dist * p1->raydir_x;
	p1->wall_x -= floor(p1->wall_x);
}

char	*set_direction_wall(t_cub3d *cub3d, t_player *p1)
{
	if (p1->side == NORTH)
		return (cub3d->no.img.addr);
	if (p1->side == SOUTH)
		return (cub3d->so.img.addr);
	if (p1->side == WEST)
		return (cub3d->we.img.addr);
	else
		return (cub3d->ea.img.addr);
}

void	visual_wall(t_cub3d *cub3d, int x, int *y, int draw_end)
{
	int		color;
	int		rgb[3];
	char	*addr;

	addr = set_direction_wall(cub3d, &(cub3d->p1));
	while (*y < draw_end)
	{
		rgb[0] = get_tex_rgb(addr, cub3d, 2, *y);
		rgb[1] = get_tex_rgb(addr, cub3d, 1, *y);
		rgb[2] = get_tex_rgb(addr, cub3d, 0, *y);
		color = get_trgb(rgb[0], rgb[1], rgb[2]);
		draw_pixel((&cub3d->screen), x, *y, color);
		(*y)++;
	}
}

void	prepare_wall(t_cub3d *cub3d, int x, int draw_start, int draw_end)
{
	int	y;

	y = 0;
	wall_x((&cub3d->p1));
	if (cub3d->pos.pos == 'N' || \
	cub3d->pos.pos == 'E')
		x = cub3d->window.width - x - 1;
	while (y < draw_start)
	{
		draw_pixel(&(cub3d->screen), x, y, \
		cub3d->celling.trgb);
		y++;
	}
	cub3d->p1.tex_start = draw_start;
	visual_wall(cub3d, x, &y, draw_end);
	while (y < cub3d->window.height)
	{
		draw_pixel(&(cub3d->screen), x, y, \
		cub3d->floor.trgb);
		y++;
	}
}
