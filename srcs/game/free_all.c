/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsuji <mtsuji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 13:08:39 by mtsuji            #+#    #+#             */
/*   Updated: 2022/10/03 13:08:41 by mtsuji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	free_texture(t_cub3d *cub3d)
{
	if (cub3d->step_of_game >= 3)
	{
		if (cub3d->mlx_img)
			mlx_destroy_image(cub3d->mlx_ptr, cub3d->no.mlx_img);
		if (cub3d->so.mlx_img)
			mlx_destroy_image(cub3d->mlx_ptr, cub3d->so.mlx_img);
		if (cub3d->we.mlx_img)
			mlx_destroy_image(cub3d->mlx_ptr, cub3d->we.mlx_img);
		if (cub3d->ea.mlx_img)
			mlx_destroy_image(cub3d->mlx_ptr, cub3d->ea.mlx_img);
	}
	if (cub3d->no)
		free(cub3d->no);
	if (cub3d->so)
		free(cub3d->so);
	if (cub3d->we)
		free(cub3d->we);
	if (cub3d->ea)
		free(cub3d->ea);
	if (texture)
		free(texture);
}

void	free_img(t_state *state, t_img *img)
{
	if (img->mlx_img)
		mlx_destroy_image(state->mlx_ptr, img->mlx_img);
	if (img)
		free(img);
}

void	free_pics(t_state *state, t_pic *pic)
{
	if (pic->img)
		mlx_destroy_image(state->mlx_ptr, pic->img);
	if (pic)
		free(pic);
}

void	free_game_and_mlx(t_state *state)
{
	if (state->step_of_game >= 3)
		free_img(state, state->screen);
	else
		free(state->screen);
	free_pics(state, state->intro);
	if (state->win_ptr)
		mlx_destroy_window(state->mlx_ptr, state->win_ptr);
	if (state->mlx_ptr)
	{
		mlx_destroy_display(state->mlx_ptr);
		free(state->mlx_ptr);
	}
	if (state->pos)
		free(state->pos);
	if (state->p1)
		free(state->p1);
}

int	free_all(t_cub3d *cub3d)
{
	free_texture(cub3d);
	free_img(game->state, game->img);
	free_game_and_mlx(game->state);
	if (game->state)
		free(game->state);
	if (game)
		free(game);
	return (0);
}

int	free_all_exit(t_game *game)
{
	free_texture(game->state, game->state->texture);
	if (game->state->step_of_game >= 3)
		free_img(game->state, game->img);
	else
		free(game->img);
	free_game_and_mlx(game->state);
	if (game->state)
		free(game->state);
	if (game)
		free(game);
	exit(EXIT_SUCCESS);
}