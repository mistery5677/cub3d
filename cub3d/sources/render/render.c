/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mistery576 <mistery576@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 18:23:18 by mistery576        #+#    #+#             */
/*   Updated: 2025/01/22 22:50:34 by mistery576       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

// void render(t_data *data)
// {
//     float angle;
//     float distance;
//     int x;

//     x = 0;
//     while (x < WIDTH)
//     {
//         angle = data->player->angle - data->fov / 2 + (float)x / WIDTH * data->fov;
//         distance = cat_ray(angle);
//         distance *= cos(data->player->angle - angle);
//     }
// }