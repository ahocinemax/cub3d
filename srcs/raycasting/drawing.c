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

#include "../../includes/cub3d.h"

t_img	put_img_wall_to_mlx(t_cub3d *cub3d, char *path, t_img img)
{
	img.mlx_img = mlx_xpm_file_to_image(cub3d->mlx_ptr, path, \
	&img.width, &img.height);
	if (!img.mlx_img)
		ft_print_error(cub3d, ERROR_IMAGE);
	img.addr = mlx_get_data_addr(img.mlx_img, &img.bpp,
			&img.line_len, &img.endian);
	if (img.mlx_img == NULL || img.addr == NULL)
		ft_print_error(cub3d, ERROR_MLX);
	return (img);
}

t_error_code	wall_tex_init(t_cub3d *cub3d)
{	
	if (cub3d->no.path)
	{
		cub3d->no.img.width = 150;
		cub3d->no.img.height = 150;
		cub3d->no.img = put_img_wall_to_mlx(cub3d, cub3d->no.path, cub3d->no.img);
	}
	if (cub3d->so.path)
	{
		cub3d->so.img.width = 150;
		cub3d->so.img.height = 150;
		cub3d->so.img = put_img_wall_to_mlx(cub3d, cub3d->so.path, cub3d->so.img);
	}
	if (cub3d->ea.path)
	{
		cub3d->ea.img.width = 150;
		cub3d->ea.img.height = 150;
		cub3d->ea.img = put_img_wall_to_mlx(cub3d, cub3d->ea.path, cub3d->ea.img);
	}
	if (cub3d->we.path)
	{
		cub3d->we.img.width = 150;
		cub3d->we.img.height = 150;
		cub3d->we.img = put_img_wall_to_mlx(cub3d, cub3d->we.path, cub3d->ea.img);
	}
	else
		return (ft_print_error(cub3d, ERROR_IMAGE));
	return (SUCCESS);
}


void	wall_x(t_player *p1)
{
	if (p1->side == EAST || p1->side == WEST)
		p1->wall_x = p1->pos_y + p1->perp_wall_dist * p1->raydir_y;
	else
		p1->wall_x = p1->pos_x + p1->perp_wall_dist * p1->raydir_x;
	p1->wall_x = floor(p1->wall_x);
}

void	draw_pixel(t_img *img, int x, int y, int color)
{
	void	*pixel;
	pixel = img->addr + (x * (img->bpp / 8) + y * img->line_len);
	*(unsigned int *) pixel = color;
}

char *set_direction_wall(t_cub3d *cub3d, t_player *p1)
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

int	get_tex_rgb(char *addr, t_cub3d *cub3d, int add, int y)
{
	int	rgb;

	rgb = addr[(int)(cub3d->p1.wall_x * TEX_W) * (cub3d->no.img.bpp >> 3) + add + (int)((y - cub3d->p1.tex_start * 1.0)  / cub3d->p1.line_height * TEX_H) *cub3d->no.img.line_len];
	return (rgb);
}

int	get_trgb(int r, int g, int b)
{
	int	color;

	color = ((int)(r & 0xff) << 16) + ((int)(g & 0xff) << 8)
		+ (int)(b & 0xff);
	return (color);
}

void	visual_wall(t_cub3d *cub3d, int x, int *y, int draw_end)
{
	int color;
	int rgb[3];
	char *addr;
	(void)x;

	addr = set_direction_wall(cub3d, &(cub3d->p1));
	while (*y < draw_end)
	{
		rgb[0] = get_tex_rgb(addr, cub3d, 2, *y);
		rgb[1] = get_tex_rgb(addr, cub3d, 1, *y);
		rgb[2] = get_tex_rgb(addr, cub3d, 0, *y);
		color = get_trgb(rgb[0], rgb[1], rgb[2]);
		get_trgb(rgb[0], rgb[1], rgb[2]);
		draw_pixel((&cub3d->screen), x, *y, color);
		(*y)++;
	}
}

t_img	*prepare_wall(t_cub3d *cub3d, int x, int draw_start, int draw_end)
{
	int	y;
	t_img *img;

	(void)draw_start;
	(void)draw_end;
	img = NULL;
	y = 0;
	wall_x(&(cub3d->p1));
	if (cub3d->p1.check_pos == 'N' || cub3d->p1.check_pos == 'E')
		x = cub3d->window.width - x - 1;
	while (y < draw_start)
	{
		draw_pixel((&cub3d->screen), x, y, cub3d->celling.trgb);
		y++;
	}
	cub3d->p1.tex_start = draw_start;
	visual_wall(cub3d,x, &y, draw_end);
	while (y < cub3d->window.height)
	{
		draw_pixel((&cub3d->screen), x, y, cub3d->celling.trgb);
		y++;
	}
	return (img);
}
//preparetion_image floor + celling;
