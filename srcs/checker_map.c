/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 19:46:27 by ahocine           #+#    #+#             */
/*   Updated: 2022/10/03 19:46:30 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_error_code	ft_check_map(t_cub3d *cub3d)
{
	char	*line;

	line = ft_skip_info(cub3d);
	if (!line)
		return (cub3d->exit_code);
	cub3d->map.large = ft_strlen(line);
	if (cub3d->map.large < 3)
		return (ft_print_error(cub3d, INVALID_MAP_SIZE));
	while (line)
	{
		if (ft_strlen(line) < cub3d->map.large)
			cub3d->map.large = ft_strlen(line);
		cub3d->map.longu++;
		free(line);
		line = get_next_line(cub3d->fd);
		ft_remove_newline(cub3d, &line);
	}
	return (SUCCESS);
}
