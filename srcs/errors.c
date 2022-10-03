/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 19:46:41 by ahocine           #+#    #+#             */
/*   Updated: 2022/10/03 19:46:43 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_print_error2(t_error_code error_code)
{
	if (error_code == INVALID_DESCRIPTOR)
	{
		ft_putstr_fd("parsing: invalid itentifier found on info.\n", _STD_ERR);
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
		ft_putstr_fd("parsing: invalid identifier found on map.\n", _STD_ERR);
	else if (error_code == DUPICATE_PATH)
		ft_putstr_fd("parsing: duplicate path.\n", _STD_ERR);
	else if (error_code == NO_MAP)
		ft_putstr_fd("file: file empty.\n", _STD_ERR);
	else if (error_code == DUPICATE_PATH)
		ft_putstr_fd("parsing: duplicate path.\n", _STD_ERR);
	else if (error_code == MAP_ERROR)
		ft_putstr_fd("parsing: map error\n", _STD_ERR);
	else
		ft_print_error2(error_code);
	if (cub3d)
		cub3d->exit_code = error_code;
	ft_putstr_fd("exiting...\n", _STD_ERR);
	return (error_code);
}
