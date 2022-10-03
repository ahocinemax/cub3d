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

t_error_code	ft_check_identifier(char *str)
{
	if ((*str == 'N' || *str == 'S') && *(str + 1) != ' ' && *(str + 1) != 'O')
		return (INVALID_DESCRIPTOR);
	else if (*str == 'E' && *(str + 1) != ' ' && *(str + 1) != 'A')
		return (INVALID_DESCRIPTOR);
	else if (*str == 'W' && *(str + 1) != ' ' && *(str + 1) != 'E')
		return (INVALID_DESCRIPTOR);
	else if (*str == 'F' && *(str + 1) != ' ')
		return (INVALID_DESCRIPTOR);
	else if (*str == 'C' && *(str + 1) != ' ')
		return (INVALID_DESCRIPTOR);
	else if (*str != 'N' && *str != 'S' && *str != 'E' \
	&& *str != 'W' && *str != 'F' && *str != 'C' && *str != 0)
		return (INVALID_DESCRIPTOR);
	return (SUCCESS);
}

t_error_code	ft_check_info(t_cub3d *cub3d)
{
	char	*s;
	int		i;

	s = get_next_line(cub3d->fd);
	ft_remove_newline(cub3d, &s);
	while (s && !ft_isdigit(*s))
	{
		i = 0;
		ft_skip_spaces(s, &i);
		if (ft_check_identifier(s + i) != SUCCESS)
			return (ft_skip_gnl(cub3d, &s), free(s), \
			ft_print_error(cub3d, INVALID_CHAR));
		free(s);
		s = get_next_line(cub3d->fd);
		ft_remove_newline(cub3d, &s);
	}
	return (ft_skip_gnl(cub3d, &s), free(s), SUCCESS);
}
