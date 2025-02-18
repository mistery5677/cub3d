/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thopgood <thopgood@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 16:09:24 by thopgood          #+#    #+#             */
/*   Updated: 2025/02/18 12:10:28 by thopgood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# define ARG_MSG "Wrong number of arguments"
# define USE_MSG " (Usage: ./cub3D map_name.cub)"
# define EXT_MSG "Wrong file extension"
# define DIR_MSG "File is directory"
# define TXT_MSG "Bad wall texture"
# define MAP_MSG "Invalid map"
# define MEM_MSG "Error allocating memory"
# define DUP_MSG "Duplicate element encountered"
# define UNX_MSG "Unexpected character encountered"
# define RGBV_MSG "Incompatible value. Must be 0-255"
# define RGB_MSG "Incorrect format"
# define NOFILE_MSG "No filename given"
# define FINAL_MSG "Element missing or map not last element in file"
# define MIS_MSG "Elements missing"
# define GAP_MSG "Empty line found within map"
# define PLAYS_MSG "More than one player found"
# define NOPLAY_MSG "No player found"
# define FLR_MSG "Floor/player tiles must be surrounded by walls"
# define LOAD_MSG "Error loading element"
# define WIN_MSG "Too large"

# define SPACES " \t\n\v\f\r"
# define VALID_CHARS " 10NSEW"
# define FLCHR "0NSEW"
# define NRCHR "10NSEW"
# define PLCHR "NSEW"

# define ERR_FAIL -1

#endif
