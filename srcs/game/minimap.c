/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:58:08 by ahocine           #+#    #+#             */
/*   Updated: 2022/10/11 13:58:24 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_init_minimap(t_cub3d *cub3d, t_minimap *minimap, t_img img, \
char ***map)
{
	minimap->pixel_y = 0;
	minimap->map_y = 0;
	minimap->pixel_x = 0;
	minimap->map_x = 0;
	minimap->size_case_x = img.height / cub3d->map.longu;
	minimap->size_case_y = img.width / (cub3d->map.large - 1);
	minimap->color = get_trgb(25, 155, 60);
	*map = cub3d->map.map;
}

void	ft_put_player(t_cub3d *cub3d, t_minimap *minimap)
{
	int	pixel_x;
	int	pixel_y;

	pixel_x = cub3d->p1.pos_x * minimap->size_case_x;
	pixel_y = cub3d->p1.pos_y * minimap->size_case_y;
	for (int i = 0; i < minimap->size_case_x; i++)
	{
		for (int j = 0; j < minimap->size_case_y; j++)
		{
			draw_pixel(&(minimap->img), pixel_y++, \
			pixel_x + i, 0);
		}
	}

}

void	ft_minimap(t_cub3d *cub3d, t_minimap *minimap)
{
	char	**map;

	ft_init_minimap(cub3d, minimap, minimap->img, &map);
	while (minimap->pixel_x < minimap->img.height && minimap->map_x < cub3d->map.longu)
	{
		minimap->pixel_y = 0;
		minimap->map_y = 0;
		while (minimap->pixel_y < minimap->img.width && minimap->map_y < cub3d->map.large)
		{
			if (map[minimap->map_x][minimap->map_y] != '1')
			{
				draw_pixel(&(minimap->img), minimap->pixel_y, \
				minimap->pixel_x, minimap->color);
			}
			minimap->pixel_y++;
			if (minimap->pixel_y % minimap->size_case_y == 0)
				minimap->map_y++;
		}
		minimap->pixel_x++;
		if (minimap->pixel_x % minimap->size_case_x == 0)
			minimap->map_x++;
	}
	ft_put_player(cub3d, minimap);
	mlx_put_image_to_window(cub3d->mlx_ptr, cub3d->window.win_ptr, \
	minimap->img.mlx_img, 0, 0);
}
