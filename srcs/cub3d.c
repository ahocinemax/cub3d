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

// must handle when file was already open, and red or not (due to gnl).
// Sometimes it start at the begining, sometimes in the middle of file.
static void	ft_parsing(char *argv, t_cub3d *cub3d)
{
	if (ft_check_file(argv, cub3d) != SUCCESS)
		return ;
	if (ft_fill_info(cub3d) != SUCCESS)
		return ;
	if (cub3d->fd > 2)
		close(cub3d->fd);
	cub3d->fd = open(cub3d->level_name, O_RDONLY);
	if (cub3d->fd < 0)
		return (cub3d->exit_code = OPEN_FAILED, (void)0);
	if (ft_check_map(cub3d) != SUCCESS)
		return ;
	if (cub3d->fd > 2)
		close(cub3d->fd);
	cub3d->fd = open(cub3d->level_name, O_RDONLY);
	if (cub3d->fd < 0)
		return (cub3d->exit_code = OPEN_FAILED, (void)0);
	ft_fill_map(cub3d);
	if (cub3d->fd > 2)
		close(cub3d->fd);
	cub3d->fd = -1;
	if (cub3d->exit_code != SUCCESS)
		return ;
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
	ft_parsing(*argv, &cub3d);
	if (cub3d.exit_code != SUCCESS)
		return (code = cub3d.exit_code, ft_free_struct(&cub3d), code);
	return (code = cub3d.exit_code, ft_free_struct(&cub3d), code);
}
	// int	i = 0;
	// while (cub3d.map.map && cub3d.map.map[i])
	// 	printf("%s\n", cub3d.map.map[i++]);
