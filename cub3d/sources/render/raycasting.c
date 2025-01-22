/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mistery576 <mistery576@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:03:05 by mistery576        #+#    #+#             */
/*   Updated: 2025/01/22 22:40:54 by mistery576       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

static bool is_wall(t_data *data, int x, int y)
{
	return (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT && data->map->matrix[y][x] == 1);
}
static void draw_pixel (t_data *data, )


float ray_cast(t_data *data, float angle)
{
	float	sin_a;
	float	cos_a;
	float	distance;
	float	ray_x;
	float	ray_y;
	
	distance = 0.0;
	sin_a = sin(angle);
	cos_a = cos(angle);
	while (distance < 20.0)
	{
		ray_x = data->player->x_pst + cos_a * distance;
		ray_x = data->player->y_pst + sin_a * distance;
		if (is_wall(data, (int)ray_x, (int)ray_y))
			return distance;
		distance += 0.01;
	}
	return distance;
}