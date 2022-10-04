/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayscasting.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsuji <mtsuji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 15:48:22 by mtsuji            #+#    #+#             */
/*   Updated: 2022/09/27 15:48:25 by mtsuji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H
# define ERROR_MALLOC "malloc error"
# define ERROR_MLX "mlx_ptr error"
# define ERROR_IMAGE "image error"
# define WIN_H 800
# define WIN_W 1200 
# define INTRO "./image/intro.xpm"
/*
typedef struct s_win
{
    int win_width;
    int win_height;
}   t_win;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_pos
{
    char    pos;
    int     pos_x;
    int     pos_y;
	int		check_pos;
}   t_pos;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	old_dir_x;
	double	plane_x;
	double	plane_y;
	double	old_plane_x;
	double	raydir_x;
	double	raydir_y;
    double  camera_x;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		check_pos;
	double	time;
	double	old_time;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		hit;
	int		side;
	int		line_height;
	double	rot_speed;
	double	move_speed;
}	t_player;

typedef struct s_color
{
	int		r;
	int		g;
	int		b;
}	t_color;



typedef struct s_pic
{
	void	*img;
	int		width;
	int		height;
}	t_pic;



typedef struct s_game
{
	char		**map;
	t_state		*state;
	t_win		win;
	t_img		*img;
}	t_game;

//raycasting
//setting player position
int				ft_valid_position(char c);
int				ft_no_void(char c);
int				ft_check_void(t_cub3d *cub3d, t_pos *pos, char **map);
t_error_code    check_player_position(t_cub3d *cub3d, char **map, t_pos *pos);

//init_raycasting structure
void			init_struct_player(t_player *p1);
void			set_player_view(t_game *game, t_player *p1);

//raycasting
void			perpwall_dist(t_player *p1);
void			dda_perform(t_game *game, t_player *p1);

//game
//free game structure
void			free_texture(t_state *state, t_texture *texture);
void			free_img(t_state *state, t_img *img);
void			free_pics(t_state *state, t_pic *pic);
void			free_game_and_mlx(t_state *state);
int				free_all(t_game *game);
int				free_all_exit(t_game *game);

//init_game
void			renew_player_value(t_player *p1, int x);
void			step_player(t_player *p1);

//init struct
int				ft_error_and_exit(char *error, t_game *game);
int				init_mlx_and_window(t_game *game, t_state *state, t_win *window);
void			init_struct_malloc(t_game *game);
int				init_img(t_img *img);
void   			init_struct_pos(t_pos *pos);
void			init_player(t_player *p1);
void			init_pic(t_pic *pic);
void			init_picture(t_game *game, t_state *state);
void			init_color(t_color *color);
void			init_texture(t_game *game, t_texture *texture);
void			init_struct_state(t_game *game, t_state *state);
t_game			*init_struct_game(t_game *game);

//intro_image
void			introduction_of_game(t_game *game, t_state *state);
int				key_press(int key, t_game *game);
int				key_press_other(int key, t_game *game);
void			right_key(t_game *game);
void			left_key(t_game *game);
void			d_key(t_game *game);
void			a_key(t_game *game);
void			w_key(t_game *game);
void			s_key(t_game *game);

//main
void			game_start(t_game *game);
int				running(t_game *game);

//image
//image
void			img_intro(t_game *game, t_state *state);

#endif