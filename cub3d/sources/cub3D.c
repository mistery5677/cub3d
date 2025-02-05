/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miafonso <miafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:40:27 by miafonso          #+#    #+#             */
/*   Updated: 2025/02/10 14:40:59 by miafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
	{
		ft_putstr_fd("Error allocating memory\n", 2);
		exit(127);
	}
	initialize_data(data);
	if (check_map(data, argc, argv) == -1)
	{
		close_game(data);
		return (-1);
	}
	if (DEBUG == 1)
	{
		create_window(data);
		gameplay(data);
		debug_window(data);
	}
	else
	{
		create_window(data);
		gameplay(data);
		mlx_loop(data->mlx);
	}
}
