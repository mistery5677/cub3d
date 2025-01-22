/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mistery576 <mistery576@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 18:27:26 by mistery576        #+#    #+#             */
/*   Updated: 2025/01/22 22:49:44 by mistery576       ###   ########.fr       */
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
# define WIDTH 1000
# define HEIGHT 1000

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
	float		x_pst;
	float		y_pst;
	float		angle;
	int			player;
}	t_player;

typedef struct s_data
{
	void        *mlx;
	void        *win;
	float		fov;
	t_map       *map;
	t_player	*player;
	t_texture   *texture;
}   t_data;

/***  FONT name: ANSI Shadow
███████╗██████╗ ██████╗  ██████╗ ██████╗ ███████╗
██╔════╝██╔══██╗██╔══██╗██╔═══██╗██╔══██╗██╔════╝
█████╗  ██████╔╝██████╔╝██║   ██║██████╔╝███████╗
██╔══╝  ██╔══██╗██╔══██╗██║   ██║██╔══██╗╚════██║
███████╗██║  ██║██║  ██║╚██████╔╝██║  ██║███████
*/

void	free_all(t_data *data);

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
██████╗  █████╗ ██╗   ██╗ ██████╗ █████╗ ███████╗████████╗██╗███╗   ██╗ ██████╗ 
██╔══██╗██╔══██╗╚██╗ ██╔╝██╔════╝██╔══██╗██╔════╝╚══██╔══╝██║████╗  ██║██╔════╝ 
██████╔╝███████║ ╚████╔╝ ██║     ███████║███████╗   ██║   ██║██╔██╗ ██║██║  ███╗
██╔══██╗██╔══██║  ╚██╔╝  ██║     ██╔══██║╚════██║   ██║   ██║██║╚██╗██║██║   ██║
██║  ██║██║  ██║   ██║   ╚██████╗██║  ██║███████║   ██║   ██║██║ ╚████║╚██████╔╝
╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝    ╚═════╝╚═╝  ╚═╝╚══════╝   ╚═╝   ╚═╝╚═╝  ╚═══╝ ╚═════╝ 
 */

float ray_cast(t_data *data);

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