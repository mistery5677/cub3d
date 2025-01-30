/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miafonso <miafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 19:50:08 by mistery576        #+#    #+#             */
/*   Updated: 2025/01/30 15:06:30 by miafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

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
	if (data->map->matrix[(int)(player.y_pst / BLOCK)]
			[(int)(player.x_pst / BLOCK)] == WALL)
		return (true);
	return (false);
}

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

static void	move_player_camera(t_data *data, float cos_angle, float sin_angle)
{
	float	speed;

	speed = data->player->speed;
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
