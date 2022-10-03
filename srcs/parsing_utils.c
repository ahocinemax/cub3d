/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_tils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 14:50:22 by ahocine           #+#    #+#             */
/*   Updated: 2022/10/01 14:50:35 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_valid_char_map(char c)
{
	return (c == '1' || c == '0' || c == ' ' || c == 'N' || c == 'S' || \
	c == 'E' || c == 'W');
}

int	ft_size_line(char *line, t_cub3d *cub3d)
{
	int	res;
	int	i;

	i = 0;
	res = 0;
	if (!line)
		return (0);
	while (line[i])
	{
		if (!ft_valid_char_map(line[i]))
			return (ft_print_error(cub3d, INVALID_CHAR), -1);
		if (line[i] != ' ')
			res++;
		i++;
	}
	return (res);
}

void	ft_remove_newline(t_cub3d *cub3d, char **line)
{
	if (!*line)
		return ;
	while (*line && **line == '\n')
	{
		free(*line);
		*line = get_next_line(cub3d->fd);
	}
	if (*line && ft_strlen(*line) > 0 && (*line)[ft_strlen(*line) - 1] == '\n')
		(*line)[ft_strlen(*line) - 1] = 0;
}

char	*ft_skip_info(t_cub3d *cub3d)
{
	char	*line;
	int		i;

	line = get_next_line(cub3d->fd);
	ft_remove_newline(cub3d, &line);
	i = 0;
	ft_skip_spaces(line, &i);
	while (line && !ft_isdigit(line[i]))
	{
		free(line);
		line = get_next_line(cub3d->fd);
		ft_remove_newline(cub3d, &line);
		i = 0;
		ft_skip_spaces(line, &i);
	}
	if (!line)
		return (ft_print_error(cub3d, NO_MAP), NULL);
	return (line);
}
