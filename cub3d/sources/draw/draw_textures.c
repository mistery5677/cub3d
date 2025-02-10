/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miafonso <miafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:05:03 by miafonso          #+#    #+#             */
/*   Updated: 2025/02/10 16:35:43 by miafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

static int	get_pixel_color(void *texture, int x, int y)
{
	char	*data;
	int		bpp;
	int		size_line;
	int		endian;

	data = mlx_get_data_addr(texture, &bpp, &size_line, &endian);
	return (*(int *)(data + (y * size_line + x * (bpp / 8))));
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

// static void draw_walls(t_data)

void	draw_textures(t_data *data, int i, float ray_x, float ray_y)
{
	int start_y;
	int end_y;
	int tex_x;
	
	data->wall->distance = fixed_calculate_distance(ray_x, ray_y, data);
	data->wall->height = (BLOCK / data->wall->distance) * (WIDTH / 2);
	start_y = (HEIGHT - data->wall->height) / 2;
	end_y = start_y + data->wall->height;
	tex_x = verify_side(data, ray_x, ray_y);
	draw_floor_ceiling(data, i, start_y, end_y);
	// draw_walls(data, start_y, end_y)
	// Calculate the exact x-coordinate on the texture
	while (start_y < end_y)
	{
		int d = start_y * 256 - HEIGHT * 128 + data->wall->height * 128;
		int texY = ((d * 64) / data->wall->height) / 256;
		if (texY < 0) texY = 0;
		if (texY >= 64) texY = 64 - 1;

		int color = get_pixel_color(data->wall->texture, tex_x, texY);
		put_pixel(i, start_y, color, data);
		start_y++;
	}
	
}


/** DICTIONARY
 * 
 * WALLX --> Where the ray hit
 * SIDE --> Verify if the
 * perpWallDist --> Distance from player to the wall
 * get_pixel_color() --> Returns the expecific pixel texture
 * */
