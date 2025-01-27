/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mistery576 <mistery576@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:03:05 by mistery576        #+#    #+#             */
/*   Updated: 2025/01/27 00:15:53 by mistery576       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

static bool is_wall(t_data *data, int px, int py)
{
	int x;
    int y;

    y = py / BLOCK;
    x = px / BLOCK;
    if (data->map->matrix[y][x] == '1')
        return true;
    return false;
}

float calculate_distance(float x, float y) // This fucntion has the fish eye
{
    return sqrt(x * x + y * y);
}

float fixed_calculate_distance(float x1, float y1, float x2, float y2, t_data *data) // Fix the fish eye
{
    float delta_x;
    float delta_y;
    float angle;
    float fix_distance;

    delta_x = x2 - x1;
    delta_y = y2 - y1;
    angle = atan2(delta_y, delta_x) - data->player->angle;
    fix_distance = calculate_distance(delta_x, delta_y) * cos(angle);
    return fix_distance;
}

static void draw_walls(t_data *data, int i, float ray_x, float ray_y)
{
	float distance;
	float wall_height;
	int start_y;
	int end;

	distance = fixed_calculate_distance(data->player->x_pst, data->player->y_pst, ray_x, ray_y, data);
	wall_height = (BLOCK / distance) * (WIDTH / 2);
	start_y = (HEIGHT - wall_height) / 2;
	end = start_y + wall_height;
	while (start_y < end)
	{
		put_pixel(i, start_y, 0x00FF00, data);
		start_y++;
	}
}

float ray_cast(t_data *data, float start_x, int i)
{
	float	cos_angle;
	float	sin_angle;
	float	ray_x;
	float	ray_y;
	
	ray_x = data->player->x_pst;
    ray_y = data->player->y_pst;
    sin_angle = sin(start_x);
    cos_angle = cos(start_x);
    while (!is_wall(data, ray_x, ray_y))
    {
        ray_x += cos_angle;
        ray_y += sin_angle; 
    }
	draw_walls(data, i, ray_x, ray_y);
	return 0;
}
