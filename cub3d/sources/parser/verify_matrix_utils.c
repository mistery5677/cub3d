/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_matrix_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miafonso <miafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 22:37:05 by mistery576        #+#    #+#             */
/*   Updated: 2025/01/27 12:06:42 by miafonso         ###   ########.fr       */
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

int	check_line(t_data *data, char *line, int x)
{
	int	i;

	i = 0;
	(void)x;
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
			{
				data->player->look = ft_strdup(line);
				//data->player->y_pst = i;
				//data->player->x_pst = x;
				data->player->player++;
			}
			else
				return (-1);
		}
		i++;
	}
	return (0);
}
