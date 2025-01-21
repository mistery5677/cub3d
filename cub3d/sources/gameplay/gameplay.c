/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mistery576 <mistery576@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:16:32 by mistery576        #+#    #+#             */
/*   Updated: 2025/01/21 17:16:22 by mistery576       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

static int	key_press(int key_pressed, t_data *data)
{
	(void) data;
	printf("key_pressed %d\n", key_pressed);
	return (0);
}

void gameplay(t_data *data)
{
	(void)data;
	mlx_hook(data->win, KeyPress, KeyPressMask, key_press, data);
}