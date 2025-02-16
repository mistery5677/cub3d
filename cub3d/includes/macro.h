/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macro.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mistery576 <mistery576@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 20:16:22 by mistery576        #+#    #+#             */
/*   Updated: 2025/02/15 16:35:52 by mistery576       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACRO_H
# define MACRO_H
# include "cub.h"

# define _USE_MATH_DEFINES

# define FOV (60.0 * M_PI / 180.0) 

# define ESC 65307
# define LEFT 65361
# define RIGHT 65363
# define A 97
# define S 115
# define D 100
# define W 119

# define HORIZONTAL 3
# define VERTICAL 2
# define WALL '1'
# define FLOOR '0'
# define BLOCK 64
# define PLAYER_SIZE 6

# define WIDTH 1280
# define HEIGHT 720

# define PURPLE 0x660033
# define GREEN 0x00FF00
# define BLUE 0x6666FF
# define GREY 0xA0A0A0
# define PINK 0xFF66B2

# define PI 3.14159265358979323846

# define DEBUG 0
#endif