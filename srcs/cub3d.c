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
	if (cub3d->exit_code != SUCCESS || ft_init_window(cub3d) != SUCCESS)
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
		line_height = (int)(cub3d->window.width / cub3d->p1.perp_wall_dist);
		draw_start = -line_height / 2 + cub3d->window.height / 2;
		if (draw_start < 0)
			draw_start = 0;
		draw_end = line_height / 2 + cub3d->window.height / 2;
		if (draw_end >= cub3d->window.height)
			draw_end = cub3d->window.height - 1;
		x++;
	}
	mlx_put_image_to_window(cub3d->mlx_ptr, cub3d->window.win_ptr, \
	cub3d->screen.mlx_img, 0, 0);
	return (0);
}

void	game_start(t_cub3d *cub3d)
{
	mlx_destroy_image(cub3d->mlx_ptr, cub3d->intro.img);
	cub3d->step_of_game = 2;
	cub3d->screen.mlx_img = mlx_new_image(cub3d->mlx_ptr, cub3d->window.width, \
	cub3d->window.height);
	if (!cub3d->screen.mlx_img)
		ft_print_error(cub3d, ERROR_IMAGE);
	cub3d->p1.pos_x = cub3d->pos.pos_x + 0.5;
	cub3d->p1.pos_y = cub3d->pos.pos_y + 0.5;
	set_player_view(cub3d, &(cub3d->p1));
	mlx_hook(cub3d->window.win_ptr, 0, 1L << 0, &key_press, cub3d);
	mlx_loop_hook(cub3d->mlx_ptr, &running, cub3d);
	mlx_hook(cub3d->window.win_ptr, 17, 1L << 0, &ft_free_struct, cub3d);
	mlx_loop(cub3d->mlx_ptr);
}

int	main(int argc, char *argv[], char **envp)
{
	t_cub3d			cub3d;

	if (!*envp)
		return (ft_print_error(NULL, NO_ENV));
	if (argc != 2)
		return (ft_print_error(NULL, ARGC_ERROR));
	argv++;
	ft_init_struct(&cub3d);
	ft_parsing(*argv, &cub3d);
	if (cub3d.exit_code != SUCCESS)
		return (ft_free_struct(&cub3d));
	introduction_of_game(&cub3d);
	game_start(&cub3d);
	return (ft_free_struct(&cub3d));
}
