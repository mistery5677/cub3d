/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thopgood <thopgood@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 18:27:26 by mistery576        #+#    #+#             */
/*   Updated: 2025/02/12 12:17:09 by thopgood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H
# include "../libraries/libft/include/libft.h"
# include "../libraries/minilibx/mlx.h"
# include "errors.h"
# include <fcntl.h>
// # include "macro.h"
# include "structs.h"
# include <linux/types.h>
// #include <sys/stat.h>
# include <X11/X.h>
# include <errno.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define ESC 65307
# define WALL '1'
# define FLOOR '0'
# define BLOCK 64
# define ZOOM 3
# define SF ZOOM // Scale Factor
# define WIDTH 320
# define HEIGHT 180
# define ESC 65307
# define A 97
# define S 115
# define D 100
# define W 119
# define DEBUG 0

# define PURPLE 0x660033
# define GREEN 0x00FF00
# define BLUE 0x6666FF
# define GREY 0xA0A0A0
# define PINK 0xFF66B2
# define LEFT 65361
# define RIGHT 65363
# define PI 3.1415926535

typedef enum e_txt_type
{
	NO,
	SO,
	EA,
	WE,
	F,
	C,
	M
}				t_txt_type;

typedef struct s_parse
{
	int			rgb[3];
}				t_parse;

typedef struct s_texture
{
	void		*no_texture;
	void		*ea_texture;
	void		*so_texture;
	void		*we_texture;
	char		*no_path;		// ! not alloc'd
	char		*ea_path;
	char		*so_path;
	char		*we_path;
	int			f_texture;
	int			c_texture;
	int			color;
}				t_texture;

typedef struct s_map
{
	char		**matrix;
	int			height;
	int			width;
	bool		player_found;
}				t_map;

typedef struct s_player
{
	char		*look;
	float		speed;
	float		angle_speed;
	float		x_pst;
	float		y_pst;
	float		angle;
	int			player;
	bool		key_up;
	bool		key_down;
	bool		key_left;
	bool		key_right;
	bool		left_rotate;
	bool		right_rotate;
}				t_player;

/* DEBUG */
typedef struct s_image
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_image;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	float		fov;
	t_map		*map;
	t_player	*player;
	t_texture	*texture;
	t_image		*image;
	int			active; // 0 = nothing 1 = image 2 = window 3 = display
}				t_data;

/*
███████╗██████╗ ██████╗  ██████╗ ██████╗ ███████╗
██╔════╝██╔══██╗██╔══██╗██╔═══██╗██╔══██╗██╔════╝
█████╗  ██████╔╝██████╔╝██║   ██║██████╔╝███████╗
██╔══╝  ██╔══██╗██╔══██╗██║   ██║██╔══██╗╚════██║
███████╗██║  ██║██║  ██║╚██████╔╝██║  ██║███████
*/

int				close_game(t_data *data);
int				print_error(char *prefix, char *msg, int code);

/*
██████╗  █████╗ ██████╗ ███████╗███████╗██████╗
██╔══██╗██╔══██╗██╔══██╗██╔════╝██╔════╝██╔══██╗
██████╔╝███████║██████╔╝███████╗█████╗  ██████╔╝
██╔═══╝ ██╔══██║██╔══██╗╚════██║██╔══╝  ██╔══██╗
██║     ██║  ██║██║  ██║███████║███████╗██║  ██║
╚═╝     ╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝╚═╝  ╚═╝
 */
bool			is_map_valid(t_data *data, int argc, char **argv);
int				parse_rgb(t_data *data, char *line);
int				parse_texture(t_data *data, char *line, t_txt_type type);
int				parse_map(t_data *data, int fd, char *line);
int				trim_map(t_data *data);
int				find_longest_usable_string(char **arr);
char			*trim_chars_from_start(char *str, int num_chars);
int				find_shortest_lead(char **arr);
int				parse_map_chars(t_map *data, char **map);

// * UTILS *
bool			is_line_only_spaces(char *line);
bool			are_textures_parsed(t_texture *t);
bool			is_file_dir(char *path);
bool			is_ext_valid(char *str, char *ext);
bool			is_first_occurrence(t_data *data, t_txt_type type);
int				ft_atoi_no_oflow(const char *nptr, bool *out_of_range);
int				print_matrix(char **matrix);
bool			isspace_not_nl(char c);
int				last_usable_char_index(char *str);
bool			is_valid_char(char c);

