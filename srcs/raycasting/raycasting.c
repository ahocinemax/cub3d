/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsuji <mtsuji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:40:03 by mtsuji            #+#    #+#             */
/*   Updated: 2022/10/03 15:40:05 by mtsuji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void    perpwall_dist(t_player *p1)
{
    if (p1->side == NO || p1->side == SO)
        p1->perp_wall_dist = (p1->side_dist_x - p1->delta_dist_x);
    else
        p1->perp_wall_dist = (p1->side_dist_y - p1->delta_dist_y);        
    p1->line_height = (int)(WIN_H / p1->perp_wall_dist); 
}

void    dda_perform(t_game *game, t_player *p1)
{
      while (p1->hit == 0)
      {
        if (p1->side_dist_x < p1->side_dist_y)
        {
          p1->side_dist_x += p1->delta_dist_y;
          if (p1->map_x > 0)
            p1->map_x += p1->step_x;
          if (p1->raydir_x > 0)
            p1->side = EA;
          else
            p1->side = WE;
        }
        else
        {
          p1->side_dist_y += p1->delta_dist_y;
          if (p1->map_y > 0)
            p1->map_y += p1->step_y;
          if (p1->raydir_y > 0)
            p1->side = NO;
          else
            p1->side = SO;
        }
        if (game->map[p1->map_x][p1->map_y] > 0) 
          p1->hit = 1;
      }
}