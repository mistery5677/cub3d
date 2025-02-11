/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mistery576 <mistery576@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 18:23:18 by mistery576        #+#    #+#             */
/*   Updated: 2025/02/11 00:10:06 by mistery576       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

void	put_pixel(int x, int y, int color, t_data *data)
{
	int	index;

	if (!data->image || !data->image->addr)
		return ;
	if (x >= WIDTH || y >= HEIGHT || x < 0 || y < 0)
		return ;
	index = y * data->image->line_length + x * data->image->bits_per_pixel / 8;
	data->image->addr[index] = color & 0xFF;
	data->image->addr[index + 1] = (color >> 8) & 0xFF;
	data->image->addr[index + 2] = (color >> 16) & 0xFF;
}
/** We are changing all the pixels, directly in the buffer */
void	clear_image(t_data *data)
{
	char	*dst;
	int		bpp;
	int		size_line;
	int		endian;
	int		total_bytes;
	int		i;

	dst = mlx_get_data_addr(data->image->img, &bpp, &size_line, &endian);
	if (!dst)
		return;
	total_bytes = HEIGHT * size_line;
	i = 0;
	while (i < total_bytes)
		dst[i++] = 0;
}

int	draw_loop(t_data *data)
{
	float	fraction;
	float	start_x;
	int		i;

	i = 0;
	fraction = PI / 3 / WIDTH;
	start_x = data->player->angle - PI / 6;
	move_player(data);
	clear_image(data);
	while (i < WIDTH)
	{
		ray_cast(data, start_x, i);
		start_x += fraction;
		i++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->image->img, 0, 0);
	return (0);
}

// void render(t_data *data)
// {
//     float angle;
//     float distance;
//     int x;

//     x = 0;
//     while (x < WIDTH)
//     {
//         angle = data->player->angle - 
//				data->fov / 2 + (float)x / WIDTH * data->fov;
//         distance = cat_ray(angle);
//         distance *= cos(data->player->angle - angle);
//     }
// }