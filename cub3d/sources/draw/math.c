/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mistery576 <mistery576@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:23:59 by miafonso          #+#    #+#             */
/*   Updated: 2025/02/16 00:51:40 by mistery576       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

void	set_speed(t_player *player, float *speed)
{
	int	moves;

	moves = 0;
	if (player->key_up)
		moves++;
	if (player->key_down)
		moves++;
	if (player->key_right)
		moves++;
	if (player->key_left)
		moves++;
	if (moves != 1)
		*speed = player->speed / 1.5;
	else
		*speed = player->speed;
}

/* Gets the column of the texture that we want to print */
int	verify_side(t_data *data, float ray_x, float ray_y)
{
	float	wall_x;
	int		tex_x;

	tex_x = 0;
	if (data->wall->side == VERTICAL)
		wall_x = ray_y;
	else
		wall_x = ray_x;
	wall_x /= BLOCK;
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * (float)64);
	if ((data->wall->side == VERTICAL && ray_x < data->player->x_pst)
		|| (data->wall->side == HORIZONTAL && ray_y > data->player->y_pst))
		tex_x = 64 - tex_x - 1;
	if (tex_x < 0)
		tex_x = 0;
	if (tex_x >= 64)
		tex_x = 64 - 1;
	return (tex_x);
}

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

/** DICTIONARY
 * wall_x --> Collumn of the wall that got hit
 * wall_x /= BLOCK --> Change to wall size;
 * wall_x -= floor(wall_x) --> Returns the integer, for example (10.74 = 10)
 * tex_x --> Gets the texture column
 * DICTIONARY*/