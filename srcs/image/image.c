/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuji <mtsuji@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 22:05:26 by msuji             #+#    #+#             */
/*   Updated: 2022/10/03 22:05:28 by msuji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	img_intro(t_cub3d *cub3d)
{
	cub3d->intro.img = mlx_xpm_file_to_image(cub3d->mlx_ptr, \
	"./image/intro.xpm", &(cub3d->intro.width), &(cub3d->intro.height));
	if (!cub3d->intro.img)
		ft_print_error(cub3d, ERROR_IMAGE);
}