/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thopgood <thopgood@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:55:56 by thopgood          #+#    #+#             */
/*   Updated: 2025/02/07 12:52:26 by thopgood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

bool	is_valid_char(char c)
{
	return (ft_strchr(VALID_CHARS, c));
}

bool	isspace_not_nl(char c)
{
	return (ft_strchr(" \t\f\r\v", c));
	// return (c == ' ' || c == '\t' || c == '\f' || c == '\r' || c == '\v');
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
	// printf("last char: %d\n",end);
	return (end);
}

// bool	is_empty_line(char *line)
// {
// 	while (*line)
// 	{
// 		if (!ft_isspace(*line))
// 			return (false);
// 		line++;
// 	}
// 	return (true);
// }

//
/** @brief Ignores leading and trailing empty lines. Returns true if empty lines
//  * 	are found within content.
//  */
// bool has_empty_internal_lines(char **matrix, int num_lines)
// {
//     bool found_non_empty_line;
// 	int i;
// 	int j;

// 	found_non_empty_line = false;
// 	i = -1;
// 	while (++i < num_lines)
// 	{
// 		if (is_empty_line(matrix[i]))
// 		{
// 			if (found_non_empty_line)
// 			{
// 				j = i;
// 				while (++j < num_lines)
// 				{
// 					if (!is_empty_line(matrix[j]))
// 						return (true);
// 				}
// 				return (false);
// 			}
// 		}
// 		else
// 			found_non_empty_line = true;
// 	}
// 	return (false);
// }
