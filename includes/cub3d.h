/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 02:28:04 by ahocine           #+#    #+#             */
/*   Updated: 2022/09/25 02:28:16 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"

typedef enum e_error_code	t_error_code;
typedef struct s_cub3d		t_cub3d;
typedef struct s_map		t_map;

enum	e_error_code
{
	SUCCESS,
	NO_ENV,
	NO_FILE,
	ARGC_ERROR,
	WRONG_EXTENTION,
	INVALID_MAP_SIZE,
	INVALID_CHAR,
	MALLOC_FAILURE,
	OPEN_FAILED
};

struct s_map
{
	int					x;
	int					y;
	int					large;
	int					longu;
	char				**map;
};

struct s_cub3d
{
	char	*level_name;
	int		exit_code;
	t_map	map;
	int		fd;
	int		x;
	int		y;
};

#endif
