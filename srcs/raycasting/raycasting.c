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
    if (p1->side == 1)//sidedist:x
        p1->perp_wall_dist = (p1->side_dist_x - p1->delta_dist_x);
    else//sidedist:y
        p1->perp_wall_dist = (p1->side_dist_y - p1->delta_dist_y);        
    p1->line_height = (int)(WIN_H / p1->perp_wall_dist); 
}

void    dda_perform(g_game *game, t_player *p1)
{

      //perform DDA
      while (hit == 0)
      {
        //jump to next map square, either in x-direction, or in y-direction
        if (sideDistX < sideDistY)
        {
          sideDistX += deltaDistX;
          mapX += stepX;
          side = 0;
        }
        else
        {
          sideDistY += deltaDistY;
          mapY += stepY;
          side = 1;
        }
        //Check if ray has hit a wall
        if (worldMap[mapX][mapY] > 0) hit = 1;
      }
}