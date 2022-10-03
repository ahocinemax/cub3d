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

void	free_texture(t_state *state, t_texture *texture)
{
	if (texture->floor)
		free(texture->floor);
	if (texture->celling)
		free(texture->celling);
	if (state->step_of_game >= 3)
	{
		if (texture->wall_no->mlx_img)
			mlx_destroy_image(state->mlx_ptr, texture->wall_no->mlx_img);
		if (texture->wall_so->mlx_img)
			mlx_destroy_image(state->mlx_ptr, texture->wall_so->mlx_img);
		if (texture->wall_we->mlx_img)
			mlx_destroy_image(state->mlx_ptr, texture->wall_we->mlx_img);
		if (texture->wall_ea->mlx_img)
			mlx_destroy_image(state->mlx_ptr, texture->wall_ea->mlx_img);
	}
	if (texture->wall_no)
		free(texture->wall_no);
	if (texture->wall_so)
		free(texture->wall_so);
	if (texture->wall_we)
		free(texture->wall_we);
	if (texture->wall_ea)
		free(texture->wall_ea);
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

int	free_all(t_game *game)
{
	free_texture(game->state, game->state->texture);
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