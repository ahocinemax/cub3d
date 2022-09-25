/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 02:27:22 by ahocine           #+#    #+#             */
/*   Updated: 2022/09/25 02:27:35 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_error_code	ft_print_error(t_cub3d *cub3d, t_error_code error_code)
{
	ft_putstr_fd("\e[31mcub3d:\e[0m ", _STD_ERR);
	if (error_code == ARGC_ERROR)
		ft_putstr_fd("usage: ./cub3d [PATH_TO_VALID_MAP].\n", _STD_ERR);
	else if (error_code == NO_ENV)
		ft_putstr_fd("display: $DISPLAY env variable not set.\n", _STD_ERR);
	else if (error_code == NO_FILE)
		ft_putstr_fd("file: could not open file.\n", _STD_ERR);
	else if (error_code == WRONG_EXTENTION)
		ft_putstr_fd("file: select a valid '.cub' file, dumbass.\n", _STD_ERR);
	else if (error_code == INVALID_MAP_SIZE)
		ft_putstr_fd("parsing: must be a square.\n", _STD_ERR);
	else if (error_code == INVALID_CHAR)
		ft_putstr_fd("parsing: invalid identifier.\n", _STD_ERR);
	else
		ft_putstr_fd("Unexpected error, well done.\nexiting...\n", _STD_ERR);
	if (cub3d)
		cub3d->exit_code = error_code;
	return (error_code);
}

t_error_code	ft_check_file(char *argv, t_cub3d *cub3d)
{
	int	len;
	int	fd;

	len = ft_strlen(argv);
	if (len < 4 || ft_strncmp(argv + len - 4, ".cub", 4))
	{
		return (ft_print_error(cub3d, WRONG_EXTENTION));
	}
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		return (ft_print_error(cub3d, NO_FILE));
	cub3d->level_name = ft_strdup(argv);
	cub3d->fd = fd;
	return (SUCCESS);
}

void	ft_init_struct(t_cub3d *cub3d)
{
	cub3d->map.large = 0;
	cub3d->map.longu = 0;
	cub3d->x = 0;
	cub3d->y = 0;
}

int	ft_valid_char(char c)
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
		if (!ft_valid_char(line[i]))
			return (ft_print_error(cub3d, INVALID_CHAR), -1);
		if (line[i] != ' ')
			res++;
		i++;
	}
	return (res);
}

t_error_code	ft_fill_and_check_map(t_cub3d *cub3d)
{
	char	*line;

	line = get_next_line(cub3d->fd);
	cub3d->map.large = ft_size_line(line, cub3d);
	if (cub3d->map.large < 0)
		return (ft_print_error(cub3d, INVALID_MAP_SIZE));
	while (line)
	{
		printf("line; %s\n", line);
		if (ft_size_line(line, cub3d) != cub3d->map.large)
			return (free(line), ft_print_error(cub3d, INVALID_MAP_SIZE));
		free(line);
		cub3d->map.longu++;
		line = get_next_line(cub3d->fd);
	}
	return (SUCCESS);
}

void	ft_free_struct(t_cub3d *cub3d)
{
	free(cub3d->level_name);
}

int	main(int argc, char *argv[], char **envp)
{
	t_cub3d			cub3d;
	t_error_code	code;

	if (!envp)
		return (ft_print_error(NULL, NO_ENV));
	if (argc != 2)
		return (ft_print_error(NULL, ARGC_ERROR));
	argv++;
	ft_init_struct(&cub3d);
	if (ft_check_file(*argv, &cub3d) != SUCCESS)
		return (cub3d.exit_code);
	if (ft_fill_and_check_map(&cub3d) != SUCCESS)
		return (cub3d.exit_code);
	return (code = cub3d.exit_code, ft_free_struct(&cub3d), code);
}
