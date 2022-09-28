/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayscasting.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsuji <mtsuji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 15:48:22 by mtsuji            #+#    #+#             */
/*   Updated: 2022/09/27 15:48:25 by mtsuji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

typedef struct s_win
{
    int win_width;
    int win_height;
}   t_win;

typedef struct s_pos
{
    char    pos;
    int     pos_x;
    int     pos_y;
	int		check_pos;
}   t_pos;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	raydir_x;
	double	raydir_y;
    double  camera;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		check_pos;
}	t_player;

typedef struct s_game
{
    t_pos	   *pos;
	t_win		*win;
	t_player	*player;
}   t_game;


void    init_struct_game(t_game *game, t_cub3d cub3d);

#endif