/*
██╗███╗   ██╗██╗████████╗
██║████╗  ██║██║╚══██╔══╝
██║██╔██╗ ██║██║   ██║
██║██║╚██╗██║██║   ██║
██║██║ ╚████║██║   ██║
╚═╝╚═╝  ╚═══╝╚═╝   ╚═╝
 */

int				create_window(t_data *data);
void			initialize_data(t_data *data);

/*
 ██████╗  █████╗ ███╗   ███╗███████╗██████╗ ██╗      █████╗ ██╗   ██╗
██╔════╝ ██╔══██╗████╗ ████║██╔════╝██╔══██╗██║     ██╔══██╗╚██╗ ██╔╝
██║  ███╗███████║██╔████╔██║█████╗  ██████╔╝██║     ███████║ ╚████╔╝
██║   ██║██╔══██║██║╚██╔╝██║██╔══╝  ██╔═══╝ ██║     ██╔══██║  ╚██╔╝
╚██████╔╝██║  ██║██║ ╚═╝ ██║███████╗██║     ███████╗██║  ██║   ██║
 ╚═════╝ ╚═╝  ╚═╝╚═╝     ╚═╝╚══════╝╚═╝     ╚══════╝╚═╝  ╚═╝   ╚═╝
 */

void			gameplay(t_data *data);
void			move_player(t_data *data);

/*
██╗   ██╗████████╗██╗██╗     ███████╗
██║   ██║╚══██╔══╝██║██║     ██╔════╝
██║   ██║   ██║   ██║██║     ███████╗
██║   ██║   ██║   ██║██║     ╚════██║
╚██████╔╝   ██║   ██║███████╗███████║
*/

/*		VERIFY_MATRIX		*/
int				check_up_down(char *line);
int				check_line_limit(char *line);
int				check_line(t_data *data, char *line, int x);

/*
██████╗ ███████╗███╗   ██╗██████╗ ███████╗██████╗
██╔══██╗██╔════╝████╗  ██║██╔══██╗██╔════╝██╔══██╗
██████╔╝█████╗  ██╔██╗ ██║██║  ██║█████╗  ██████╔╝
██╔══██╗██╔══╝  ██║╚██╗██║██║  ██║██╔══╝  ██╔══██╗
██║  ██║███████╗██║ ╚████║█████���╔╝███████╗��█║  ██║
 */
float	ray_cast(t_data *data, float start_x, int i);
void	put_pixel(int x, int y, int color, t_data *data);
void	clear_image(t_data *data);
int		draw_loop(t_data *data);

/**
████████╗███████╗██╗  ██╗████████╗██╗   ██╗██████╗ ███████╗███████╗
╚══██╔══╝██╔════╝╚██╗██╔╝╚══██╔══╝██║   ██║██╔══██╗██╔════╝██╔════╝
	 ██║   █████╗   ╚███╔╝    ██║   ██║   ██║██████╔╝█████╗  ███████╗
	 ██║   ██╔══╝   ██╔██╗    ██║   ██║   ██║██╔══██╗██╔══╝  ╚════██║
	 ██║   ███████╗██╔╝ ██╗   ██║   ╚██████╔╝██║  ██║███████╗███████║
	 ╚═╝   ╚══════╝╚═╝  ╚═╝   ╚═╝    ╚═════╝ ╚═╝  ╚═╝╚══════╝╚══════╝
 */
float	fixed_calculate_distance(float x2, float y2, t_data *data);
void	draw_textures(t_data *data, int i, float ray_x, float ray_y);
int		verify_side(t_data *data, float ray_x, float ray_y);

/*
██████╗ ███████╗██████╗ ██╗   ██╗ ██████╗
██╔��═██╗██╔════╝█��╔══██╗██║   ██║██╔════╝
██║  ██║█████╗  ██████╔╝██║   ██║██║  ███╗
██║  ██║██╔══╝  ██╔══██╗██║   ██║██║   ██║
██████╔╝███████╗██████╔╝╚██████╔╝╚██████╔╝
╚═════╝ ╚══════╝╚═════╝  ╚═════╝  ╚═════╝
 */

void			debug_window(t_data *data);
#endif