/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_matrix_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mistery576 <mistery576@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 22:37:05 by mistery576        #+#    #+#             */
/*   Updated: 2025/01/21 23:28:35 by mistery576       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

int	check_up_down(char *line)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	if (!line)
		return (-1);
	while (line[i])
	{
		if (line[i] == WALL)
			flag = 1;
		if (line[i] != WALL
			&& line[i] != ' ')
			return (-1);
		i++;
	}
	if (flag == 0)
		return (-1);
	return (0);
}

int check_line_limit(char *line)
{
	int	i;
	int	size;

	size = ft_strlen(line) - 1;
	i = 0;
	while (line[i] && line[i] == ' ')
		i++;
	if (line[i] != WALL)
		return (-1);
	while (line[size] && line[size] == ' ')
		size--;
	if (line[i] != WALL)
		return (-1);
	return (0);
}

int	check_line(t_data *data, char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != WALL
			&& line[i] != FLOOR
			&& line[i] != ' ')
		{
			if (line[i] == 'N'
				|| line[i] == 'O'
				|| line[i] == 'E'
				|| line[i] == 'S')
				data->player++;
			else
				return (-1);
		}
		i++;
	}
	return (0);
}