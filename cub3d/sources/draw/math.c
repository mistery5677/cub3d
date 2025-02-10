/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miafonso <miafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:23:59 by miafonso          #+#    #+#             */
/*   Updated: 2025/02/10 17:13:00 by miafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

/* Gets the column of the texture that we want to print */
int	verify_side(t_data *data, float ray_x, float ray_y)
{
	float	wall_x;
	int		tex_x;

	tex_x = 0;
	if (data->wall->side == VERTICAL)
		wall_x = ray_y;
	else
		wall_x = ray_x;
	wall_x /= BLOCK;
	wall_x -= floor (wall_x);
	tex_x = (int)(wall_x * (float)64);
	if (tex_x < 0)
		tex_x = 0;
	if (tex_x >= 64)
		tex_x = 64 - 1;
	return (tex_x);
}

/** DICTIONARY
 * wall_x --> Collumn of the wall that got hit
 * wall_x /= BLOCK --> Change to wall size;
 * wall_x -= floor(wall_x) --> Returns the integer, for example (10.74 = 10)
 * tex_x --> Gets the texture column
 * DICTIONARY*/