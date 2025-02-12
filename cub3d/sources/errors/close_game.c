/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thopgood <thopgood@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 12:46:23 by mistery576        #+#    #+#             */
/*   Updated: 2025/02/12 13:38:10 by thopgood         ###   ########.fr       */
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
	free(data->texture);
}

int	close_game(t_data *data)
{
	free_texture(data);
	free_map(data);
	if (data->active >= 3  && data->image)
		mlx_destroy_image(data->mlx, data->image->img);
	if (data->active >= 2 && data->mlx)
		mlx_destroy_window(data->mlx, data->win);
	if (data->active >= 1 && data->win)
		mlx_destroy_display(data->mlx);
	free(data->player->look);
	free(data->player);
	free(data->image);
	free(data->mlx);
	free(data->wall);
	// free(data); // ! static local variable
	exit(0);
}
