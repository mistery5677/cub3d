/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thopgood <thopgood@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 13:10:37 by thopgood          #+#    #+#             */
/*   Updated: 2025/02/17 14:13:27 by thopgood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

/** @brief Gets useable string from line, maintaining intermediate spaces but
 *  stripping them from beginning and end.
 */
char	*get_texture_path(char *line)
{
	char	*text;
	char	*new_str;
	char	*end;
	int		i;

	i = 0;
	while (line[i] && ft_isspace(line[i]))
		i++;
	if (!line[i])
		return (NULL);
	text = line + i;
	end = text;
	while (*end && *end != '\n')
		end++;
	while (end > text && ft_isspace(*(end - 1)))
		end--;
	*end = '\0';
	new_str = ft_strdup(text);
	if (!new_str)
		return (NULL);
	return (new_str);
}

void	add_texture_to_struct(t_data *data, t_txt_type type, char *path)
{
	if (type == NO)
		data->texture->no_path = path;
	if (type == EA)
		data->texture->ea_path = path;
	if (type == SO)
		data->texture->so_path = path;
	if (type == WE)
		data->texture->we_path = path;
}

int	parse_texture(t_data *data, char *line, t_txt_type type)
{
	char	*path;
	int		fd;

	if (!is_first_occurrence(data, type))
		return (print_error("Texture", DUP_MSG, ERR_FAIL));
	path = get_texture_path(line + 2);
	if (!path)
		return (print_error("Texture", NOFILE_MSG, ERR_FAIL));
	if (is_file_dir(path))
		return (free(path), print_error("Texture", DIR_MSG, ERR_FAIL));
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (free(path), print_error("Texture", strerror(errno), ERR_FAIL));
	close(fd);
	add_texture_to_struct(data, type, path);
	return (0);
}
