/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thopgood <thopgood@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 20:06:19 by mistery576        #+#    #+#             */
/*   Updated: 2025/02/17 14:21:22 by thopgood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	load_textures(t_data *data, t_texture *tx)
{
	int	*tx_w;
	int	*tx_h;

	tx_w = &(tx)->width;
	tx_h = &(tx)->height;
	tx->no_texture = mlx_xpm_file_to_image(data->mlx, tx->no_path, tx_w, tx_h);
	tx->so_texture = mlx_xpm_file_to_image(data->mlx, tx->so_path, tx_w, tx_h);
	tx->we_texture = mlx_xpm_file_to_image(data->mlx, tx->we_path, tx_w, tx_h);
	tx->ea_texture = mlx_xpm_file_to_image(data->mlx, tx->ea_path, tx_w, tx_h);
	if (!data->texture->no_texture || !data->texture->so_texture
		|| !data->texture->we_texture || !data->texture->ea_texture)
		return (print_error("Textures", LOAD_MSG, ENOMEM), -1);
	return (0);
}

static void	initialize_player(t_data *data)
{
	data->player->angle = PI / 2;
	data->player->speed = 2;
	data->player->angle_speed = 0.015;
}

void	initialize_data(t_data *data)
{
	data->map = ft_calloc(1, sizeof(t_map));
	data->texture = ft_calloc(1, sizeof(t_texture));
	data->player = ft_calloc(1, sizeof(t_player));
	data->image = ft_calloc(1, sizeof(t_image));
	data->ray = ft_calloc(1, sizeof(t_ray));
	data->wall = ft_calloc(1, sizeof(t_wall));
	if (!data->texture || !data->map || !data->player || !data->image || !data->wall || !data->ray)
	{
		free(data->map);
		free(data->player);
		free(data->texture);
		free(data->image);
		free(data->wall);
		free(data->ray);
		exit (print_error(NULL, strerror(errno), ENOMEM));
	}
	initialize_player(data);
}

int	create_window(t_data *data)
{
	t_image	*image;

	image = data->image;
	data->mlx = mlx_init();
	if (!data->mlx)
		return (print_error("INIT", strerror(errno), ENOMEM), close_game(data));
	//mlx_get_screen_size // ! might be useful to auto set zoom level
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Cub3D");
	if (!data->win)
		return (print_error("INIT", strerror(errno), ENOMEM), close_game(data));
	image->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!image->img)
		return (print_error("INIT", strerror(errno), ENOMEM), close_game(data));
	image->addr = mlx_get_data_addr(image->img, &image->bits_per_pixel,
			&image->line_length, &image->endian);
	if (load_textures(data, data->texture) < 0)
		return (close_game(data));
	mlx_put_image_to_window(data->mlx, data->win, data->image->img, 0, 0);
	return (0);
}
