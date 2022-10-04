/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsuji <mtsuji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 02:36:18 by mtsuji            #+#    #+#             */
/*   Updated: 2022/10/03 02:36:21 by mtsuji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_error_and_exit(t_error_code error, t_cub3d *cub3d)
{
	ft_print_error(cub3d, error);
	free_all(cub3d);
	exit(EXIT_FAILURE);
	return (-1);
}

int	init_img(t_img *img)
{
	img->mlx_img = NULL;
	img->bpp = 0;
	img->line_len = 0;
	img->endian = 0;
	img->width = 0;
	img->height = 0;
	return (0);
}


void	init_player(t_player *p1)
{
	p1->pos_x = 0;
	p1->pos_y = 0;
	p1->dir_x = 0;
	p1->dir_y = 0;
	p1->plane_x = 0;
	p1->plane_y = 0;
	p1->time = 0;
	p1->old_time = 0;
}

void	init_pic(t_pic *pic)
{
	pic->img = NULL;
	pic->width = 0;
	pic->height = 0;
}

void	init_picture(t_cub3d *cub3d)
{
	init_pic(&(cub3d->intro));
}

void	init_texture(t_game *game, t_texture *texture)
{
	texture->wall_no = malloc(sizeof(t_img));
	if (!texture->wall_no)
		ft_error_and_exit(ERROR_MALLOC, game);
	init_img(texture->wall_no);
	texture->wall_so = malloc(sizeof(t_img));
	if (!texture->wall_so)
	    ft_error_and_exit(ERROR_MALLOC, game);
	init_img(texture->wall_so);
	texture->wall_we = malloc(sizeof(t_img));
	if (!texture->wall_we)
		ft_error_and_exit(ERROR_MALLOC, game);
	init_img(texture->wall_we);
	texture->wall_ea = malloc(sizeof(t_img));
	if (!texture->wall_ea)
		ft_error_and_exit(ERROR_MALLOC, game);
	init_img(texture->wall_ea);
	texture->floor = malloc(sizeof(t_color));
	if (!texture->floor)
		ft_error_and_exit(ERROR_MALLOC, game);
	texture->celling = malloc(sizeof(t_color));
	if (!texture->celling)
		ft_error_and_exit(ERROR_MALLOC, game);
}
void	init_struct_state(t_game *game, t_state *state)
{
	state->mlx_ptr = NULL;
	state->win_ptr = NULL;
	state->step_of_game = 0;
	state->screen = NULL;
	state->screen = malloc(sizeof(t_img));
	if (!state->screen)
		ft_error_and_exit(ERROR_MALLOC, game);
	init_img(state->screen);
	if (!state->screen)
		ft_error_and_exit(ERROR_MALLOC, game);
	init_picture(game, state);
	init_texture(game, state->texture);
	init_struct_pos(state->pos);
}

t_game	*init_struct_game(t_game *game)
{
	init_struct_malloc(game);
	init_img(game->img);
	init_struct_state(game, game->state);
	init_player(game->state->p1);
	return (game);
}