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

#include "../../includes/cub3d_bonus.h"

void	ft_init_minimap(t_cub3d *cub3d, t_minimap *minimap, t_img img, \
char ***map)
{
	minimap->pixel_y = 0;
	minimap->map_y = 0;
	minimap->pxl_x = 0;
	minimap->map_x = 0;
	minimap->size_case_x = img.width / cub3d->map.large;
	minimap->size_case_y = img.height / cub3d->map.longu;
	minimap->color = get_trgb(25, 155, 60);
	*map = cub3d->map.map;
}

void	ft_put_player(t_cub3d *cub3d, t_minimap *minimap)
{
	int	pixel_x;
	int	pixel_y;
	int	i;
	int	j;

	pixel_x = (int)cub3d->p1.pos_x * minimap->size_case_x;
	pixel_y = (int)cub3d->p1.pos_y * minimap->size_case_y;
	i = minimap->size_case_x / 4;
	while (i < (minimap->size_case_x * 3) / 4)
	{
		j = minimap->size_case_y / 4;
		while (j < (minimap->size_case_y * 3) / 4)
		{
			draw_pixel(&(minimap->img), pixel_x + i, \
			pixel_y + j, get_trgb(215, 155, 200));
			j++;
		}
		i++;
	}
}

void	ft_minimap(t_cub3d *cub3d, t_minimap *mini)
{
	char	**map;

	ft_init_minimap(cub3d, mini, mini->img, &map);
	while (mini->pixel_y < mini->img.height && mini->map_y < cub3d->map.longu)
	{
		mini->pxl_x = 0;
		mini->map_x = 0;
		while (mini->pxl_x < mini->img.width && mini->map_x < cub3d->map.large)
		{
			if (map[mini->map_y][mini->map_x] != '1')
			{
				draw_pixel(&(mini->img), mini->pxl_x, \
				mini->pixel_y, mini->color);
			}
			mini->pxl_x++;
			if (mini->pxl_x % mini->size_case_x == 0)
				mini->map_x++;
		}
		mini->pixel_y++;
		if (mini->pixel_y % mini->size_case_y == 0)
			mini->map_y++;
	}
	ft_put_player(cub3d, mini);
	mlx_put_image_to_window(cub3d->mlx_ptr, cub3d->window.win_ptr, \
	mini->img.mlx_img, 0, 0);
}
