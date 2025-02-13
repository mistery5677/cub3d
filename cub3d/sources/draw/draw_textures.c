/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mistery576 <mistery576@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:05:03 by miafonso          #+#    #+#             */
/*   Updated: 2025/02/15 19:45:54 by mistery576       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

static int	get_pixel_color(t_data *data, char *image, int x, int y)
{
	return (*(int *)(image + (y * data->texture->size_line
			+ x * (data->texture->bpp / 8))));
}

static void	draw_floor_ceiling(t_data *data, int i, int start_y, int end_y)
{
	int	y;

	y = 0;
	while (y < start_y)
	{
		put_pixel(i, y, data->texture->c_texture, data);
		y++;
	}
	y = end_y;
	while (y < HEIGHT)
	{
		put_pixel(i, y, data->texture->f_texture, data);
		y++;
	}
}

// static void process_math()

// static void	draw_walls(t_data *dt, t_texture *tx, int i, int tex_x)
// {
// 	float	step;
// 	float	tex_pos;
// 	int		converter_base;
// 	int		tex_scale;
// 	int		tex_y;

// 	tex_scale = (64 * 256) / dt->wall->height;
// 	step = 64.0f / dt->wall->height;
// 	tex_pos = (dt->wall->start_y - (HEIGHT / 2)
// 			+ (dt->wall->height / 2)) * step;
// 	converter_base = -HEIGHT * 128 + dt->wall->height * 128;
// 	tx->img = mlx_get_data_addr(dt->wall->texture,
// 			&(tx)->bpp, &(tx)->size_line, &(tx)->endian);
// 	while (dt->wall->start_y < dt->wall->end_y)
// 	{
// 		tex_y = ((dt->wall->start_y * 256 + converter_base) * tex_scale) / 256;
// 		if (tex_y < 0)
// 			tex_y = 0;
// 		tex_y = (int)tex_pos & 63;
// 		tx->color = get_pixel_color(dt, tx->img, tex_x, tex_y);
// 		put_pixel(i, dt->wall->start_y, tx->color, dt);
// 		tex_pos += step;
// 		dt->wall->start_y++;
// 	}
// }

static void	draw_walls(t_data *dt, t_texture *tx, int i, int tex_x)
{
	float	step;
	float	tex_pos;
	int		tex_y;
	int		y;

	step = (float)BLOCK / dt->wall->height;
	if (dt->wall->start_y < 0)
		tex_pos = -dt->wall->start_y * step;
	else
		tex_pos = 0;
	tx->img = mlx_get_data_addr(dt->wall->texture,
			&(tx)->bpp, &(tx)->size_line, &(tx)->endian);
	if (dt->wall->start_y < 0)
		y = 0;
	else
		y = dt->wall->start_y;
	while (y < dt->wall->end_y && y < HEIGHT)
	{
		tex_y = ((int)tex_pos) % BLOCK;
		tx->color = get_pixel_color(dt, tx->img, tex_x, tex_y);
		put_pixel(i, y, tx->color, dt);
		tex_pos += step;
		y++;
	}
}

void	draw_textures(t_data *data, int i, float ray_x, float ray_y)
{
	int	tex_x;

	data->wall->distance = fixed_calculate_distance(ray_x, ray_y, data);
	data->wall->height = (BLOCK * HEIGHT)
		/ (data->wall->distance * tan(FOV / 2));
	data->wall->start_y = (HEIGHT - data->wall->height) / 2;
	data->wall->end_y = data->wall->start_y + data->wall->height;
	tex_x = verify_side(data, ray_x, ray_y);
	draw_floor_ceiling(data, i, data->wall->start_y, data->wall->end_y);
	draw_walls(data, data->texture, i, tex_x);
}

/** DICTIONARY
 * 
 * WALLX --> Where the ray hit
 * SIDE --> Verify if the
 * perpWallDist --> Distance from player to the wall
 * get_pixel_color() --> Returns the expecific pixel texture
 * converter = data->wall->start_y * 256 - 
 * 			HEIGHT * 128 + data->wall->height * 128;
 *  --> adjusts the pixel position on the screen to a 
 * 		proportional value within the wall. We multiply by
 * 		256 and 128 to prevent some errors when we try to convert
 * 		a fractional number.
 * tex_y --> Convets to wall texture coordenates
 * tex_y = (int)tex_pos & 63; --> Keeps tex_y within the range [0, 63]
 * */
