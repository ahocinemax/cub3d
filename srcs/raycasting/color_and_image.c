/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_and_image.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsuji <mtsuji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 12:38:26 by mtsuji            #+#    #+#             */
/*   Updated: 2022/10/11 12:38:33 by mtsuji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	get_tex_rgb(char *addr, t_cub3d *cub3d, int add, int y)
{
	return (addr[(int)(cub3d->p1.wall_x * TEX_W) * (cub3d->no.img.bpp >> 3) + \
	add + (int)((y - cub3d->p1.tex_start * 1.0) / cub3d->p1.line_height * \
	TEX_H) *cub3d->no.img.line_len]);
}

int	get_trgb(int r, int g, int b)
{
	return (((int)(r & 0xff) << 16) + ((int)(g & 0xff) << 8) + \
	(int)(b & 0xff));
}

void	draw_pixel(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*((unsigned int *)pixel) = color;
}

void	put_img_wall_to_mlx(t_cub3d *cub3d, char *path, t_img *img)
{
	img->mlx_img = mlx_xpm_file_to_image(cub3d->mlx_ptr, path, \
	&(img->width), &(img->height));
	if (!img->mlx_img)
		ft_print_error_exit(cub3d, ERROR_IMAGE);
	img->addr = mlx_get_data_addr(img->mlx_img, &(img->bpp), \
	&(img->line_len), &(img->endian));
	if (img->mlx_img == NULL || img->addr == NULL)
		ft_print_error_exit(cub3d, ERROR_MLX);
}
