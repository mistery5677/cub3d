/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thopgood <thopgood@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 12:42:53 by thopgood          #+#    #+#             */
/*   Updated: 2025/02/10 12:27:38 by thopgood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

/*
 * Fill rules:
 * P (player) = N, E, S, W.
 * 0 must be entirely surrounded (8 tiles) by `0, 1, P`.
 * Flag when P is found, if another is found, return.
 * Check at end that P has been found.
 * No sentinel value is needed because we're not flood filling from the
 * players starting position, we're checking each floor tile for validity.
 */

static bool	do_near_exist(t_map *vars, int y, int x)
{
	if (y == 0 || y + 1 == vars->height)
		return (false);
	if (x == 0 || x + 1 == vars->width)
		return (false);
	return (true);
}

static bool	are_near_valid(char **map, int y, int x)
{
	if (!ft_strchr(NRCHR, map[y + 1][x - 1]) || !ft_strchr(NRCHR, map[y + 1][x])
		|| !ft_strchr(NRCHR, map[y + 1][x + 1]) || !ft_strchr(NRCHR, map[y][x
			+ 1]))
	{
		printf("1!\n");
		return (false);
	}
	if (!ft_strchr(NRCHR, map[y - 1][x + 1]) || !ft_strchr(NRCHR, map[y - 1][x])
		|| !ft_strchr(NRCHR, map[y - 1][x - 1]) || !ft_strchr(NRCHR, map[y][x
			- 1]))
	{
		printf("2!\n");
		return (false);
	}
	return (true);
}

/** @brief Check first that surrounding tiles exist and if they do that
 *  they are all valid values "10NSEW"(NRCHR).
 *
 * NW(y+1,x-1) N(y+1,x) NE(y+1,x+1) E(y,x+1)
 * SE(y-1,x+1)S(y-1,x) SW(y-1,x-1) W(y,x-1)
 */
int	handle_floor_tile(t_map *vars, char **map, int y, int x)
{
	if (ft_strchr(PLCHR, map[y][x]) && vars->player_found)
		return (print_error("Map", PLAYS_MSG, ERR_FAIL));
	else if (ft_strchr(PLCHR, map[y][x]))
		vars->player_found = true;
			// ! set player starting angle here data->player->angle
	if (do_near_exist(vars, y, x) == false)
		return (print_error("Map", FLR_MSG, ERR_FAIL));
	if (are_near_valid(map, y, x) == false)
		return (print_error("Map", FLR_MSG, ERR_FAIL));
	return (0);
}

int	fill_map(t_map *vars, char **map)
{
	int	y;
	int	x;

	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (!is_valid_char(map[y][x]))
				return (print_error("Map:", UNX_MSG, ERR_FAIL));
			if (ft_strchr(FLCHR, map[y][x]))
			{
				if (handle_floor_tile(vars, map, y, x) == ERR_FAIL)
					return (ERR_FAIL);
			}
		}
	}
	return (0);
}

int	parse_map_chars(t_map *vars, char **map)
{
	if (fill_map(vars, map) == ERR_FAIL)
		return (ERR_FAIL);
	if (!vars->player_found)
		return (print_error("Map", NOPLAY_MSG, ERR_FAIL));
	return (0);
}
