/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mistery576 <mistery576@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:05:03 by miafonso          #+#    #+#             */
/*   Updated: 2025/02/11 19:51:33 by mistery576       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

static int	get_pixel_color(t_data *data, char *image, int x, int y)
{
	return (*(int *)(image + (y * data->texture->size_line + x * (data->texture->bpp / 8))));
}

static void	draw_floor_ceiling(t_data *data, int i, int start_y, int end_y)
{
	int	y;

	y = 0;
	data->texture->color = BLUE;
	while (y < start_y)
	{
		put_pixel(i, y, data->texture->color, data);
		y++;
	}
	y = end_y;
	data->texture->color = 0xFF0000;
	while (y < HEIGHT)
	{
		put_pixel(i, y, data->texture->color, data);
		y++;
	}
}

static void	draw_walls(t_data *data, int i, int tex_x)
{
	int	converter;
	int	tex_y;
	int	color;
	char *image;

	image = mlx_get_data_addr(data->wall->texture, &(data)->texture->bpp, &(data)->texture->size_line, &(data)->texture->endian);
	while (data->wall->start_y < data->wall->end_y)
	{
		converter = data->wall->start_y * 256
		- HEIGHT * 128 + data->wall->height * 128;
		tex_y = ((converter * 64) / data->wall->height) / 256;
		if (tex_y < 0)
			tex_y = 0;
		if (tex_y >= 64)
			tex_y = 64 - 1;
		color = get_pixel_color(data, image, tex_x, tex_y);
		put_pixel(i, data->wall->start_y, color, data);
		data->wall->start_y++;
	}
}

void	draw_textures(t_data *data, int i, float ray_x, float ray_y)
{
	int	tex_x;

	(void)i;
	(void)tex_x;
	data->wall->distance = fixed_calculate_distance(ray_x, ray_y, data);
	data->wall->height = (BLOCK / data->wall->distance) * (WIDTH / 2);
	data->wall->start_y = (HEIGHT - data->wall->height) / 2;
	data->wall->end_y = data->wall->start_y + data->wall->height;
	tex_x = verify_side(data, ray_x, ray_y);
	draw_floor_ceiling(data, i, data->wall->start_y, data->wall->end_y);
	draw_walls(data, i, tex_x);
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
 * */
