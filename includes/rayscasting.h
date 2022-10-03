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
# define WIN_H 1000
# define WIN_W 1200 

typedef enum e_direction
{
	NO,
	SO,
	EA,
	WE
}	t_direction;

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

typedef struct s_texture
{
	t_img	*wall_no;
	t_img	*wall_so;
	t_img	*wall_we;
	t_img	*wall_ea;
	t_color	*floor;
	t_color	*celling;
}	t_texture;

typedef struct s_pic
{
	void	*img;
	int		width;
	int		height;
}	t_pic;

typedef struct s_state
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			step_of_game;
	t_pic		*intro;
	t_texture	*texture;
	t_pos		*pos;
	t_player	*p1;
	t_img		*screen;
}	t_state;

typedef struct s_game
{
	char		**map;
	t_state		*state;
	t_win		win;
	t_img		*img;
}	t_game;


t_game    *init_struct_game(t_game *game);
void    ft_free_game(t_game *game);
void    init_struct_pos(t_pos *pos);
int	ft_error_and_exit(char *error, t_game *game);
int	free_all(t_game *game);
int	free_all_exit(t_game *game);
int	init_mlx_and_window(t_game *game, t_state *state, t_win *window);
void	introduction_of_game(t_game *game, t_state *state);
int	key_press(int key, t_game *game);
void	init_struct_player(t_player *p1);
void	set_player_view(t_game *game, t_player *p1);
void	game_start(t_game *game);
void    perpwall_dist(t_player *p1);
void    dda_perform(t_game *game, t_player *p1);
#endif