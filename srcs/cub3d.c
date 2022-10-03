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
		return (ft_print_error(cub3d, WRONG_EXTENTION));
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		return (ft_print_error(cub3d, NO_FILE));
	cub3d->level_name = ft_strdup(argv);
	cub3d->fd = fd;
	return (SUCCESS);
}

void	ft_init_texture(t_cub3d *cub3d)
{
	cub3d->no.path = NULL;
	cub3d->so.path = NULL;
	cub3d->ea.path = NULL;
	cub3d->we.path = NULL;
}

void	ft_init_struct(t_cub3d *cub3d)
{
	ft_init_texture(cub3d);
	cub3d->exit_code = SUCCESS;
	cub3d->level_name = NULL;
	cub3d->map.map = NULL;
	cub3d->map.large = 0;
	cub3d->map.longu = 0;
	cub3d->map.x = 0;
	cub3d->map.y = 0;
	cub3d->fd = -1;
	cub3d->x = 0;
	cub3d->y = 0;
	cub3d->pos_x = 0;
	cub3d->pos_y = 0;
	cub3d->check_pos = 0;
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

void	ft_remove_newline(t_cub3d *cub3d, char *line)
{
	if (!line)
		return ;
	while (line && *line == '\n')
	{
		free(line);
		line = get_next_line(cub3d->fd);
	}
	if (*line && ft_strlen(line) > 0 && line[ft_strlen(line) - 1] == '\n')
		line[ft_strlen(line) - 1] = 0;
}

char	*ft_fill_line(t_cub3d *cub3d)
{
	char	*line;
	char	*gnl;
	int		i;
	int		j;

	i = 0;
	j = 0;
	line = (char *)ft_calloc(sizeof(char), cub3d->map.large + 1);
	if (!line)
		return (cub3d->exit_code = MALLOC_FAILURE, NULL);
	gnl = get_next_line(cub3d->fd);
	ft_remove_newline(cub3d, line);
	while (gnl && *gnl == '\n')
	{
		free(gnl);
		gnl = get_next_line(cub3d->fd);
	}
	while (gnl[i] != '\n' && gnl[i] != 0)
	{
		if (gnl[i] != ' ')
			line[j++] = gnl[i];
		i++;
	}
	free(gnl);
	return (line);
}

void	ft_fill_map(t_cub3d *cub3d)
{
	char	**res;
	int		i;

	res = (char **)ft_calloc(sizeof(char *), cub3d->map.longu + 1);
	if (!res)
		return (cub3d->exit_code = MALLOC_FAILURE, (void)0);
	cub3d->fd = open(cub3d->level_name, O_RDONLY);
	if (cub3d->fd < 0)
		return (cub3d->exit_code = OPEN_FAILED, (void)0);
	i = 0;
	while (i < cub3d->map.longu)
	{
		res[i] = ft_fill_line(cub3d);
		if (!res[i])
			return (ft_free_array((void **)res, free));
		i++;
	}
	cub3d->map.map = res;
	close(cub3d->fd);
	cub3d->fd = -1;
}

t_error_code	ft_fill_and_check_map(t_cub3d *cub3d)
{
	char	*line;

	line = get_next_line(cub3d->fd);
	ft_remove_newline(cub3d, line);
	cub3d->map.large = ft_size_line(line, cub3d);
	if (cub3d->map.large < 3)
		return (ft_print_error(cub3d, INVALID_MAP_SIZE));
	while (line)
	{
		if (ft_size_line(line, cub3d) != cub3d->map.large)
			return (free(line), ft_print_error(cub3d, INVALID_MAP_SIZE));
		free(line);
		cub3d->map.longu++;
		line = get_next_line(cub3d->fd);
		ft_remove_newline(cub3d, line);
	}
	close(cub3d->fd);
	cub3d->fd = -1;
	ft_fill_map(cub3d);
	return (SUCCESS);
}

void	ft_free_struct(t_cub3d *cub3d)
{
	if (cub3d->level_name)
		free(cub3d->level_name);
	if (cub3d->fd > 2)
		close(cub3d->fd);
	ft_free_array((void **)cub3d->map.map, free);
}

void	ft_add_texture_path(t_cub3d *cub3d, char *line, t_direction dir)
{
	// Check if struct was already filled to avoid duplicate
	// Store the given path to struct for the mlx part
	(void)cub3d;
	(void)line;
	printf("%d\n", dir);
}

t_error_code	ft_fill_info(t_cub3d *cub3d)
{
	char	*line;
	int		i;

	line = get_next_line(cub3d->fd);
	if (!line)
		return (ft_print_error(cub3d, INVALID_DESCRIPTOR));
	i = 0;
	while (line)
	{
		ft_remove_newline(cub3d, line);
		if (!*line)
			continue ;
		ft_skip_spaces(line, &i);
		if (line[i] == 'N')
			ft_add_texture_path(cub3d, line, NORTH);
		else if (line[i] == 'S')
			ft_add_texture_path(cub3d, line, SOUTH);
		else if (line[i] == 'E')
			ft_add_texture_path(cub3d, line, EAST);
		else if (line[i] == 'W')
			ft_add_texture_path(cub3d, line, WEST);
		else if (ft_isdigit(line[i]))
			break ;
		else
			return (ft_print_error(cub3d, INVALID_DESCRIPTOR));
		free(line);
		line = get_next_line(cub3d->fd);
	}
	return (free(line), SUCCESS);
}

void	ft_parsing(char *argv, t_cub3d *cub3d)
{
	if (ft_check_file(argv, cub3d) != SUCCESS)
		return ;
	if (ft_fill_info(cub3d) != SUCCESS)
		return ;
	if (ft_fill_and_check_map(cub3d) != SUCCESS)
		return ;
	if (check_player_position(cub3d->map.map, cub3d) != SUCCESS)
		return ;
}
void	running(t_game *game)
{
	int x;

	x = 0;
	while (x < WIN_W)
	{
		renew_player_value(game->state->p1, x);
		step_player(game->state->p1);

		x++;
	}
}

void	game_start(t_game *game)
{
	game->state->step_of_game = 2;
	init_struct_player(game->state->p1);
	game->state->p1->pos_x = game->state->pos->pos_x + 0.5;
	game->state->p1->pos_y = game->state->pos->pos_y + 0.5;
	set_player_view(game, game->state->p1);
	mlx_loop_hook(game->state->mlx_ptr, &running, game);
	//running : game is still running,continue ray_casting
	//->check step, renew the values
	mlx_hook(game->state->win_ptr, 0, 1L << 0, &key_press, game);
	mlx_hook(game->state->win_ptr, 17, 1L << 0, &free_all_exit, game);
	mlx_loop(game->state->mlx_ptr);
}

int	main(int argc, char *argv[], char **envp)
{
	t_cub3d			cub3d;
	t_error_code	code;
	t_game 			*game;

	game = NULL;
	if (!envp)
		return (ft_print_error(NULL, NO_ENV));
	if (argc != 2)
		return (ft_print_error(NULL, ARGC_ERROR));
	argv++;
	game = init_struct_game(game);
	game->state->mlx_ptr = mlx_init();
	if (!game->state->mlx_ptr)
		ft_error_and_exit(ERROR_MLX, game);
	ft_init_struct(&cub3d);
	ft_parsing(*argv, &cub3d);
	int	i = 0;
	while (cub3d.map.map[i])
	{
		game->map[i] = ft_strdup(cub3d.map.map[i]);
		printf("%s\n", cub3d.map.map[i++]);
	}
	if (init_mlx_and_window(game, game->state, &game->win))
		ft_error_and_exit(ERROR_MLX, game);
	check_player_position(cub3d.map.map, &cub3d);
	introduction_of_game(game,  game->state);
	int	i = 0;
	while (game->map[i])
	{
		if (game->map[i]);
			free(game->map[i]);
		i++;
	}
	free_all(game);
	return (code = cub3d.exit_code, ft_free_struct(&cub3d), code);
}