/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thopgood <thopgood@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:49:07 by thopgood          #+#    #+#             */
/*   Updated: 2025/02/14 15:47:05 by thopgood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	main(int argc, char **argv)
{
	static t_data	data;

	initialize_data(&data);
	if (!is_map_valid(&data, argc, argv))
		return (close_game(&data), EXIT_FAILURE);
	if (DEBUG == 1)
	{
		create_window(&data);
		gameplay(&data);
		debug_window(&data);
	}
	else
	{
		create_window(&data);
		gameplay(&data);
		mlx_loop(data.mlx);
	}

	// * Would this make more sense?
	// create_window(&data);
	// gameplay(&data);
	// if (DEBUG == 1)
	// 	debug_window(&data);
	// else
	// 	mlx_loop(data.mlx);

	return (0);
}
