/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mistery576 <mistery576@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 20:06:19 by mistery576        #+#    #+#             */
/*   Updated: 2025/01/24 16:56:09 by mistery576       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

static void	initialize_player(t_data *data)
{
	data->player->player = 0;
	data->player->angle = 0.0;
}

static void	initialize_textures(t_data *data)
{
	data->texture->no_texture = NULL;
    data->texture->so_texture = NULL;
    data->texture->we_texture = NULL;
    data->texture->ea_texture = NULL;
    data->texture->f_texture = NULL;
    data->texture->c_texture = NULL;
}

void	initialize_data(t_data *data)
{
	data->map = malloc(sizeof(t_map));
	if (!data->map)
	{
		ft_putstr_fd("Error allocating memory\n", 2);
		exit(127);
	}
	data->texture = malloc(sizeof(t_texture));
	data->player = malloc(sizeof(t_player));
	if (!data->texture)
	{
		ft_putstr_fd("Error allocating memory\n", 2);
		exit(127);
	}
	data->win = NULL;
	data->mlx = NULL;
	data->fov = 60;
	initialize_player(data);
	initialize_textures(data);
}

int	create_window(t_data *data)
{
	(void)data;
	data->mlx = mlx_init();
	//mlx_get_screen_size
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Cub3D");
	return (0);
}