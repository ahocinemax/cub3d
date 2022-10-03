/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 14:50:22 by ahocine           #+#    #+#             */
/*   Updated: 2022/10/01 14:50:35 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_error_code	ft_check_path(t_cub3d *cub3d, char *str)
{
	int	i;

	if (!str)
		return (SUCCESS);
	i = 1;
	if (ft_isalpha(str[i]))
		i++;
	ft_skip_spaces(str, &i);
	while (str[i] && str[i] != ' ')
		i++;
	if (ft_strncmp(str + i - 4, ".xpm", 4))
		return (ft_print_error(cub3d, WRONG_EXTENTION2));
	ft_skip_spaces(str, &i);
	if (str[i] != 0)
		return (ft_print_error(cub3d, INVALID_DESCRIPTOR));
	return (SUCCESS);
}

void	ft_fill_color(t_cub3d *cub3d, char c, int res, int nbr)
{
	if (c == 'F')
	{
		if (nbr == 0)
			cub3d->floor.red = res;
		else if (nbr == 1)
			cub3d->floor.green = res;
		else if (nbr == 2)
			cub3d->floor.blue = res;
	}
	else
	{
		if (nbr == 0)
			cub3d->celling.red = res;
		else if (nbr == 1)
			cub3d->celling.green = res;
		else if (nbr == 2)
			cub3d->celling.blue = res;
	}
}

t_error_code	ft_check_colors(t_cub3d *cub3d, char *str)
{
	int	nbr;
	int	res;
	int	i;

	if (!str)
		return (SUCCESS);
	res = 0;
	i = 1;
	nbr = 0;
	while (str[i])
	{
		ft_skip_spaces(str, &i);
		if (!ft_isdigit(str[i]) && str[i] != '+' && str[i] != '-')
			return (ft_print_error(cub3d, INVALID_DESCRIPTOR));
		res = ft_atoi(str + i);
		if (res < 0 || res > 255 || nbr > 2)
			return (ft_print_error(cub3d, WRONG_COLOR));
		ft_fill_color(cub3d, *str, res, nbr);
		while (ft_isdigit(str[i]))
			i++;
		ft_skip_spaces(str, &i);
		if (str[i] && str[i] != ',')
			return (ft_print_error(cub3d, WRONG_SEPARATOR));
		i++;
		nbr++;
	}
	return (SUCCESS);
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
		if ((s[i] == 'N' || s[i] == 'S' || s[i] == 'E' || s[i] == 'W') && \
		ft_check_path(cub3d, s + i) != SUCCESS)
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
	return (ft_skip_gnl(cub3d, &s), free(s), SUCCESS);
}
