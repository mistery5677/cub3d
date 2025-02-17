/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thopgood <thopgood@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:19:01 by miafonso          #+#    #+#             */
/*   Updated: 2025/02/17 13:17:52 by thopgood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

bool	is_file_valid(char *path)
{
	int	fd;

	if (!is_ext_valid(path, ".cub"))
		return (print_error("File", EXT_MSG USE_MSG, false));
	if (is_file_dir(path))
		return (print_error("File", DIR_MSG, false));
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (print_error("File", strerror(errno), false));
	close(fd);
	return (true);
}

int	parse_line(t_data *data, int fd, char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		while (ft_isspace(line[i]))
			i++;
		if (!line[i] || line[i] == '\n')
			return (0);
		if (!ft_strncmp(line + i, "NO", 2))
			return (parse_texture(data, line + i, NO));
		else if (!ft_strncmp(line + i, "EA", 2))
			return (parse_texture(data, line + i, EA));
		else if (!ft_strncmp(line + i, "SO", 2))
			return (parse_texture(data, line + i, SO));
		else if (!ft_strncmp(line + i, "WE", 2))
			return (parse_texture(data, line + i, WE));
		else if (line[i] == 'F' || line[i] == 'C')
			return (parse_rgb(data, line));
		else if (line[i] == '1')
			return (parse_map(data, fd, line));
		return (print_error("Map", UNX_MSG, ERR_FAIL));
	}
	return (ERR_FAIL);
}

int	parse_map_file(t_data *data, char *path)
{
	int		fd;
	char	*curr_line;

	fd = open(path, O_RDONLY);
	while (get_next_line(fd, &curr_line))
	{
		if (parse_line(data, fd, curr_line) == ERR_FAIL)
			return (free(curr_line), close(fd), ERR_FAIL);
		free(curr_line);
	}
	close(fd);
	if (!are_textures_parsed(data->texture) || !data->map->matrix)
		return (print_error("File", MIS_MSG, ERR_FAIL));
	return (0);
}

bool	is_map_valid(t_data *data, int argc, char **argv)
{
	if (argc != 2)
		return (print_error(NULL, ARG_MSG USE_MSG, false));
	if (!is_file_valid(argv[1]))
		return (false);
	if (parse_map_file(data, argv[1]) == ERR_FAIL)
		return (false);
	if (trim_map(data) == ERR_FAIL)
		return (false);
	if (parse_map_chars(data, data->map, data->map->matrix) == ERR_FAIL)
		return (false);
	return (true);
}
