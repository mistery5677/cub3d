/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thopgood <thopgood@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:55:56 by thopgood          #+#    #+#             */
/*   Updated: 2025/02/18 11:31:59 by thopgood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

bool	is_line_only_spaces(char *line)
{
	int	i;

	i = 0;
	while (ft_isspace(line[i]))
		i++;
	if (!line[i] || line[i] == '\n')
		return (true);
	return (false);
}

bool	are_textures_parsed(t_texture *t)
{
	return (t->c_texture != -1 && t->f_texture != -1 && t->no_path && t->ea_path
		&& t->so_path && t->we_path);
}

bool	is_file_dir(char *path)
{
	int	fd;

	if (!path)
		return (false);
	fd = open(path, O_DIRECTORY);
	if (fd < 0)
		return (false);
	else
		return (close(fd), true);
}

/** @brief Checks that ext matches extension of str.
 */
bool	is_ext_valid(char *str, char *ext)
{
	int	str_len;
	int	ext_len;

	if (!str | !ext)
		return (false);
	ext_len = ft_strlen(ext);
	str_len = ft_strlen(str);
	if (ft_strncmp(str + str_len - ext_len, ext, ext_len))
		return (false);
	return (true);
}

bool	is_first_occurrence(t_data *data, t_txt_type type)
{
	if (type == NO)
		return (!data->texture->no_path);
	else if (type == EA)
		return (!data->texture->ea_path);
	else if (type == SO)
		return (!data->texture->so_path);
	else if (type == WE)
		return (!data->texture->we_path);
	else if (type == F)
		return (data->texture->f_texture == -1);
	else if (type == C)
		return (data->texture->c_texture == -1);
	return (false);
}
