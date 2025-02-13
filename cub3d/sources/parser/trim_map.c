/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thopgood <thopgood@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 17:10:45 by thopgood          #+#    #+#             */
/*   Updated: 2025/02/13 15:51:42 by thopgood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	replace_shortened_strs(char **arr, int max_len)
{
	int		i;
	char	*temp;

	i = -1;
	while (arr[++i])
	{
		temp = arr[i];
		arr[i] = ft_calloc(max_len + 1, sizeof(char));
		if (!arr[i])
			return (print_error("Map", strerror(errno), ERR_FAIL));
		ft_memset(arr[i], ' ', max_len);
		ft_strncpy(arr[i], temp, max_len);
		free(temp);
	}
	return (0);
}

int	trim_trailing_spaces(char **arr)
{
	int	longest_str;

	longest_str = find_longest_usable_string(arr);
	if (replace_shortened_strs(arr, longest_str) == ERR_FAIL)
		return (ERR_FAIL);
	return (0);
}

int	trim_array_leading(char **arr, int num_chars)
{
	int		i;
	char	*temp;

	(void)num_chars;
	i = -1;
	while (arr[++i])
	{
		temp = arr[i];
		arr[i] = trim_chars_from_start(arr[i], num_chars);
		if (!arr[i])
			return (print_error("Map", strerror(errno), ERR_FAIL));
		free(temp);
	}
	return (0);
}

int	trim_leading_spaces(char **arr)
{
	int	lead_len;

	lead_len = find_shortest_lead(arr);
	if (lead_len > 0)
	{
		if (trim_array_leading(arr, lead_len) == ERR_FAIL)
			return (ERR_FAIL);
	}
	return (0);
}

int	trim_map(t_data *data)
{
	if (trim_leading_spaces(data->map->matrix) == ERR_FAIL)
		return (ERR_FAIL);
	if (trim_trailing_spaces(data->map->matrix) == ERR_FAIL)
		return (ERR_FAIL);
	data->map->height = ft_array_size(data->map->matrix);
	data->map->width = ft_strlen(data->map->matrix[0]);
	return (0);
}
