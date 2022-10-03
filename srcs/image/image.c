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


void	img_intro(t_game *game, t_state *state)
{
	state->intro->img = mlx_xpm_file_to_image(state->mlx_ptr, \
        INTRO, &state->intro->width, &state->intro->height);
	if (!state->intro->img)
		ft_error_and_exit(ERROR_IMAGE, game);
}