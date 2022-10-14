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

#include "../includes/cub3d_bonus.h"

char	*ft_fill_line(t_cub3d *cub3d, int line_nb)
{
	char	*line;
	char	*gnl;
	int		i;

	gnl = ft_skip_info(cub3d);
	if (!gnl)
		return (NULL);
	i = 0;
	line = (char *)ft_calloc(sizeof(char), cub3d->map.large + 1);
	ft_strcpy(line, gnl);
	while (line && i < cub3d->map.large)
	{
		if (line[i] == 'N' || line[i] == 'S' || line[i] == 'E' || \
		line[i] == 'W')
		{
			cub3d->pos.pos_x = i;
			cub3d->pos.pos_y = line_nb;
			cub3d->pos.pos = line[i];
		}
		i++;
	}
	return (free(gnl), line);
}

t_error_code	ft_check_inside_map(t_cub3d *cub3d, char *prev, char *curr)
{
	int		i;

	i = 0;
	if (prev && curr)
	{
		while (++i < cub3d->map.large - 1)
		{
			if (curr[i] == '0')
			{
				if (!curr[i + 1] || curr[i + 1] == ' ')
					return (ft_print_error(cub3d, NOT_SURROUNDED));
				else if (!curr[i - 1] || curr[i - 1] == ' ')
					return (ft_print_error(cub3d, NOT_SURROUNDED));
				else if (!prev[i] || prev[i] == ' ')
					return (ft_print_error(cub3d, NOT_SURROUNDED));
				else if (!prev[i - 1] || prev[i - 1] == ' ')
					return (ft_print_error(cub3d, NOT_SURROUNDED));
				else if (!prev[i + 1] || prev[i + 1] == ' ')
					return (ft_print_error(cub3d, NOT_SURROUNDED));
			}
		}
	}
	return (SUCCESS);
}

t_error_code	ft_check_border_map(t_cub3d *cub3d, char **map)
{
	int	ln;
	int	col;

	ln = 0;
	col = cub3d->map.large - 1;
	while (ln < cub3d->map.longu)
	{
		if (map[ln][0] == '0' || ft_isalpha(map[ln][0]) || \
		map[ln][col] == '0' || ft_isalpha(map[ln][col]))
			return (ft_print_error(cub3d, NOT_SURROUNDED));
		ln++;
	}
	col = 0;
	ln = cub3d->map.longu - 1;
	while (col < cub3d->map.large)
	{
		if (map[0][col] == '0' || ft_isalpha(map[0][col]) || \
		map[ln][col] == '0' || ft_isalpha(map[ln][col]))
			return (ft_print_error(cub3d, NOT_SURROUNDED));
		col++;
	}
	return (SUCCESS);
}

void	ft_convert_space(t_cub3d *cub3d)
{
	int	ligne;
	int	col;

	ligne = 0;
	while (ligne < cub3d->map.longu)
	{
		col = 0;
		while (col < cub3d->map.large)
		{
			if (cub3d->map.map[ligne][col] == ' ' || \
			cub3d->map.map[ligne][col] == 0)
				cub3d->map.map[ligne][col] = '1';
			col++;
		}
		ligne++;
	}
}

void	ft_fill_map(t_cub3d *cub3d)
{
	char	**res;
	int		i;

	res = (char **)ft_calloc(sizeof(char *), cub3d->map.longu + 1);
	if (!res)
		return (cub3d->exit_code = MALLOC_FAILURE, (void)0);
	i = 0;
	while (i < cub3d->map.longu)
	{
		res[i] = ft_fill_line(cub3d, i);
		if (!res[i])
			return (ft_free_array((void **)res, free));
		if (i && i < cub3d->map.large - 1 && \
		ft_check_inside_map(cub3d, res[i - 1], res[i]) != SUCCESS)
			return (ft_free_array((void **)res, free));
		i++;
	}
	if (ft_check_border_map(cub3d, res) != SUCCESS)
		return (ft_free_array((void **)res, free));
	cub3d->map.map = res;
	return (close(cub3d->fd), cub3d->fd = -1, ft_convert_space(cub3d));
}
