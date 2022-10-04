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
	cub3d->mlx_ptr = mlx_init();
}

int	running(t_cub3d *cub3d)
{
	int x;

	x = 0;
	while (x < cub3d->window.width)
	{
		renew_player_value(cub3d, &(cub3d->p1), x);
		step_player(&(cub3d->p1));
		x++;
	}
	return (0);
}

void	game_start(t_cub3d *cub3d)
{
	cub3d->step_of_game = 2;
	cub3d->p1.pos_x = cub3d->pos.pos_x + 0.5;
	cub3d->p1.pos_y = cub3d->pos.pos_y + 0.5;
	set_player_view(cub3d, &(cub3d->p1));
	mlx_loop_hook(cub3d->mlx_ptr, &running, (void *)cub3d);
	//running : game is still running,continue ray_casting
	//->check step, renew the values
	mlx_hook(cub3d->window.win_ptr, 0, 1L << 0, &key_press, cub3d);
	mlx_hook(cub3d->window.win_ptr, 17, 1L << 0, &free_all_exit, cub3d);
	mlx_loop(cub3d->mlx_ptr);
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
	if (ft_init_struct(&cub3d) != SUCCESS)
		return (code = cub3d.exit_code, ft_free_struct(&cub3d), code);
	ft_parsing(*argv, &cub3d);
	if (cub3d.exit_code != SUCCESS)
		return (code = cub3d.exit_code, ft_free_struct(&cub3d), code);
	introduction_of_game(&cub3d);
	free_all(&cub3d);
	return (code = cub3d.exit_code, ft_free_struct(&cub3d), code);
}