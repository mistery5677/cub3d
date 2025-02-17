/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thopgood <thopgood@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 13:14:45 by thopgood          #+#    #+#             */
/*   Updated: 2025/02/17 14:15:23 by thopgood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

bool	has_internal_empty_lines(char *str)
{
	static bool	found_content;
	static bool	last_line_was_empty;
	bool		has_non_space;

	while (*str)
	{
		has_non_space = false;
		while (*str && *str != '\n')
			if (!isspace_not_nl(*str++))
				has_non_space = true;
		if (has_non_space)
		{
			if (found_content && last_line_was_empty)
				return (true);
			found_content = true;
			last_line_was_empty = false;
		}
		else if (found_content)
			last_line_was_empty = true;
		if (*str == '\n')
			str++;
	}
	return (false);
}

char	*map_to_str(t_data *data, int fd, char *line)
{
	char	*backup;
	char	*str_matrix;

	data->map->matrix = NULL;
	str_matrix = ft_strdup(line);
	if (!str_matrix)
		return (print_error("Map", strerror(errno), -1), NULL);
	while (get_next_line(fd, &line))
	{
		backup = ft_strdup(str_matrix);
		if (!backup)
			return (free(str_matrix), free(line), print_error("Map",
					strerror(errno), -1), NULL);
		free(str_matrix);
		str_matrix = ft_strjoin(backup, line);
		if (!str_matrix)
			return (free(backup), free(line), print_error("Map",
					strerror(errno), -1), NULL);
		free(backup);
		free(line);
	}
	return (str_matrix);
}

/** @brief Trims trailing 'space' from end of allocated string. Returns new
 * 	allocated string and frees string given as arg.
 */
char	*trim_trailing_space(char *str)
{
	int		end;
	char	*new_str;

	end = last_usable_char_index(str);
	if (end < 0)
	{
		new_str = ft_strdup("");
		if (!new_str)
			return (free(str), NULL);
		return (new_str);
	}
	new_str = ft_calloc(end + 2, sizeof(char));
	if (!new_str)
		return (free(str), NULL);
	ft_strlcpy(new_str, str, end + 2);
	free(str);
	return (new_str);
}

int	parse_map(t_data *data, int fd, char *line)
{
	char	*map_str;

	if (!are_textures_parsed(data->texture))
		return (print_error("Map", FINAL_MSG, ERR_FAIL));
	map_str = map_to_str(data, fd, line);
	if (!map_str)
		return (ERR_FAIL);
	if (has_internal_empty_lines(map_str))
		return (free(map_str), print_error("Map", GAP_MSG, ERR_FAIL));
	map_str = trim_trailing_space(map_str);
	if (!map_str)
		return (print_error("Map", strerror(errno), ERR_FAIL));
	data->map->matrix = ft_split(map_str, '\n');
	if (!data->map->matrix)
		return (free(map_str), print_error("Map", strerror(errno), ERR_FAIL));
	free(map_str);
	return (0);
}
