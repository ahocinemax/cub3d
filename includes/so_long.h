/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsuji <mtsuji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 11:47:57 by mtsuji            #+#    #+#             */
/*   Updated: 2022/06/10 17:05:00 by mtsuji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define HEIGHT 400
# define WIDTH 2000
# define ASSETS 4
# define ERROR 1
# define RENDER 10000

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"

typedef struct s_mlx
{
	void	*mlx_win;
	void	*mlx;
	t_img	*mlx_img;
}	t_mlx;

typedef struct s_asset
{
	t_img	*enemy1;
	t_img	*enemy2;
	t_img	*enemy3;
	t_img	*enemy4;
	t_img	*enemy[4];
	t_img	*player1;
	t_img	*player2;
	t_img	*player3;
	t_img	*player4;
	t_img	*player_left;
	int		enemy_img;
}	t_asset;

typedef struct s_game
{
	t_mlx	mlx;
	int		map_height;
	int		map_width;
	int		fd;
	int		line_char;
	int		line_num;
	int		line_end;
	int		number;
	int		x;
	int		y;
	int		move;
	int		star;
	int		enemy_count;
	int		player_count;
	char	*map;
	t_img	img;
	t_img	*home;
	t_img	*back;
	t_img	*wall;
	t_img	*collect;
	t_img	*player;
	t_img	**enemy;
	t_asset	asset;
}	t_game;

//key_hook
int		exit_hook(t_game *game);
int		key_hook(int keycode, t_game *game);
int		reduce_window(t_game *game);
//error + checker
void	error_message(char *message, char *map);
void	check_wall(char *line, char *map_all);
void	check_elements(char *map_all);
void	free_asset(t_game *game);
void	checker_enemy(t_img **enemy, t_game *game);
//action
void	right(t_game *game);
void	left(t_game *game);
void	up(t_game *game);
void	down(t_game *game);
//render_map
char	init_map(t_game *game, char *map);
void	deal_line(int ret, char *line, t_game *game, char *map_all);
void	init_map2(t_game *game, char *map_all);
//init_images
void	load_image(t_game *game, t_img **image, char *filename);
void	image_setting(t_game *game);
void	player_setting(t_game *game);
void	enemy_setting(t_game *game);
//drawing
void	draw(t_game *game);
void	draw_one_image(t_game *game, t_img *image, int x, int y);
void	draw_pixel(t_img *mlx_img, int x, int y, int color);
void	checker_image(char c, t_game *game);
int		render(t_game *game);
//bonus
void	destroy_enemy(t_game *game);
void	printer_ascii(char *filename);
void	game_clear(t_game *game);
void	game_over(t_game *game);
void	action_enemy(t_game *game);
void	act_counter(t_game *game);
#endif
