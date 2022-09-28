/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct_game.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsuji <mtsuji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:34:10 by mtsuji            #+#    #+#             */
/*   Updated: 2022/09/28 16:34:12 by mtsuji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void    init_struct_pos(t_pos *pos)
{
    pos->check_pos = 0;
    pos->pos_x = 0;
    pos->pos_y = 0;
}

void    init_struct_game(t_game *game, t_cub3d cub3d)
{
    init_struct_pos(game->pos);
/** 
    memo from Mariko:
    Je vais rajouter des autres fonctions pour
    initialiser des autres structure de
    t_game. mtn je initialise justement
    t_pos pour coder raycasting (09/28)
**/
}