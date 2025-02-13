/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miafonso <miafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:32:48 by miafonso          #+#    #+#             */
/*   Updated: 2025/02/13 16:10:28 by miafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub.h"

static void	choose_vertical_tex(t_data *data, int i, float ray_x, float ray_y)
{
	if (ray_x < data->player->x_pst)
		data->wall->texture = data->texture->we_texture;
	else
		data->wall->texture = data->texture->ea_texture;
	data->wall->side = VERTICAL;
	draw_textures(data, i, ray_x, ray_y);
}

static void	choose_horizontal_tex(t_data *data, int i, float ray_x, float ray_y)
{
	if (ray_y < data->player->y_pst)
		data->wall->texture = data->texture->no_texture;
	else
		data->wall->texture = data->texture->so_texture;
	data->wall->side = HORIZONTAL;
	draw_textures(data, i, ray_x, ray_y);
}


static void	init_ray(t_ray *ray, float start_x)
{
	ray->cos_angle = cos(start_x);
	ray->sin_angle = sin(start_x);
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
		ray->side_dist_x = (player->x_pst - map_x) *ray->delta_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (map_x + 1.0 - player->x_pst) *ray->delta_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (player->y_pst - map_y) *ray->delta_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (map_y + 1.0 - player->y_pst) *ray->delta_y;
	}
	
}

float dda_algorithm(t_data *data, t_ray *ray, float start_x, int i)
{
    int map_x;
    int map_y;
    int side; // 0 = vertical, 1 = horizontal
	
	map_x = (int)data->player->x_pst;
	map_y = (int)data->player->y_pst;
	init_ray(ray, start_x);
    init_dir_dist(ray, data->player, map_x, map_y);
	
	// Step direction and initial side distance

    // DDA algorithm

    while (data->map->matrix[map_y / BLOCK][map_x / BLOCK] != '1')
    {
        if (ray->side_dist_x < ray->side_dist_y)
        {
            ray->side_dist_x += ray->delta_x;
            map_x += ray->step_x;
            side = VERTICAL;
        }
        else
        {
            ray->side_dist_y += ray->delta_y;
            map_y += ray->step_y;
            side = HORIZONTAL;
        }
    }

    // Calculate distance to the wall
    // float perp_wall_dist;
    // if (side == 0)
        // perp_wall_dist = (map_x - data->player->x_pst + (1 - step_x) / 2) / ray_dir_x;
    // else
        // perp_wall_dist = (map_y - data->player->y_pst + (1 - step_y) / 2) / ray_dir_y;

    // Choose texture based on side
    if (side == VERTICAL)
        choose_vertical_tex(data, i, map_x, map_y);
    else
        choose_horizontal_tex(data, i, map_x, map_y);

    return 0; 
}

/** DICTIONARY
 * Delta_x and delta_y are the lenght of ray from 
 * 		one x or y-side to next x or y-side
 * 
 * 
 */

// float ray_cast(t_data *data, float start_x, int i)
// {
//     float cos_angle = cos(start_x);
//     float sin_angle = sin(start_x);

//     // Ray direction
//     float ray_dir_x = cos_angle;
//     float ray_dir_y = sin_angle;

//     // Map position
//     int map_x = (int)data->player->x_pst;
//     int map_y = (int)data->player->y_pst;

//     // Length of ray from one x or y-side to next x or y-side
//     float delta_dist_x = fabs(1 / ray_dir_x);
//     float delta_dist_y = fabs(1 / ray_dir_y);

//     // Step direction and initial side distance
//     int step_x, step_y;
//     float side_dist_x, side_dist_y;

//     if (ray_dir_x < 0)
//     {
//         step_x = -1;
//         side_dist_x = (data->player->x_pst - map_x) * delta_dist_x;
//     }
//     else
//     {
//         step_x = 1;
//         side_dist_x = (map_x + 1.0 - data->player->x_pst) * delta_dist_x;
//     }

//     if (ray_dir_y < 0)
//     {
//         step_y = -1;
//         side_dist_y = (data->player->y_pst - map_y) * delta_dist_y;
//     }
//     else
//     {
//         step_y = 1;
//         side_dist_y = (map_y + 1.0 - data->player->y_pst) * delta_dist_y;
//     }

//     // DDA algorithm
//     int hit = 0;
//     int side; // 0 = vertical, 1 = horizontal

//     while (!hit)
//     {
//         if (side_dist_x < side_dist_y)
//         {
//             side_dist_x += delta_dist_x;
//             map_x += step_x;
//             side = 0;
//         }
//         else
//         {
//             side_dist_y += delta_dist_y;
//             map_y += step_y;
//             side = 1;
//         }

//         // Check if ray hits a wall
//         if (data->map->matrix[map_y][map_x] == '1')
//             hit = 1;
//     }

//     // Calculate distance to the wall
//     float perp_wall_dist;
//     if (side == 0)
//         perp_wall_dist = (map_x - data->player->x_pst + (1 - step_x) / 2) / ray_dir_x;
//     else
//         perp_wall_dist = (map_y - data->player->y_pst + (1 - step_y) / 2) / ray_dir_y;

//     // Choose texture based on side
//     if (side == 0)
//         choose_vertical_tex(data, i, map_x, map_y);
//     else
//         choose_horizontal_tex(data, i, map_x, map_y);

//     return perp_wall_dist;
// }