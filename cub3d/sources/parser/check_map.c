/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miafonso <miafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:19:01 by miafonso          #+#    #+#             */
/*   Updated: 2025/01/30 15:19:58 by miafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

static int	check_map_name(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '.')
		{
			if (str[i + 1] == 'c'
				&& str[i + 2] == 'u'
				&& str[i + 3] == 'b'
				&& str[i + 4] == '\0')
				return (0);
			else
				return (-1);
		}
		i++;
	}
	return (-1);
}

int	verify_matrix(t_data *data)
{
	int	i;

	if (check_up_down(data->map->matrix[0]) == -1)
		return (-1);
	i = 1;
	while (data->map->matrix[i + 1])
	{
		if (check_line_limit(data->map->matrix[i]) == -1
			|| check_line(data, data->map->matrix[i], i) == -1)
			return (-1);
		i++;
	}
	if (check_up_down(data->map->matrix[i]) == -1)
		return (-1);
	if (data->player->player != 1)
		return (-1);
	return (0);
}

int	check_map(t_data *data, int argc, char **argv)
{
	(void)argv;
	if (argc != 2)
	{
		ft_putstr_fd("Error: Wrong number of arguments\n", 2);
		return (-1);
	}
	if (check_map_name(argv[1]) == -1)
	{
		ft_putstr_fd("Error: Wrong file extension\n", 2);
		return (-1);
	}
	if (check_walls_texture(data, argv[1]) == -1)
	{
		ft_putstr_fd("Error: Wrong walls texture\n", 2);
		return (-1);
	}
	if (verify_matrix(data) == -1)
	{
		ft_putstr_fd("Error: Invalid map\n", 2);
		return (-1);
	}
	return (0);
}
