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
# define KEY_RETURN		65293
# define KEY_RIGHT		65363
# define KEY_LEFT		65361

typedef enum e_error_code	t_error_code;
typedef enum e_direction	t_direction;
typedef struct s_texture	t_texture;
typedef struct s_window		t_window;
typedef struct s_player		t_player;
typedef struct s_cub3d		t_cub3d;
typedef struct s_color		t_color;
typedef struct s_img		t_img;
typedef struct s_pos		t_pos;
typedef struct s_map		t_map;
typedef struct s_pic		t_pic;

struct s_pic
{
	void			*img;
	int				width;
	int				height;
};

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
	INVALID_PLAYER_NB,
	MALLOC_FAILURE,
	EMPTY_FILE,
	ERROR_IMAGE,
	OPEN_FAILED,
	NO_MAP,
	ERROR_MLX,
	DUPICATE_PATH,
	MAP_ERROR
};

struct s_img
{
	void			*mlx_img;
	char			*addr;
	int				bpp;
	int				line_len;
	int				endian;
	int				width;
	int				height;
};

struct s_window
{
	int				width;
	int				height;
	void			*win_ptr;
};

struct s_player
{
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			old_dir_x;
	double			plane_x;
	double			plane_y;
	double			old_plane_x;
	double			raydir_x;
	double			raydir_y;
    double  		camera_x;
	int				map_x;
	int				map_y;
	int				step_x;
	int				step_y;
	int				check_pos;
	double			time;
	double			old_time;
	double			side_dist_x;
	double			side_dist_y;
	double			delta_dist_x;
	double			delta_dist_y;
	double			perp_wall_dist;
	int				hit;
	int				side;
	int				line_height;
	double			rot_speed;
	double			move_speed;
};

struct s_pos
{
	char			pos;
	int				pos_x;
	int				pos_y;
	int				check_pos;
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
	void			*mlx_ptr;
	char			*level_name;
	int				step_of_game;
	t_pic			intro;
	t_window		*window;
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
t_error_code	ft_check_line(t_cub3d *cub3d, char *line);
t_error_code	ft_check_map(t_cub3d *cub3d);

// fill info
t_error_code	parse_txt(t_cub3d *cub3d, t_texture *texture, char *line);
t_error_code	ft_texture_handler(char *str, t_cub3d *cub3d);
void			ft_skip_gnl(t_cub3d *cub3d, char **line);
t_error_code	ft_fill_info(t_cub3d *cub3d);

// fill map
char			*ft_fill_line(t_cub3d *cub3d, int line_nb);
void			ft_fill_map(t_cub3d *cub3d);

// parsing utils
void			ft_remove_newline(t_cub3d *cub3d, char **line);
int				ft_size_line(char *line, t_cub3d *cub3d);
char			*ft_skip_info(t_cub3d *cub3d);
int				ft_valid_char_map(char c);

// struct handler
t_error_code	ft_init_struct(t_cub3d *cub3d);
void			ft_free_struct(t_cub3d *cub3d);

// errors
t_error_code	ft_print_error(t_cub3d *cub3d, t_error_code error_code);
void			ft_print_error2(t_error_code error_code);

// main
t_error_code	ft_check_file(char *argv, t_cub3d *cub3d);
void			ft_parsing(char *argv, t_cub3d *cub3d);
t_error_code	ft_reopen(t_cub3d *cub3d);

//raycasting
//setting player position
int				ft_valid_position(char c);
int				ft_no_void(char c);
int				ft_check_void(t_cub3d *cub3d, t_pos *pos, char **map);
t_error_code	check_player_position(t_cub3d *cub3d, char **map, t_pos *pos);

//init_raycasting structure
void			init_struct_player(t_player *p1);
void			set_player_view(t_cub3d *cub3d, t_player *p1);

//raycasting
void			perpwall_dist(t_player *p1);
void			dda_perform(t_cub3d *cub3d, t_player *p1);

//game
//free game structure
void			free_texture(t_state *state, t_texture *texture);
void			free_img(t_state *state, t_img *img);
void			free_pics(t_state *state, t_pic *pic);
void			free_game_and_mlx(t_state *state);
int				free_all(t_cub3d *cub3d);
int				free_all_exit(t_cub3d *cub3d);

//init_game
void			renew_player_value(t_player *p1, int x);
void			step_player(t_player *p1);

//init struct
int				ft_error_and_exit(char *error, t_cub3d *cub3d);
int				init_mlx_and_window(t_cub3d *cub3d, t_win *window);
void			init_struct_malloc(t_cub3d *cub3d);
int				init_img(t_img *img);
void   			init_struct_pos(t_pos *pos);
void			init_player(t_player *p1);
void			init_pic(t_pic *pic);
void			init_picture(t_cub3d *cub3d);
void			init_color(t_color *color);
void			init_texture(t_cub3d *cub3d, t_texture *texture);
void			init_struct_state(t_cub3d *cub3d);

//intro_image
void			introduction_of_game(t_cub3d *cub3d);
int				key_press(int key, t_cub3d *cub3d);
int				key_press_other(int key, t_cub3d *cub3d);
void			right_key(t_cub3d *cub3d);
void			left_key(t_cub3d *cub3d);
void			d_key(t_cub3d *cub3d);
void			a_key(t_cub3d *cub3d);
void			w_key(t_cub3d *cub3d);
void			s_key(t_cub3d *cub3d);

//main
void			game_start(t_cub3d *cub3d);
int				running(t_cub3d *cub3d);

//image
void			img_intro(t_cub3d *cub3d);

#endif
