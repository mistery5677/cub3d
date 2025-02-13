/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mistery576 <mistery576@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 19:50:08 by mistery576        #+#    #+#             */
/*   Updated: 2025/02/16 16:33:34 by mistery576       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

static bool	check_player_size(t_data *data, int new_x, int new_y)
{
	int	bottom;
	int	right;
	int	left;
	int	top;

	left = (int)((new_x - PLAYER_SIZE) / BLOCK);
	right = (int)((new_x + PLAYER_SIZE) / BLOCK);
	top = (int)((new_y - PLAYER_SIZE) / BLOCK);
	bottom = (int)((new_y + PLAYER_SIZE) / BLOCK);
	if (data->map->matrix[top][left] == WALL
		|| data->map->matrix[top][right] == WALL
		|| data->map->matrix[bottom][left] == WALL
		|| data->map->matrix[bottom][right] == WALL)
		return (true);
	return (false);
}

static bool	check_wall(t_data *data, t_player player,
	float cos_angle, float sin_angle)
{
	if (data->player->key_up)
	{
		player.x_pst += (cos_angle * data->player->speed);
		player.y_pst += (sin_angle * data->player->speed);
	}
	if (data->player->key_down)
	{
		player.x_pst -= (cos_angle * data->player->speed);
		player.y_pst -= (sin_angle * data->player->speed);
	}
	if (data->player->key_left)
	{
		player.x_pst += (sin_angle * data->player->speed);
		player.y_pst -= (cos_angle * data->player->speed);
	}
	if (data->player->key_right)
	{
		player.x_pst -= (sin_angle * data->player->speed);
		player.y_pst += (cos_angle * data->player->speed);
	}
	if (check_player_size(data, player.x_pst, player.y_pst) == true)
		return (true);
	return (false);
}

/** We have to reset the angles, when we 
 * exceed the "limit" (0° - 360°)
*/
static void	turn_player_camera(t_data *data)
{
	if (data->player->left_rotate == true)
		data->player->angle -= data->player->angle_speed;
	if (data->player->right_rotate == true)
		data->player->angle += data->player->angle_speed;
	if (data->player->angle > 2 * PI)
		data->player->angle -= 2 * PI;
	if (data->player->angle < 0)
		data->player->angle += 2 * PI;
}

/** To move in our game, we use angles to know
 * where is the player, instead using the
 * map coordinates as X and y. Because in a
 * 3D game, you can look around you, and the
 * player coordenates depends on the way you
 * are looking.
*/
static void	move_player_camera(t_data *data, float cos_angle, float sin_angle)
{
	float	speed;

	set_speed(data->player, &speed);
	if (data->player->key_up)
	{
		data->player->x_pst += cos_angle * speed;
		data->player->y_pst += sin_angle * speed;
	}
	if (data->player->key_down)
	{
		data->player->x_pst -= cos_angle * speed;
		data->player->y_pst -= sin_angle * speed;
	}
	if (data->player->key_left)
	{
		data->player->x_pst += sin_angle * speed;
		data->player->y_pst -= cos_angle * speed;
	}
	if (data->player->key_right)
	{
		data->player->x_pst -= sin_angle * speed;
		data->player->y_pst += cos_angle * speed;
	}
}

void	move_player(t_data *data)
{
	float	cos_angle;
	float	sin_angle;

	cos_angle = cos(data->player->angle);
	sin_angle = sin(data->player->angle);
	turn_player_camera(data);
	if (!check_wall(data, *(data)->player, cos_angle, sin_angle))
		move_player_camera(data, cos_angle, sin_angle);
}
