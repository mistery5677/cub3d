/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mistery576 <mistery576@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:16:32 by mistery576        #+#    #+#             */
/*   Updated: 2025/02/15 23:45:17 by mistery576       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

static int	key_press(int key_pressed, t_data *data)
{
	if (key_pressed == ESC)
		close_game(data);
	if (key_pressed == W)
		data->player->key_up = true;
	if (key_pressed == S)
		data->player->key_down = true;
	if (key_pressed == D)
		data->player->key_right = true;
	if (key_pressed == A)
		data->player->key_left = true;
	if (key_pressed == LEFT)
		data->player->left_rotate = true;
	if (key_pressed == RIGHT)
	{
		data->player->right_rotate = true;
	}
	return (0);
}

static int	key_release(int key_released, t_data *data)
{
	if (key_released == W)
		data->player->key_up = false;
	if (key_released == S)
		data->player->key_down = false;
	if (key_released == D)
		data->player->key_right = false;
	if (key_released == A)
		data->player->key_left = false;
	if (key_released == LEFT)
		data->player->left_rotate = false;
	if (key_released == RIGHT)
	{
		data->player->right_rotate = false;
	}
	return (0);
}

void	gameplay(t_data *data)
{
	mlx_hook(data->win, KeyPress, KeyPressMask, key_press, data);
	mlx_hook(data->win, KeyRelease, KeyReleaseMask, key_release, data);
	mlx_hook(data->win, DestroyNotify, StructureNotifyMask, close_game, data);
	mlx_loop_hook(data->mlx, draw_loop, data);
}
