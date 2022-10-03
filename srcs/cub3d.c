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

t_error_code	ft_reopen(t_cub3d *cub3d)
{
	if (cub3d->fd > 2)
		close(cub3d->fd);
	cub3d->fd = open(cub3d->level_name, O_RDONLY);
	if (cub3d->fd < 0)
		return (ft_print_error(cub3d, OPEN_FAILED));
	return (SUCCESS);
}

void	ft_parsing(char *argv, t_cub3d *cub3d)
{
	if (ft_check_file(argv, cub3d) != SUCCESS || ft_check_info(cub3d) != \
	SUCCESS || ft_reopen(cub3d) != SUCCESS || ft_fill_info(cub3d) != SUCCESS)
		return ;
	if (ft_reopen(cub3d) != SUCCESS || ft_check_map(cub3d) != SUCCESS || \
	ft_reopen(cub3d) != SUCCESS)
		return ;
	ft_fill_map(cub3d);
	if (cub3d->exit_code != SUCCESS)
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
	if (cub3d.exit_code != SUCCESS)
		return (code = cub3d.exit_code, ft_free_struct(&cub3d), code);
	int				i = 0;
	printf("%s\n%s\n%s\n%s\n\n", cub3d.no.path, cub3d.so.path, cub3d.ea.path, cub3d.we.path);
	printf("floor: [%d], [%d], [%d]\ncelling: : [%d], [%d], [%d]\n\n", cub3d.floor.red, cub3d.floor.green, cub3d.floor.blue, cub3d.celling.red, cub3d.celling.green, cub3d.celling.blue);
	while (cub3d.map.map && cub3d.map.map[i])
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