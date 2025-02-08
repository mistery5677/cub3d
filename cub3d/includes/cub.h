/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mistery576 <mistery576@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 18:27:26 by mistery576        #+#    #+#             */
/*   Updated: 2025/02/08 02:05:41 by mistery576       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H
# include "../libraries/libft/libft.h"
# include "../libraries/minilibx/mlx.h"
# include <math.h>
# include <X11/X.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# define ESC 65307
# define WALL '1'
# define FLOOR '0'
# define BLOCK 64
# define WIDTH 1280
# define HEIGHT 720
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

typedef struct s_texture
{
	void    *no_texture;
	char    *so_texture;
	char    *we_texture;
	char    *ea_texture;
	char    *f_texture;
	char    *c_texture;
	int		color;
	void	*img;
	int		width;
	int		height;
	  
}   t_texture;

typedef struct s_map
{
	char        **matrix;
	int         height;
	int         width;
}   t_map;

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
}	t_player;

/* DEBUG */
typedef struct s_image_debug {
	void 	*mlx;
	void 	*win;
    void    *img;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
}   t_image_debug;

typedef struct s_image{
	void 	*mlx;
	void 	*win;
    void    *img;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
}   t_image;

typedef struct s_data
{
	void        *mlx;
	void        *win;
	float		fov;
	t_map       *map;
	t_player	*player;
	t_texture   *texture;
	t_image		*image;
	t_image_debug		*debug;
}   t_data;

/***  FONT name: ANSI Shadow
███████╗██████╗ ██████╗  ██████╗ ██████╗ ███████╗
██╔════╝██╔══██╗██╔══██╗██╔═══██╗██╔══██╗██╔════╝
█████╗  ██████╔╝██████╔╝██║   ██║██████╔╝███████╗
██╔══╝  ██╔══██╗██╔══██╗██║   ██║██╔══██╗╚════██║
███████╗██║  ██║██║  ██║╚██████╔╝██║  ██║███████
*/

int	close_game(t_data *data);

/***  FONT name: ANSI Shadow
██████╗  █████╗ ██████╗ ███████╗███████╗██████╗ 
██╔══██╗██╔══██╗██╔══██╗██╔════╝██╔════╝██╔══██╗
██████╔╝███████║██████╔╝███████╗█████╗  ██████╔╝
██╔═══╝ ██╔══██║██╔══██╗╚════██║██╔══╝  ██╔══██╗
██║     ██║  ██║██║  ██║███████║███████╗██║  ██║
╚═╝     ╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝╚═╝  ╚═╝          
 */
int	check_walls_texture(t_data *data, char *file);
int	check_map(t_data *data, int argc, char **argv);

/***  FONT name: ANSI Shadow
██╗███╗   ██╗██╗████████╗
██║████╗  ██║██║╚══██╔══╝
██║██╔██╗ ██║██║   ██║   
██║██║╚██╗██║██║   ██║   
██║██║ ╚████║██║   ██║   
╚═╝╚═╝  ╚═══╝╚═╝   ╚═╝        
 */

int create_window(t_data *data);
void	initialize_data(t_data *data);

/***  FONT name: ANSI Shadow
 ██████╗  █████╗ ███╗   ███╗███████╗██████╗ ██╗      █████╗ ██╗   ██╗
██╔════╝ ██╔══██╗████╗ ████║██╔════╝██╔══██╗██║     ██╔══██╗╚██╗ ██╔╝
██║  ███╗███████║██╔████╔██║█████╗  ██████╔╝██║     ███████║ ╚████╔╝ 
██║   ██║██╔══██║██║╚██╔╝██║██╔══╝  ██╔═══╝ ██║     ██╔══██║  ╚██╔╝  
╚██████╔╝██║  ██║██║ ╚═╝ ██║███████╗██║     ███████╗██║  ██║   ██║   
 ╚═════╝ ╚═╝  ╚═╝╚═╝     ╚═╝╚══════╝╚═╝     ╚══════╝╚═╝  ╚═╝   ╚═╝ 
 */

void gameplay(t_data *data);
void move_player(t_data *data);

/***  FONT name: ANSI Shadow 
██╗   ██╗████████╗██╗██╗     ███████╗
██║   ██║╚══██╔══╝██║██║     ██╔════╝
██║   ██║   ██║   ██║██║     ███████╗
██║   ██║   ██║   ██║██║     ╚════██║
╚██████╔╝   ██║   ██║███████╗███████║
*/

/*		VERIFY_MATRIX		*/
int	check_up_down(char *line);
int check_line_limit(char *line);
int	check_line(t_data *data, char *line, int x);


/***  FONT name: ANSI Shadow
██████╗ ███████╗███╗   ██╗██████╗ ███████╗██████╗ 
██╔══██╗██╔════╝████╗  ██║██╔══██╗██╔════╝██╔══██╗
██████╔╝█████╗  ██╔██╗ ██║██║  ██║█████╗  ██████╔╝
██╔══██╗██╔══╝  ██║╚██╗██║██║  ██║██╔══╝  ██╔══██╗
██║  ██║███████╗██║ ╚████║██████╔╝███████╗██║  ██║
 */
void put_pixel(int x, int y, int color, t_data *data);
void clear_image(t_data *data);
int	draw_loop(t_data *data);
float ray_cast(t_data *data, float start_x, int i);

/**
████████╗███████╗██╗  ██╗████████╗██╗   ██╗██████╗ ███████╗███████╗
╚══██╔══╝██╔════╝╚██╗██╔╝╚══██╔══╝██║   ██║██╔══██╗██╔════╝██╔════╝
   ██║   █████╗   ╚███╔╝    ██║   ██║   ██║██████╔╝█████╗  ███████╗
   ██║   ██╔══╝   ██╔██╗    ██║   ██║   ██║██╔══██╗██╔══╝  ╚════██║
   ██║   ███████╗██╔╝ ██╗   ██║   ╚██████╔╝██║  ██║███████╗███████║
   ╚═╝   ╚══════╝╚═╝  ╚═╝   ╚═╝    ╚═════╝ ╚═╝  ╚═╝╚══════╝╚══════╝
 */
float fixed_calculate_distance(float x1, float y1, float x2, float y2, t_data *data);
void draw_textures(t_data *data, int i, float ray_x, float ray_y, int side);


/***
██████╗ ███████╗██████╗ ██╗   ██╗ ██████╗ 
██╔══██╗██╔════╝██╔══██╗██║   ██║██╔════╝ 
██║  ██║█████╗  ██████╔╝██║   ██║██║  ███╗
██║  ██║██╔══╝  ██╔══██╗██║   ██║██║   ██║
██████╔╝███████╗██████╔╝╚██████╔╝╚██████╔╝
╚═════╝ ╚══════╝╚═════╝  ╚═════╝  ╚═════╝
 */

void debug_window(t_data *data);
#endif