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

t_error_code	ft_check_line(t_cub3d *cub3d, char *line)
{
	int			i;

	i = 0;
	while (line[i])
	{
		if (!ft_valid_char_map(line[i]))
			return (ft_print_error(cub3d, INVALID_CHAR));
		if (line[i] == 'N' || line[i] == 'S' || \
		line[i] == 'E' || line[i] == 'W')
			cub3d->nb_player++;
		if (cub3d->nb_player > 1)
			return (ft_print_error(cub3d, INVALID_PLAYER_NB));
		i++;
	}
	return (SUCCESS);
}

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
		if (ft_strlen(line) > cub3d->map.large)
			cub3d->map.large = ft_strlen(line);
		if (ft_check_line(cub3d, line) != SUCCESS)
			return (ft_skip_gnl(cub3d, &line), free(line), cub3d->exit_code);
		cub3d->map.longu++;
		free(line);
		line = get_next_line(cub3d->fd);
		ft_remove_newline(cub3d, &line);
	}
	if (cub3d->nb_player != 1)
		return (ft_print_error(cub3d, INVALID_PLAYER_NB));
	return (SUCCESS);
}

t_error_code	ft_check_file(char *argv, t_cub3d *cub3d)
{
	int	len;
	int	fd;

	len = ft_strlen(argv);
	if (!len)
		return (ft_print_error(cub3d, ARGC_ERROR));
	if (len < 4 || ft_strncmp(argv + len - 4, ".cub", 4))
		return (ft_print_error(cub3d, WRONG_EXTENTION));
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		return (ft_print_error(cub3d, BAD_FILE));
	cub3d->level_name = ft_strdup(argv);
	cub3d->fd = fd;
	return (SUCCESS);
}
