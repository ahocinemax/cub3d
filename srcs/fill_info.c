/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 14:50:22 by ahocine           #+#    #+#             */
/*   Updated: 2022/10/01 14:50:35 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_skip_gnl(t_cub3d *cub3d, char **line)
{
	while (*line)
	{
		free(*line);
		*line = get_next_line(cub3d->fd);
	}
}

t_error_code	parse_txt(t_cub3d *cub3d, t_texture *txt, char *line)
{
	int		i;

	i = 1;
	if (!line || !txt)
		return (SUCCESS);
	if (txt->path)
		return (ft_print_error(cub3d, DUPICATE_PATH));
	if (line[i] && ft_isalpha(*line))
		i++;
	ft_skip_spaces(line, &i);
	txt->path = ft_strdup(line + i);
	return (SUCCESS);
}

t_error_code	ft_texture_handler(char *str, t_cub3d *cub3d)
{
	if (*str == 'N')
		return (parse_txt(cub3d, &(cub3d->no), str));
	else if (*str == 'S')
		return (parse_txt(cub3d, &(cub3d->so), str));
	else if (*str == 'E')
		return (parse_txt(cub3d, &(cub3d->ea), str));
	else if (*str == 'W')
		return (parse_txt(cub3d, &(cub3d->we), str));
	return (SUCCESS);
}

t_error_code	ft_fill_info(t_cub3d *cub3d)
{
	char	*line;
	int		i;

	line = get_next_line(cub3d->fd);
	if (!line)
		return (ft_print_error(cub3d, EMPTY_FILE));
	ft_remove_newline(cub3d, &line);
	while (line && !ft_isdigit(*line))
	{
		i = 0;
		if (!line || !*line)
			continue ;
		ft_skip_spaces(line, &i);
		if (line[i] == 'N' || line[i] == 'S' || line[i] == 'E' \
		|| line[i] == 'W' || line[i] == 'F' || line[i] == 'C' || line[i] == 0)
			ft_texture_handler(line + i, cub3d);
		else if (ft_isdigit(line[i]) || cub3d->exit_code != SUCCESS)
			break ;
		else
			return (free(line), ft_print_error(cub3d, INVALID_DESCRIPTOR));
		free(line);
		line = get_next_line(cub3d->fd);
		ft_remove_newline(cub3d, &line);
	}
	return (ft_skip_gnl(cub3d, &line), free(line), SUCCESS);
}
