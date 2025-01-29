/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mistery576 <mistery576@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 19:50:08 by mistery576        #+#    #+#             */
/*   Updated: 2025/01/27 19:27:27 by mistery576       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

static bool check_wall(t_data *data, float cos_angle, float sin_angle)
{
    float x;
    float y;
    
    x = data->player->x_pst;
    y = data->player->y_pst;
    if (data->player->key_up)
    {
        x += (cos_angle * data->player->speed);
        y += (sin_angle * data->player->speed);
    }
    if (data->player->key_down)
    {
        x -= (cos_angle * data->player->speed);
        y -= (sin_angle * data->player->speed);
    }
    if (data->player->key_left)
    {
        x += (sin_angle * data->player->speed);
        y -= (cos_angle * data->player->speed);
    }
    if (data->player->key_right)
    {
        x -= (sin_angle * data->player->speed);
        y += (cos_angle * data->player->speed);
    }
    if (data->map->matrix[(int)(y / BLOCK)][(int)(x / BLOCK)] == WALL)
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

static void move_player_camera(t_data *data, float cos_angle, float sin_angle)
{
	float speed;

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
    if (!check_wall(data, cos_angle, sin_angle))
        move_player_camera(data, cos_angle, sin_angle);
}
