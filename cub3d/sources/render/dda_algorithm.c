/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mistery576 <mistery576@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:32:48 by miafonso          #+#    #+#             */
/*   Updated: 2025/02/15 19:59:31 by mistery576       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	choose_wall_tex(t_data *data, int i, float ray_x, float ray_y)
{
	if (data->wall->side == VERTICAL)
	{
		if (ray_x < data->player->x_pst)
			data->wall->texture = data->texture->we_texture;
		else
			data->wall->texture = data->texture->ea_texture;
	}
	else
	{
		if (ray_y < data->player->y_pst)
			data->wall->texture = data->texture->no_texture;
		else
			data->wall->texture = data->texture->so_texture;
	}
	draw_textures(data, i, ray_x, ray_y);
}

static void	init_ray(t_ray *ray, t_player *player, int i)
{
	float	camera_x;
	float	ray_angle;

	camera_x = (2.0f * i / WIDTH) - 1.0f;
	ray_angle = player->angle + atan(camera_x * tan(FOV / 2));
	ray->cos_angle = cos(ray_angle);
	ray->sin_angle = sin(ray_angle);
	ray->ray_dir_x = ray->cos_angle;
	ray->ray_dir_y = ray->sin_angle;
	ray->delta_x = fabs(1 / ray->ray_dir_x);
	ray->delta_y = fabs(1 / ray->ray_dir_y);
}

/** Step direction and initial side distance */
static void	init_dir_dist(t_ray *ray, t_player *player, int map_x, int map_y)
{
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (player->x_pst - map_x) * ray->delta_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (map_x + 1.0 - player->x_pst) * ray->delta_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (player->y_pst - map_y) * ray->delta_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (map_y + 1.0 - player->y_pst) * ray->delta_y;
	}
}

float	dda_algorithm(t_data *data, t_ray *ray, int i)
{
	int	map_x;
	int	map_y;

	map_x = (int)data->player->x_pst;
	map_y = (int)data->player->y_pst;
	init_ray(ray, data->player, i);
	init_dir_dist(ray, data->player, map_x, map_y);
	while (data->map->matrix[map_y / BLOCK][map_x / BLOCK] != '1')
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_x;
			map_x += ray->step_x;
			data->wall->side = VERTICAL;
		}
		else
		{
			ray->side_dist_y += ray->delta_y;
			map_y += ray->step_y;
			data->wall->side = HORIZONTAL;
		}
	}
	choose_wall_tex(data, i, map_x, map_y);
	return (0);
}

/** DICTIONARY
 * Delta_x and delta_y are the lenght of ray from
 * 		one x or y-side to next x or y-side
 *
 *
 */