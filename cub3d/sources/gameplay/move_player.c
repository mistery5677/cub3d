/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mistery576 <mistery576@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 19:50:08 by mistery576        #+#    #+#             */
/*   Updated: 2025/01/26 20:03:25 by mistery576       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

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
        data->player->x_pst += cos_angle *speed;
        data->player->y_pst += sin_angle *speed;
    }
    if (data->player->key_down)
    {
        data->player->x_pst -= cos_angle *speed;
        data->player->y_pst -= sin_angle *speed;
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
	move_player_camera(data, cos_angle, sin_angle);
}
