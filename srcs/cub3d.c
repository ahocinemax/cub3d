/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 02:27:22 by ahocine           #+#    #+#             */
/*   Updated: 2022/10/05 18:14:54 by mtsuji           ###   ########.fr       */
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
	if (ft_init_window(cub3d) != SUCCESS)
		return ;
}

int	running(t_cub3d *cub3d)
{
	int	x;
	int	line_height;
	int	draw_start;
	int	draw_end;

	x = 0;
	while (x < cub3d->window.width)
	{
		renew_player_value(cub3d, &(cub3d->p1), x);
		step_player(&(cub3d->p1));
		while (cub3d->p1.hit == 0)
			dda_perform(cub3d, &(cub3d->p1));
		perpwall_dist(cub3d, &(cub3d->p1));
	//Calculate height of line to draw on screen
		line_height = (int)(cub3d->window.width / cub3d->p1.perp_wall_dist);
	//calculate lowest and highest pixel to fill in current stripe
		draw_start = -line_height / 2 + cub3d->window.height / 2;
		if (draw_start < 0)
			draw_start = 0;
		draw_end = line_height / 2 + cub3d->window.height / 2;
		if (draw_end >= cub3d->window.height)
			draw_end = cub3d->window.height - 1;
		// prepare_wall(cub3d, x, draw_start, draw_end);
		x++;
	}
	mlx_put_image_to_window(cub3d->mlx_ptr, cub3d->window.win_ptr, \
	cub3d->screen.mlx_img, 0, 0);
	return (0);
}

void	game_start(t_cub3d *cub3d)
{
	cub3d->step_of_game = 2;
	/*cub3d->screen.mlx_img = mlx_xpm_file_to_image(cub3d->mlx_ptr, \
	 * "./image/black.xpm", &(cub3d->window.width), &(cub3d->window.height));
	if (!cub3d->screen.mlx_img)
		ft_print_error(cub3d, ERROR_IMAGE);
	mlx_put_image_to_window(cub3d->mlx_ptr, cub3d->window.win_ptr, \
		cub3d->screen.mlx_img, 0, 0);*/
	cub3d->screen.mlx_img = mlx_new_image(cub3d->mlx_ptr, \
					cub3d->window.width, cub3d->window.height);
	if (!cub3d->screen.mlx_img)
		ft_print_error(cub3d, ERROR_IMAGE);
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

	if (!*envp)
		return (ft_print_error(NULL, NO_ENV));
	if (argc != 2)
		return (ft_print_error(NULL, ARGC_ERROR));
	argv++;
	ft_init_struct(&cub3d);
	ft_parsing(*argv, &cub3d);
	if (cub3d.exit_code != SUCCESS)
		return (code = cub3d.exit_code, ft_free_struct(&cub3d), code);
	printf("%s\n%s\n%s\n%s\n\n\n\n", cub3d.no.path, cub3d.so.path, \
		cub3d.ea.path, cub3d.we.path);
	printf("floor: [%d], [%d], [%d]\ncelling: : [%d], [%d], [%d]\n\n", \
		cub3d.floor.red, cub3d.floor.green, cub3d.floor.blue, \
		cub3d.celling.red, cub3d.celling.green, cub3d.celling.blue);
	int i = 0;
	while (cub3d.map.map && cub3d.map.map[i])
		printf("%s\n", cub3d.map.map[i++]);
	introduction_of_game(&cub3d);
	game_start(&cub3d);
	free_all_exit(&cub3d);
	return (0);
}
