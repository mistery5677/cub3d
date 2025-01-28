/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mistery576 <mistery576@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:03:05 by mistery576        #+#    #+#             */
/*   Updated: 2025/01/28 00:02:22 by mistery576       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

static bool is_wall(t_data *data, int px, int py)
{
	int x;
    int y;

    y = py / BLOCK;
    x = px / BLOCK;
    if (data->map->matrix[y][x] == '1')
        return true;
    return false;
}

float calculate_distance(float x, float y) // This fucntion has the fish eye
{
    return sqrt(x * x + y * y);
}

float fixed_calculate_distance(float x1, float y1, float x2, float y2, t_data *data) // Fix the fish eye
{
    float delta_x;
    float delta_y;
    float angle;
    float fix_distance;

    delta_x = x2 - x1;
    delta_y = y2 - y1;
    angle = atan2(delta_y, delta_x) - data->player->angle;
    fix_distance = calculate_distance(delta_x, delta_y) * cos(angle);
    return fix_distance;
}

void paint_green(t_data *data, float start_y, int i)
{
    int index;
    
    index = start_y * data->image->line_length + i * (data->image->bits_per_pixel / 8);
    data->image->addr[index] = 0x00;
    data->image->addr[index + 1] = 0xFF;
    data->image->addr[index + 2] = 0x00;
}

void paint_blue(t_data *data, float start_y, int i)
{
    int index;
    
    index = start_y * data->image->line_length + i * (data->image->bits_per_pixel / 8);
    data->image->addr[index] = 0xFF;
    data->image->addr[index + 1] = 0x00;
    data->image->addr[index + 2] = 0x00;
}

static void draw_walls(t_data *data, int i, float ray_x, float ray_y)
{
    float distance;
    float wall_height;
    int start_y;
    int end_y;
    int y;
    //int index;
    
    y = 0;
    distance = fixed_calculate_distance(data->player->x_pst, data->player->y_pst, ray_x, ray_y, data);
    wall_height = (BLOCK / distance) * (WIDTH / 2);
    start_y = (HEIGHT - wall_height) / 2;
    end_y = start_y + wall_height;

    if (start_y < 0) start_y = 0; // Garantir que não ultrapasse o topo da tela
    if (end_y >= HEIGHT) end_y = HEIGHT - 1; // Garantir que não ultrapasse o fundo da tela
    while (y < start_y)
    {
        paint_blue(data, y, i);
        y++;
    }
    while (start_y < end_y)
    {
        paint_green(data, start_y, i);
        start_y++;
    }
    while (end_y < HEIGHT)
    {
        paint_blue(data, end_y, i);
        end_y++;
    }
}


float ray_cast(t_data *data, float start_x, int i)
{
	float	cos_angle;
	float	sin_angle;
	float	ray_x;
	float	ray_y;
	
	ray_x = data->player->x_pst;
    ray_y = data->player->y_pst;
    sin_angle = sin(start_x);
    cos_angle = cos(start_x);
    while (!is_wall(data, ray_x, ray_y))
    {
        ray_x += cos_angle;
        ray_y += sin_angle; 
    }
	draw_walls(data, i, ray_x, ray_y);
	return 0;
}

//  DDA ALGORITHM
// float ray_cast(t_data *data, float start_x, int i)
// {
//     float cos_angle = cos(start_x);
//     float sin_angle = sin(start_x);
//     float delta_dist_x, delta_dist_y;
//     float side_dist_x, side_dist_y;
//     int map_x, map_y;
//     int step_x, step_y;

//     // Posição inicial do raio
//     float ray_x = data->player->x_pst;
//     float ray_y = data->player->y_pst;

//     // Cálculo da posição inicial no grid
//     map_x = (int)(ray_x / BLOCK);
//     map_y = (int)(ray_y / BLOCK);

//     // Distância até as próximas bordas
//     delta_dist_x = fabs(1 / cos_angle);
//     delta_dist_y = fabs(1 / sin_angle);

//     // Determina o passo (direção do incremento)
//     if (cos_angle < 0)
//     {
//         step_x = -1;
//         side_dist_x = (ray_x - map_x * BLOCK) * delta_dist_x;
//     }
//     else
//     {
//         step_x = 1;
//         side_dist_x = ((map_x + 1) * BLOCK - ray_x) * delta_dist_x;
//     }
//     if (sin_angle < 0)
//     {
//         step_y = -1;
//         side_dist_y = (ray_y - map_y * BLOCK) * delta_dist_y;
//     }
//     else
//     {
//         step_y = 1;
//         side_dist_y = ((map_y + 1) * BLOCK - ray_y) * delta_dist_y;
//     }

//     // Itera através do mapa até encontrar uma parede
//     while (data->map->matrix[map_y][map_x] != '1')
//     {
//         if (side_dist_x < side_dist_y)
//         {
//             side_dist_x += delta_dist_x;
//             map_x += step_x;
//         }
//         else
//         {
//             side_dist_y += delta_dist_y;
//             map_y += step_y;
//         }
//     }

//     // Calcula a posição do ponto de interseção
//     ray_x += cos_angle * (side_dist_x < side_dist_y ? side_dist_x : side_dist_y);
//     ray_y += sin_angle * (side_dist_x < side_dist_y ? side_dist_x : side_dist_y);

//     draw_walls(data, i, ray_x, ray_y);
//     return 0;
// }
