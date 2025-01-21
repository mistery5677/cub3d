/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mistery576 <mistery576@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 12:46:23 by mistery576        #+#    #+#             */
/*   Updated: 2025/01/21 16:10:16 by mistery576       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

static void	free_map(t_data *data)
{
	int i;

	i = 0;
	while (data->map->matrix[i])
	{
		free(data->map->matrix[i]);
		i++;
	}
	free(data->map->matrix);
	free(data->map);
}

static void	free_texture(t_data *data)
{
	free(data->texture->no_texture);
	free(data->texture->ea_texture);
	free(data->texture->we_texture);
	free(data->texture->so_texture);
	free(data->texture->c_texture);
	free(data->texture->f_texture);
	free(data->texture);
}

void	free_all(t_data *data)
{
	free_texture(data);
	free_map(data);
	//mlx_destroy_window(data->mlx, data->win);
	//mlx_destroy_display(data->mlx);
	free(data);
}