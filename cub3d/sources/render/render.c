/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mistery576 <mistery576@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 18:23:18 by mistery576        #+#    #+#             */
/*   Updated: 2025/02/15 20:04:25 by mistery576       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

void	put_pixel(int x, int y, int color, t_data *data)
{
	char	*pixel;
	int		index;

	if (!data->image || !data->image->addr)
		return ;
	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	index = (y * data->image->line_length)
		+ (x * (data->image->bits_per_pixel >> 3));
	pixel = data->image->addr + index;
	*(int *)pixel = color;
}

/** We are changing all the pixels, directly in the buffer */
void	clear_image(t_data *data)
{
	char	*dst;
	int		total_bytes;
	int		i;

	dst = mlx_get_data_addr(data->image->img,
			&(data)->image->bits_per_pixel,
			&(data)->image->line_length,
			&(data)->image->endian);
	if (!dst)
		return ;
	total_bytes = HEIGHT * data->image->line_length;
	i = 0;
	while (i < total_bytes)
		dst[i++] = 0;
}

int	draw_loop(t_data *data)
{
	int		i;

	i = 0;
	move_player(data);
	clear_image(data);
	while (i < WIDTH)
	{
		dda_algorithm(data, data->ray, i);
		i++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->image->img, 0, 0);
	return (0);
}
