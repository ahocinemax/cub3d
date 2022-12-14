/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 14:50:22 by ahocine           #+#    #+#             */
/*   Updated: 2022/10/05 18:09:23 by mtsuji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_error_code	ft_check_path(t_cub3d *cub3d, char *str)
{
	char	*tmp;
	int		i;

	if (!str)
		return (SUCCESS);
	i = 1;
	tmp = ft_strtrim(str, " \t");
	if (ft_isalpha(tmp[i]))
		i++;
	ft_skip_spaces(tmp, &i);
	while (tmp[i] && tmp[i] != ' ')
		i++;
	if (ft_strncmp(tmp + i - 4, ".xpm", 4))
		return (ft_print_error(cub3d, WRONG_EXTENTION2));
	ft_skip_spaces(tmp, &i);
	if (tmp[i] != 0)
		return (ft_print_error(cub3d, INVALID_DESCRIPTOR));
	free(tmp);
	return (SUCCESS);
}

void	ft_fill_color(t_cub3d *cub3d, char c, int res, int nbr)
{
	if (c == 'F')
	{
		if (nbr == 1)
			cub3d->floor.red = res;
		else if (nbr == 2)
			cub3d->floor.green = res;
		else if (nbr == 3)
			cub3d->floor.blue = res;
		cub3d->floor.nb = nbr;
	}
	else
	{
		if (nbr == 1)
			cub3d->celling.red = res;
		else if (nbr == 2)
			cub3d->celling.green = res;
		else if (nbr == 3)
			cub3d->celling.blue = res;
		cub3d->celling.nb = nbr;
	}
}

t_error_code	ft_check_colors(t_cub3d *cub3d, char *str)
{
	int	nbr;
	int	i;

	if (!str)
		return (SUCCESS);
	i = 0;
	nbr = 0;
	while (str[++i])
	{
		ft_skip_spaces(str, &i);
		if (!ft_isdigit(str[i]) && str[i] != '+' && str[i] != '-')
			return (ft_print_error(cub3d, INVALID_DESCRIPTOR));
		if (ft_atoi(str + i) < 0 || ft_atoi(str + i) > 255 || nbr++ > 2)
			return (ft_print_error(cub3d, WRONG_COLOR));
		ft_fill_color(cub3d, *str, ft_atoi(str + i), nbr);
		while (ft_isdigit(str[i]))
			i++;
		ft_skip_spaces(str, &i);
		if (str[i] && str[i] != ',')
			return (ft_print_error(cub3d, WRONG_SEPARATOR));
	}
	return (cub3d->floor.trgb = get_trgb(cub3d->floor.red, cub3d->floor.green, \
		cub3d->floor.blue),
		cub3d->celling.trgb = get_trgb(cub3d->celling.red, \
		cub3d->celling.green, cub3d->celling.blue), SUCCESS);
}

t_error_code	ft_check_identifier(t_cub3d *cub3d, char *s)
{
	if (!s || (*s != 'N' && *s != 'S' && *s != 'E' \
	&& *s != 'W' && *s != 'F' && *s != 'C' && *s != 0))
		return (ft_print_error(cub3d, INVALID_DESCRIPTOR));
	else if ((*s == 'N' || *s == 'S') && *(s + 1) != ' ' && *(s + 1) != 'O')
		return (ft_print_error(cub3d, INVALID_DESCRIPTOR));
	else if (*s == 'E' && *(s + 1) != ' ' && *(s + 1) != 'A')
		return (ft_print_error(cub3d, INVALID_DESCRIPTOR));
	else if (*s == 'W' && *(s + 1) != ' ' && *(s + 1) != 'E')
		return (ft_print_error(cub3d, INVALID_DESCRIPTOR));
	else if (*s == 'F' && *(s + 1) != ' ')
		return (ft_print_error(cub3d, INVALID_DESCRIPTOR));
	else if (*s == 'C' && *(s + 1) != ' ')
		return (ft_print_error(cub3d, INVALID_DESCRIPTOR));
	return (SUCCESS);
}

t_error_code	ft_check_info(t_cub3d *cub3d)
{
	char	*s;
	int		i;

	s = get_next_line(cub3d->fd);
	ft_remove_newline(cub3d, &s);
	i = 0;
	ft_skip_spaces(s, &i);
	while (s && !ft_isdigit(s[i]))
	{
		if (ft_check_identifier(cub3d, s + i) != SUCCESS)
			return (ft_skip_gnl(cub3d, &s), free(s), cub3d->exit_code);
		if (ft_valid_char_info(s[i]) && ft_check_path(cub3d, s + i) != SUCCESS)
			return (ft_skip_gnl(cub3d, &s), free(s), cub3d->exit_code);
		else if ((s[i] == 'C' || s[i] == 'F') && \
		ft_check_colors(cub3d, s + i) != SUCCESS)
			return (ft_skip_gnl(cub3d, &s), free(s), cub3d->exit_code);
		free(s);
		i = 0;
		s = get_next_line(cub3d->fd);
		ft_remove_newline(cub3d, &s);
		ft_skip_spaces(s, &i);
	}
	if (cub3d->celling.nb != 3 || cub3d->floor.nb != 3)
		return (ft_skip_gnl(cub3d, &s), ft_print_error(cub3d, WRONG_COLOR));
	return (ft_skip_gnl(cub3d, &s), SUCCESS);
}
