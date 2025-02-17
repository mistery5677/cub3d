/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thopgood <thopgood@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:50:20 by thopgood          #+#    #+#             */
/*   Updated: 2025/02/17 14:16:28 by thopgood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	arr_to_hex(int red, int green, int blue)
{
	int	rgb;

	rgb = (red << 16) | (green << 8) | blue;
	return (rgb);
}

bool	is_valid_rgb_line(char *line)
{
	char	*trimmed;
	int		i;

	trimmed = ft_strtrim(line, SPACES);
	if (!trimmed)
		return (print_error(NULL, MEM_MSG, false));
	if (!ft_isdigit(trimmed[0]) || trimmed[ft_strlen(trimmed) - 1] == ',')
		return (free(trimmed), print_error("RGB", UNX_MSG, false));
	i = -1;
	while (trimmed[++i])
	{
		if (!ft_isdigit(trimmed[i]) && trimmed[i] != ',' && trimmed[i] != ' '
			&& trimmed[i] != '\n' && trimmed[i] != '\0')
			return (free(trimmed), print_error("RGB", UNX_MSG, false));
		if (trimmed[i] == ',' && trimmed[i + 1] == ',')
			return (free(trimmed), print_error("RGB", RGB_MSG, false));
	}
	free(trimmed);
	return (true);
}

static int	assign_values(t_parse *parse, char **rgb_arr)
{
	int		i;
	bool	out_of_range;
	char	*trimmed;

	parse->rgb[0] = -1;
	parse->rgb[1] = -1;
	parse->rgb[2] = -1;
	if (arr_length(rgb_arr) != 3)
		return (print_error("RGB", RGB_MSG, ERR_FAIL));
	i = -1;
	out_of_range = false;
	while (rgb_arr[++i])
	{
		trimmed = ft_strtrim(rgb_arr[i], SPACES);
		if (!trimmed || *trimmed == '\0' || ft_strchr(trimmed, ' '))
			return (free(trimmed), print_error("RGB", RGB_MSG, ERR_FAIL));
		parse->rgb[i] = ft_atoi_no_oflow(rgb_arr[i], &out_of_range);
		free(trimmed);
		if (out_of_range || parse->rgb[i] < 0 || parse->rgb[i] > 255)
			return (print_error("RGB", RGBV_MSG, ERR_FAIL));
	}
	return (0);
}

int	set_rgb(t_parse *parse, char *line)
{
	char	**rgb_arr;

	line = ft_strtrim(line, SPACES);
	if (!line)
		return (print_error(NULL, strerror(errno), ERR_FAIL));
	rgb_arr = ft_split(line, ',');
	if (!rgb_arr)
		return (print_error(NULL, strerror(errno), ERR_FAIL));
	free(line);
	if (assign_values(parse, rgb_arr) == ERR_FAIL)
		return (free_array(rgb_arr), ERR_FAIL);
	free_array(rgb_arr);
	if (parse->rgb[0] < 0 || parse->rgb[1] < 0 || parse->rgb[2] < 0)
		return (print_error("RGB", RGB_MSG, ERR_FAIL));
	return (0);
}

int	parse_rgb(t_data *data, char *line)
{
	static t_parse	parse;

	if (!is_valid_rgb_line(line + 1))
		return (ERR_FAIL);
	if (set_rgb(&parse, line + 1) == ERR_FAIL)
		return (ERR_FAIL);
	if (*line == 'F')
	{
		if (!is_first_occurrence(data, F))
			return (print_error("RGB", DUP_MSG, ERR_FAIL));
		data->texture->f_texture = arr_to_hex(parse.rgb[0], parse.rgb[1],
				parse.rgb[2]);
	}
	if (*line == 'C')
	{
		if (!is_first_occurrence(data, C))
			return (print_error("RGB", DUP_MSG, ERR_FAIL));
		data->texture->c_texture = arr_to_hex(parse.rgb[0], parse.rgb[1],
				parse.rgb[2]);
	}
	return (0);
}
