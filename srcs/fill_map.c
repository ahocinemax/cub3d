/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 14:50:22 by ahocine           #+#    #+#             */
/*   Updated: 2022/10/01 14:50:35 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*ft_fill_line(t_cub3d *cub3d)
{
	char	*line;
	char	*gnl;

	gnl = ft_skip_info(cub3d);
	if (!gnl)
		return (NULL);
	line = ft_strdup(gnl);
	return (free(gnl), line);
}

void	ft_fill_map(t_cub3d *cub3d, t_game *game)
{
	char	**res;
	int		i;

	res = (char **)ft_calloc(sizeof(char *), cub3d->map.longu + 1);
	if (!res)
		return (cub3d->exit_code = MALLOC_FAILURE, (void)0);
	i = 0;
	while (i < cub3d->map.longu)
	{
		res[i] = ft_fill_line(cub3d);
		if (!res[i])
			return (ft_free_array((void **)res, free));
		i++;
	}
	cub3d->map.map = res;
	game->map.map = res;
	close(cub3d->fd);
	cub3d->fd = -1;
}
