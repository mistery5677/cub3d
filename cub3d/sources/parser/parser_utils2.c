/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thopgood <thopgood@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:55:56 by thopgood          #+#    #+#             */
/*   Updated: 2025/02/13 15:50:33 by thopgood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	set_player_starting_angle(t_data *data, char c)
{
	if (c == 'N')
		data->player->angle = 3 * (PI / 2);
	else if (c == 'E')
		data->player->angle = 0;
	else if (c == 'S')
		data->player->angle = PI / 2;
	else if (c == 'W')
		data->player->angle = PI;
}

bool	is_valid_char(char c)
{
	return (ft_strchr(VALID_CHARS, c));
}

bool	isspace_not_nl(char c)
{
	return (ft_strchr(" \t\f\r\v", c));
}

int	print_matrix(char **matrix)
{
	int	i;

	i = 0;
	printf("\nMap Matrix\n");
	printf(": <- start/end of line\n\n");
	while (matrix[i])
	{
		printf(":%s:\n", matrix[i]);
		i++;
	}
	printf("\n");
	return (0);
}

/** @brief Fetches the index of the last usable (non-space) char in a string.
 */
int	last_usable_char_index(char *str)
{
	int	end;

	if (!str)
		return (ERR_FAIL);
	end = ft_strlen(str) - 1;
	while (end >= 0 && ft_isspace(str[end]))
		end--;
	return (end);
}
