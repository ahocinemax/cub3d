/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsuji <mtsuji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 13:30:23 by mtsuji            #+#    #+#             */
/*   Updated: 2022/10/03 13:30:25 by mtsuji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	renew_player_value(t_player *p1, int x)
{
	p1->camera_x = 2 * x / (double)WIN_W - 1;
	p1->raydir_x = p1->dir_x + p1->plane_x * p1->camera_x;
	p1->raydir_y = p1->dir_y + p1->plane_y * p1->camera_x;
	p1->map_x = (int)p1->pos_x;
	p1->map_y = (int)p1->pos_y;
	p1->delta_dist_x = fabs(1 / p1->raydir_x);
	p1->delta_dist_y = fabs(1 / p1->raydir_y);
	p1->hit = 0;
	p1->line_height = 0;
}

void	step_player(t_player *p1)
{
	if (p1->raydir_x < 0)
	{
		p1->step_x = -1;
		p1->side_dist_x = (p1->pos_x - p1->map_x) * p1->delta_dist_x;
	}
	else
	{
		p1->step_x = 1;
		p1->side_dist_x = (p1->map_x + 1.0 - p1->pos_x) * p1->delta_dist_x;
	}
	if (p1->raydir_y < 0)
	{
		p1->step_y = -1;
		p1->side_dist_y = (p1->pos_y - p1->map_y) * p1->delta_dist_y;
	}
	else
	{
		p1->step_y = 1;
		p1->side_dist_y = (p1->map_y + 1.0 - p1->pos_y) * p1->delta_dist_y;
	}
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

void    perpwalldist(t_player *p1)
{
    if (p1->side == 1)//sidedist:x
        p1->perp_wall_dist = (p1->side_dist_x - p1->delta_dist_x);
    else//sidedist:y
        p1->perp_wall_dist = (p1->side_dist_y - p1->delta_dist_y);        
    p1->line_height = (int)(WIN_H / p1->perp_wall_dist); 
}