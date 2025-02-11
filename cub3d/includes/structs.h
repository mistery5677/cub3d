/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mistery576 <mistery576@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 20:17:37 by mistery576        #+#    #+#             */
/*   Updated: 2025/02/10 23:41:13 by mistery576       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H
# include "cub.h"
# include <stdbool.h>

typedef struct s_wall
{
	float			distance;
	float			height;
	void			*texture;
	int				side;
	int				start_y;
	int				end_y;
}	t_wall;

typedef struct s_texture
{
	void			*no_texture;
	void			*so_texture;
	void			*we_texture;
	void			*ea_texture;
	void			*img;
	char			*f_texture;
	char			*c_texture;
	int				color;
	int				width;
	int				height;
}	t_texture;

typedef struct s_map
{
	char			**matrix;
	int				height;
	int				width;
}	t_map;

typedef struct s_player
{
	float			speed;
	float			angle_speed;
	float			x_pst;
	float			y_pst;
	float			angle;
	char			*look;
	int				player;
	bool			key_up;
	bool			key_down;
	bool			key_left;
	bool			key_right;
	bool			left_rotate;
	bool			right_rotate;
}	t_player;

/* DEBUG */
typedef struct s_image_debug
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}	t_image_debug;

typedef struct s_image
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}	t_image;

typedef struct s_data
{
	t_image_debug	*debug;
	t_texture		*texture;
	t_player		*player;
	t_image			*image;
	t_wall			*wall;
	t_map			*map;
	void			*mlx;
	void			*win;
	void			*use_texture;
	float			fov;
}	t_data;

#endif