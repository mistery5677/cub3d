/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mistery576 <mistery576@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 20:06:19 by mistery576        #+#    #+#             */
/*   Updated: 2025/01/21 16:05:35 by mistery576       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

int	create_window(t_data *data)
{
	(void)data;
	data->mlx = mlx_init();
	//mlx_get_screen_size
	data->win = mlx_new_window(data->mlx, 1000, 1000, "Cub3D");
	return (0);
}