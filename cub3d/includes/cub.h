/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mistery576 <mistery576@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 18:27:26 by mistery576        #+#    #+#             */
/*   Updated: 2025/01/28 00:06:14 by mistery576       ###   ########.fr       */
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
# define BLOCK 32
# define WIDTH 1280
# define HEIGHT 720
# define ESC 65307
# define A 97
# define S 115
# define D 100
# define W 119
# define DEBUG 0

# define LEFT 65361
# define RIGHT 65363
# define PI 3.1415926535

typedef struct s_texture
{
	char    *no_texture;
	char    *so_texture;
	char    *we_texture;
	char    *ea_texture;
	char    *f_texture;
	char    *c_texture;
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
typedef struct s_image {
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