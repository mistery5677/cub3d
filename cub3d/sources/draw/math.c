/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miafonso <miafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:23:59 by miafonso          #+#    #+#             */
/*   Updated: 2025/02/10 16:23:23 by miafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

/* Gets the column of the texture that we want to print */
int	verify_side(t_data *data, float ray_x, float ray_y)
{
	float wall_x; // Represents the point, where the ray hits
	int	tex_x;

	tex_x = 0;
	if (data->wall->side == VERTICAL)
		wall_x = ray_y;
	else
		wall_x = ray_x;
	wall_x /= BLOCK; //Change to wall size;
	wall_x -= floor (wall_x); // Gets only the franction of the texture;
	tex_x = (int)(wall_x * (float)64); // Gets the texture column
	if (tex_x < 0) // Protection
		tex_x = 0;
	if (tex_x >= 64)
		tex_x = 64 - 1;
	return (tex_x);	
}

