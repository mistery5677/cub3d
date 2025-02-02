/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thopgood <thopgood@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 12:46:23 by mistery576        #+#    #+#             */
/*   Updated: 2025/02/10 12:36:48 by thopgood         ###   ########.fr       */
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

static void	free_texture(t_data *data)
{
	if (data->active)
	{
		printf("IS FREEING\n");
		free(data->texture->no_texture);
		free(data->texture->ea_texture);
		free(data->texture->we_texture);
		free(data->texture->so_texture);
	}
	// free(data->texture->c_texture);  // ! not mallocd
	// free(data->texture->f_texture);	// ! 
	free(data->texture);
}

int	close_game(t_data *data)
{
	free_texture(data);
	free_map(data);
	if (data->active && data->image)
		mlx_destroy_image(data->mlx, data->image->img);
	if (data->active && data->mlx)
		mlx_destroy_window(data->mlx, data->win);
	if (data->active && data->win)
		mlx_destroy_display(data->mlx);
	free(data->player->look);
	free(data->player);
	free(data->image);
	free(data->mlx);
	// free(data->active);
	free(data);
	exit(0);
}
