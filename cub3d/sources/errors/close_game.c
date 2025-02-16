/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mistery576 <mistery576@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 12:46:23 by mistery576        #+#    #+#             */
/*   Updated: 2025/02/15 19:46:13 by mistery576       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h" // ! can change to cub.h

static void	free_map(t_data *data)
{
	int	i;

	i = 0;
	while (data->map->matrix && data->map->matrix[i])
	{
		free(data->map->matrix[i]);
		i++;
	}
	free(data->map->matrix);
	free(data->map);
}

static void	free_textures(t_data *data)
{
	if (data->texture->no_texture)
		mlx_destroy_image(data->mlx, data->texture->no_texture);
	if (data->texture->ea_texture)
		mlx_destroy_image(data->mlx, data->texture->ea_texture);
	if (data->texture->so_texture)
		mlx_destroy_image(data->mlx, data->texture->so_texture);
	if (data->texture->we_texture)
		mlx_destroy_image(data->mlx, data->texture->we_texture);
	free(data->texture);
}

static void	free_paths(t_data *data)
{
	if (data->texture->no_path)
		free(data->texture->no_path);
	if (data->texture->ea_path)
		free(data->texture->ea_path);
	if (data->texture->so_path)
		free(data->texture->so_path);
	if (data->texture->we_path)
		free(data->texture->we_path);
}

int	close_game(t_data *data)
{
	free_map(data);
	free_paths(data);
	if (data->texture)
		free_textures(data);
	if (data->image->img)
		mlx_destroy_image(data->mlx, data->image->img);
	if (data->mlx && data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
		mlx_destroy_display(data->mlx);
	free(data->player->look);
	free(data->player);
	free(data->image);
	free(data->mlx);
	free(data->wall);
	free(data->ray);
	exit(0);
}
