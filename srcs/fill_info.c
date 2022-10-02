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

static int	ft_valid_char_info(char c, t_direction dir, int *i)
{
	if (dir == NORTH || dir == SOUTH)
	{
		if (c == 'O')
			(*i)++;
		return (c == 'O' || c == ' ');
	}
	else if (dir == EAST)
	{
		if (c == 'A')
			(*i)++;
		return (c == 'A' || c == ' ');
	}
	else
	{
		if (c == 'E')
			(*i)++;
		return (c == 'E' || c == ' ');
	}
}

void	ft_add_texture_path(t_cub3d *cub3d, t_texture *txt, \
char *line, t_direction dir)
{
	int		i;

	i = 0;
	if (!line)
		return ;
	if (txt->path)
		return (ft_print_error(cub3d, DUPICATE_PATH), (void)0);
	if (*line && ft_isalpha(*line))
		i++;
	if (line[i] && !ft_valid_char_info(line[i], dir, &i))
		return (ft_print_error(cub3d, INVALID_CHAR), (void)0);
	ft_skip_spaces(line, &i);
	txt->path = ft_strdup(line + i);
	printf("adding path= {%s}\n", txt->path);
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
		if (line[i] == 'N')
			ft_add_texture_path(cub3d, &(cub3d->no), line + i, NORTH);
		else if (line[i] == 'S')
			ft_add_texture_path(cub3d, &(cub3d->so), line + i, SOUTH);
		else if (line[i] == 'E')
			ft_add_texture_path(cub3d, &(cub3d->ea), line + i, EAST);
		else if (ft_isdigit(line[i]))
			break ;
		else
			return (free(line), ft_print_error(cub3d, INVALID_DESCRIPTOR));
		free(line);
		line = get_next_line(cub3d->fd);
		ft_remove_newline(cub3d, &line);
	}
	while (line)
	{
		free(line);
		line = get_next_line(cub3d->fd);
	}
	return (free(line), SUCCESS);
}
