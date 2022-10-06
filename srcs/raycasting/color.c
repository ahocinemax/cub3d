/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsuji <mtsuji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:47:45 by mtsuji            #+#    #+#             */
/*   Updated: 2022/10/05 18:19:37 by mtsuji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_color_val(int nbr)
{
	if (nbr <= 0 && nbr >= 255)
		return (1);
	else
		return (0);
}

int	create_trgb(int r, int g, int b)
{
	return ((0 << 24 | r << 16 | g << 8 | b));
}
