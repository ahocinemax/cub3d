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

void	ft_print_error2(t_error_code error_code)
{
	if (error_code == INVALID_DESCRIPTOR)
	{
		ft_putstr_fd("parsing: invalid itentifier.\n", _STD_ERR);
		ft_putstr_fd("usage: [ID] [PATH_TO_TEXTURE].\n\nID =\t-NO (N)\n\t-SO \
(S)\n\t-EA (E)\n\t-WE (W)\n\t-F\n\t-C\n", _STD_ERR);
	}
	else if (error_code == EMPTY_FILE)
		ft_putstr_fd("file: file is empty.\n", _STD_ERR);
	else
		ft_putstr_fd("Unexpected error, well done.\n", _STD_ERR);
}

t_error_code	ft_print_error(t_cub3d *cub3d, t_error_code error_code)
{
	ft_putstr_fd("\e[31mcub3d:\e[0m ", _STD_ERR);
	if (error_code == ARGC_ERROR)
		ft_putstr_fd("usage: ./cub3d [PATH_TO_VALID_MAP].\n", _STD_ERR);
	else if (error_code == NO_ENV)
		ft_putstr_fd("display: $DISPLAY env variable not set.\n", _STD_ERR);
	else if (error_code == BAD_FILE || error_code == OPEN_FAILED)
		ft_putstr_fd("file: could not open file.\n", _STD_ERR);
	else if (error_code == WRONG_EXTENTION)
		ft_putstr_fd("file: select a valid '.cub' file, dumbass.\n", _STD_ERR);
	else if (error_code == INVALID_MAP_SIZE)
		ft_putstr_fd("parsing: must be a square.\n", _STD_ERR);
	else if (error_code == INVALID_CHAR)
		ft_putstr_fd("parsing: invalid identifier.\n", _STD_ERR);
	else if (error_code == DUPICATE_PATH)
		ft_putstr_fd("parsing: duplicate path.\n", _STD_ERR);
	else if (error_code == NO_MAP)
		ft_putstr_fd("file: file empty.\n", _STD_ERR);
	else if (error_code == DUPICATE_PATH)
		ft_putstr_fd("parsing: duplicate path.\n", _STD_ERR);
	else
		ft_print_error2(error_code);
	if (cub3d)
		cub3d->exit_code = error_code;
	ft_putstr_fd("exiting...\n", _STD_ERR);
	return (error_code);
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
		if ((s[i] == 'N' || s[i] == 'S') && s[i + 1] != ' ' && s[i + 1] != 'O')
			return (ft_print_error(cub3d, INVALID_CHAR));
		else if (s[i] == 'E' && s[i + 1] != ' ' && s[i + 1] != 'A')
			return (ft_print_error(cub3d, INVALID_CHAR));
		else if (s[i] == 'W' && s[i + 1] != ' ' && s[i + 1] != 'E')
			return (ft_print_error(cub3d, INVALID_CHAR));
		else if (s[i] == 'F' && s[i + 1] != ' ')
			return (ft_print_error(cub3d, INVALID_CHAR));
		else if (s[i] == 'C' && s[i + 1] != ' ')
			return (ft_print_error(cub3d, INVALID_CHAR));
		else if (s[i] != 'N' && s[i] != 'S' && s[i] != 'E' \
		&& s[i] != 'W' && s[i] != 'F' && s[i] != 'C' && s[i] != 0)
			return (ft_print_error(cub3d, INVALID_CHAR));
		s = get_next_line(cub3d->fd);
		ft_remove_newline(cub3d, &s);
	}
	return (ft_skip_gnl(cub3d, &s), free(s), SUCCESS);
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
		if (ft_strlen(line) < cub3d->map.large)
			cub3d->map.large = ft_strlen(line);
		cub3d->map.longu++;
		free(line);
		line = get_next_line(cub3d->fd);
		ft_remove_newline(cub3d, &line);
	}
	return (SUCCESS);
}
