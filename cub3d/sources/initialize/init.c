/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thopgood <thopgood@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 20:06:19 by mistery576        #+#    #+#             */
/*   Updated: 2025/02/12 16:17:11 by thopgood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	load_textures(t_data *data, t_texture *tx)
{
	int	*tx_w;
	int	*tx_h;

	tx_w = &(tx)->width;
	tx_h = &(tx)->height;
	tx->no_texture = mlx_xpm_file_to_image(data->mlx, "tx/CAT.xpm", tx_w, tx_h);
	tx->so_texture = mlx_xpm_file_to_image(data->mlx, "tx/S.xpm", tx_w, tx_h);
	tx->we_texture = mlx_xpm_file_to_image(data->mlx, "tx/WE.xpm", tx_w, tx_h);
	tx->ea_texture = mlx_xpm_file_to_image(data->mlx, "tx/E.xpm", tx_w, tx_h);
	if (!data->texture->no_texture || !data->texture->so_texture
		|| !data->texture->we_texture || !data->texture->ea_texture
		|| !data->texture->f_texture || !data->texture->c_texture)
	{
		ft_putstr_fd("Error loading textures\n", 2);
		return (-1);
	}
	return (0);
}

static void	initialize_player(t_data *data)
{
	data->player->angle = PI / 2;
	data->player->speed = 1;
	data->player->angle_speed = 0.02;
}

void	initialize_data(t_data *data)
{
	data->map = ft_calloc(1, sizeof(t_map));
	data->texture = ft_calloc(1, sizeof(t_texture));
	data->player = ft_calloc(1, sizeof(t_player));
	data->image = ft_calloc(1, sizeof(t_image));
	data->wall = malloc(sizeof(t_wall));
	if (!data->texture || !data->map || !data->player || !data->image)
	{
		free(data->map);
		free(data->player);
		free(data->texture);
		free(data->image);
		free(data);
		exit (print_error(NULL, strerror(errno), ENOMEM));
	}
	data->fov = 60;
	initialize_player(data);
	data->active = 0; // ! change to levels 0, 1, 2, 3
}

int	create_window(t_data *data)
{
	t_image	*image;

	image = data->image;
	data->active = 1;
	data->mlx = mlx_init();
	data->active = 2;
	//mlx_get_screen_size // ! might be useful to auto set zoom level
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Cub3D");
	data->active = 3;
	image->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	image->addr = mlx_get_data_addr(image->img, &image->bits_per_pixel,
			&image->line_length, &image->endian);
	load_textures(data, data->texture);
	mlx_put_image_to_window(data->mlx, data->win, data->image->img, 0, 0);
	return (0);
}
