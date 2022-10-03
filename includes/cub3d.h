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
# include "../mlx/mlx.h"
# include <math.h>
# include <fcntl.h>
# include <limits.h>
# include <float.h>
# include <stdbool.h>

# define KEY_ESC		65307
# define KEY_W			119
# define KEY_A			97
# define KEY_S			115
# define KEY_D			100

typedef enum e_error_code	t_error_code;
typedef enum e_direction	t_direction;
typedef struct s_texture	t_texture;
typedef struct s_cub3d		t_cub3d;
typedef struct s_color		t_color;
typedef struct s_map		t_map;

enum	e_direction
{
	NORTH,
	SOUTH,
	EAST,
	WEST
};

enum	e_error_code
{
	SUCCESS,
	NO_ENV,
	BAD_FILE,
	ARGC_ERROR,
	WRONG_EXTENTION,
	WRONG_EXTENTION2,
	WRONG_COLOR,
	WRONG_SEPARATOR,
	INVALID_MAP_SIZE,
	INVALID_CHAR,
	INVALID_DESCRIPTOR,
	MALLOC_FAILURE,
	EMPTY_FILE,
	OPEN_FAILED,
	NO_MAP,
	DUPICATE_PATH
};

struct s_color
{
	int				red;
	int				green;
	int				blue;
};

struct s_map
{
	int				x;
	int				y;
	int				large;
	int				longu;
	char			**map;
};

struct s_texture
{
	t_direction		direction;
	char			*path;
};

struct s_cub3d
{
	char			*level_name;
	t_texture		no;
	t_texture		so;
	t_texture		ea;
	t_texture		we;
	t_color			floor;
	t_color			celling;
	int				exit_code;
	t_map			map;
	int				fd;
};

// checker_info
void			ft_fill_color(t_cub3d *cub3d, char c, int res, int nbr);
t_error_code	ft_check_identifier(t_cub3d *cub3d, char *s);
t_error_code	ft_check_colors(t_cub3d *cub3d, char *str);
t_error_code	ft_check_path(t_cub3d *cub3d, char *str);
t_error_code	ft_check_info(t_cub3d *cub3d);

// checker_map
t_error_code	ft_check_map(t_cub3d *cub3d);

// fill info
t_error_code	parse_txt(t_cub3d *cub3d, t_texture *texture, char *line);
t_error_code	ft_texture_handler(char *str, t_cub3d *cub3d);
void			ft_skip_gnl(t_cub3d *cub3d, char **line);
t_error_code	ft_fill_info(t_cub3d *cub3d);

// fill map
char			*ft_fill_line(t_cub3d *cub3d);
void			ft_fill_map(t_cub3d *cub3d);

// parsing utils
void			ft_remove_newline(t_cub3d *cub3d, char **line);
int				ft_size_line(char *line, t_cub3d *cub3d);
char			*ft_skip_info(t_cub3d *cub3d);
int				ft_valid_char_map(char c);

// struct handler
void			ft_init_struct(t_cub3d *cub3d);
void			ft_free_struct(t_cub3d *cub3d);

// errors
t_error_code	ft_print_error(t_cub3d *cub3d, t_error_code error_code);
void			ft_print_error2(t_error_code error_code);

// main
t_error_code	ft_check_file(char *argv, t_cub3d *cub3d);
void			ft_parsing(char *argv, t_cub3d *cub3d);
t_error_code	ft_reopen(t_cub3d *cub3d);

#endif
