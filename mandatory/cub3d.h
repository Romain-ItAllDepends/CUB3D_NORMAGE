/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 09:41:36 by rgobet            #+#    #+#             */
/*   Updated: 2024/09/23 09:39:59 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "MLX42/include/MLX42/MLX42.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define VIEW_HEIGHT 0.5
# define SCREEN 1
# define ROT_SPEED 0.06
# define MOVE_SPEED 0.10
# define HEIGHT 1024
# define WIDTH 1280
# define TEXHEIGHT 256
# define TEXWIDTH 256
# define MAX 1e30

typedef enum s_facing
{
	NORTH = 0,
	SOUTH = 1,
	WEST = 2,
	EAST = 3
}						t_facing;

typedef struct textures
{
	mlx_texture_t		*north;
	mlx_texture_t		*south;
	mlx_texture_t		*east;
	mlx_texture_t		*west;
	mlx_texture_t		*crosshair;
}						t_textures;

typedef struct images
{
	mlx_image_t			*north;
	mlx_image_t			*south;
	mlx_image_t			*east;
	mlx_image_t			*west;
	mlx_image_t			*crosshair;
	mlx_image_t			*screen;
}						t_images;

typedef struct raycast
{
	double				dirx;
	double				diry;
	double				planex;
	double				planey;
	double				ray_dirx;
	double				ray_diry;
	double				side_distx;
	double				side_disty;
	double				delta_distx;
	double				delta_disty;
	double				stepx;
	double				stepy;
	double				camerax;
	double				cameray;
	double				posx;
	double				posy;
	int					hit;
	int					mapx;
	int					mapy;
	int					side;
	int					draw_start;
	int					draw_end;
	int					texx;
	int					texy;
	double				perp_wall_dist;
	double				wallx;
	double				step;
	double				tex_pos;
	int					line_height;
	int32_t				color;
	t_facing			facing;
}						t_raycast;

typedef struct vars
{
	int					floor[3];
	int					ceiling[3];
	char				*north;
	char				*south;
	char				*east;
	char				*west;
	char				**map;

	t_raycast			*raycast;
	int32_t				mouse_pos[2];
	mlx_win_cursor_t	*cursor;
	t_images			*images;
	mlx_t				*window;
	t_textures			*textures;
}						t_vars;

/*
 * Initialize
 */

void					init(t_vars *vars, char *str);
void					raycast_vars_init(t_vars *vars);
void					initialize_vars(t_vars **vars, char *file);
void					initialize_window(t_vars *vars);
void					north_south_textures(char *str, t_vars *vars, char dir);
void					get_parameters(t_vars *vars, char **file);
void					get_player_pos(t_vars *vars);
void					get_colors(char *str, t_vars *vars);
void					get_textures(char *str, t_vars *vars);

/*
 * Parsing
 */

void					parse_file(char *file);
void					check_data(char **file);
void					check_map(char **map);
int						check_closed_map(char **map);
int						check_player_char(char **map);
void					check_diff_wall(char **map, char *tab, int x);

/*
 * Game
 */

void					paint_on_screen(t_vars *vars);
void					raycast(t_vars *vars, int x);
int32_t					get_color(int32_t pixel);
void					select_textures(t_vars *vars);
void					put_pixels(t_vars *vars, int x);
void					texture_coord(t_vars *vars);
void					wall_start_end(t_vars *vars);
void					right_utils(t_vars *vars, double moveSpeed);
void					left_utils(t_vars *vars, double moveSpeed);
void					forward_and_back_utils_s(t_vars *vars,
							double moveSpeed);
void					forward_and_back_utils_w(t_vars *vars,
							double moveSpeed);
void					forward_and_back(t_vars *vars, double moveSpeed);
void					right_and_left(t_vars *vars, double moveSpeed);
void					rotate_camera(t_vars *vars, double rotSpeed);

/*
 * Utils
 */

int						ft_strlen(const char *str);
int						len_db_char(char **str);
int						ft_strcspn(const char *s, char *reject);
char					*ft_strjoin(char const *s1, char const *s2);
char					*ft_strjoin_free_s1(char *s1, char *s2);
int						ft_atoi(const char *str);
int						ft_isalpha(char *str);
void					*ft_calloc(size_t nmemb, size_t size);
void					ft_putstr_fd(char *s, int fd);
char					**get_file(int fd);
char					**ft_split(char const *s, char c);
int						skip_space(char *str);
int						invert_skip_space(char *str);
char					**get_map(char **file);
int						start_map(char **file);
char					*copy(char *s);
void					get_borders(char *tab, char *line, int i);
int						verif_map_split(char *s);
int						is_parameter(char *s);
void					setup_textures(t_vars *vars);

/*
 * Errors
 */

void					nb_arg_error(void);
void					empty_arg(void);
void					error_fd(void);
void					error_extention(void);
int						verify_split(char **file, char *getter);
int						verify_rgb(char **rgb, int i);
void					verify_map(char **map, int i);
void					error_malloc(int fd, char **tab);
void					error_read(int fd, char *buffer, char *getter);
void					map_error(void);
void					color_error(t_vars *vars);
void					texture_error(t_vars *vars);
void					resize_error(t_vars *vars);
void					screen_error(t_vars *vars);

/*
 Free
*/

void					ft_free_vars(t_vars *vars);
void					ft_free(char **str);

#endif
