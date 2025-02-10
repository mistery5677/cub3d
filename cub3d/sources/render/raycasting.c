/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miafonso <miafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:03:05 by mistery576        #+#    #+#             */
/*   Updated: 2025/02/10 14:39:35 by miafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

/* This funcstion has the fish eye effect*/
float	calculate_distance(float x, float y)
{
	return (sqrt(x * x + y * y));
}

/* Fix the fish eye effect*/
float	fixed_calculate_distance(float x2, float y2, t_data *data)
{
	float	delta_x;
	float	delta_y;
	float	angle;
	float	fix_distance;

	delta_x = x2 - data->player->x_pst;
	delta_y = y2 - data->player->y_pst;
	angle = atan2(delta_y, delta_x) - data->player->angle;
	fix_distance = calculate_distance(delta_x, delta_y) * cos(angle);
	return (fix_distance);
}

// static void draw_walls(t_data *data, int i, float ray_x, float ray_y)
// {
//     float distance;
//     float wall_height;
//     int start_y;
//     int end_y;
//     int y;
//     //int index;
//
//     y = 0;
//     distance = fixed_calculate_distance
//	(data->player->x_pst, data->player->y_pst, ray_x, ray_y, data);
//     wall_height = (BLOCK / distance) * (WIDTH / 2);
//     start_y = (HEIGHT - wall_height) / 2;
//     end_y = start_y + wall_height;

//     if (start_y < 0) 
//         start_y = 0;
//     if (end_y >= HEIGHT) 
//         end_y = HEIGHT - 1;
//     while (y < start_y)
//     {
//         put_pixel(i, y, 0xFF0000, data);
//         y++;
//     } 
// 	while (start_y <= end_y)
// 	{
// 		put_pixel(i, start_y, data->texture->color, data);
// 		start_y++;
// 	}
//     while (end_y <= HEIGHT)
//     {
//         put_pixel(i, end_y, 0x0000FF, data);
//         end_y++;
//     }
// }

// static void draw_texture(t_data *data, int i, float ray_x, float ray_y)
// {
//     (void)data;
//     float distance;
//     float distance;
//     float wall_height;
//     int start_y;
//     int end_y;
///
//     distance = fixed_calculate_distance
//		(data->player->x_pst, data->player->y_pst, ray_x, ray_y, data);
//     wall_height = (BLOCK / distance) * (WIDTH / 2);
//     start_y = (HEIGHT - wall_height) / 2;
//     end_y = start_y + wall_height;
//     while (start_y < end_y)
//     {
//	
//     }
// }

static void	choose_vertical_tex(t_data *data, int i, float ray_x, float ray_y)
{
	if (ray_x < data->player->x_pst)
		data->wall->texture = data->texture->we_texture;
	else
		data->wall->texture = data->texture->ea_texture;
	data->wall->side = VERTICAL;
	draw_textures(data, i, ray_x, ray_y);
}

static void	choose_horizontal_tex(t_data *data, int i, float ray_x, float ray_y)
{
	if (ray_y < data->player->y_pst)
		data->wall->texture = data->texture->no_texture;
	else
		data->wall->texture = data->texture->so_texture;
	data->wall->side = HORIZONTAL;
	draw_textures(data, i, ray_x, ray_y);
}

float	ray_cast(t_data *data, float start_x, int i)
{
	float	cos_angle;
	float	sin_angle;
	float	ray_x;
	float	ray_y;	

	ray_x = data->player->x_pst;
	ray_y = data->player->y_pst;
	sin_angle = sin(start_x);
	cos_angle = cos(start_x);
	while (1)
	{
		ray_x += cos_angle * 0.3;
		if (data->map->matrix[(int)ray_y / BLOCK][(int)ray_x / BLOCK] == '1')
		{
			choose_vertical_tex(data, i, ray_x, ray_y);
			break ;
		}
		ray_y += sin_angle * 0.3;
		if (data->map->matrix[(int)ray_y / BLOCK][(int)ray_x / BLOCK] == '1')
		{
			choose_horizontal_tex(data, i, ray_x, ray_y);
			break ;
		}
	}
	return (0);
}
