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

t_error_code	ft_print_error(t_error_code error_code)
{
	ft_putstr_fd("\e[31mcub3d:\e[0m ", _STD_ERR);
	if (error_code == ARGC_ERROR)
		ft_putstr_fd("usage: ./cub3d [PATH_TO_VALID_MAP]\n", _STD_ERR);
	else if (error_code == NO_ENV)
		ft_putstr_fd("display: $DISPLAY env variable not set\n", _STD_ERR);
	else if (error_code == NO_FILE)
		ft_putstr_fd("file: could not open file.\n", _STD_ERR);
	else if (error_code == WRONG_EXTENTION)
		ft_putstr_fd("file: select a valid '.cub' file, dumbass\n", _STD_ERR);
	else
		ft_putstr_fd("Unexpected error, well done.\nexiting...\n", _STD_ERR);
	return (error_code);
}

int	ft_check_file(char *argv, t_cub3d *cub3d)
{
	int	len;
	int	fd;

	len = ft_strlen(argv);
	if (len < 4 || ft_strncmp(argv + len - 4, ".cub", 4))
		return (ft_print_error(WRONG_EXTENTION));
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		return (ft_print_error(NO_FILE));
	cub3d->level_name = ft_strdup(argv);
	return (close(fd), SUCCESS);
}

void	ft_init_struct(t_cub3d *cub3d)
{
	cub3d->x = 0;
	cub3d->y = 0;
}

void	ft_check_and_fill_map(t_cub3d *cub3d)
{
	(void)cub3d;
}

void	ft_free_struct(t_cub3d *cub3d)
{
	free(cub3d->level_name);
}

int	main(int argc, char *argv[], char **envp)
{
	t_cub3d	cub3d;

	if (!envp)
		return (ft_print_error(NO_ENV));
	if (argc != 2)
		return (ft_print_error(ARGC_ERROR));
	argv++;
	ft_init_struct(&cub3d);
	if (ft_check_file(*argv, &cub3d) != SUCCESS)
		return (1);
	ft_check_and_fill_map(&cub3d);
	ft_free_struct(&cub3d);
	return (0);
}
