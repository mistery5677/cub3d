/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_incl_nl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thopgood <thopgood@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 09:27:46 by thopgood          #+#    #+#             */
/*   Updated: 2025/02/10 12:26:05 by thopgood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

// int split_incl_nl(t_parse *p, char *backup)
// {
//     int i;

//     i = -1;
// 	while (++i < p->lines)
// 	{
// 		p->end = ft_strchr(p->start, '\n');
// 		if (p->end)
// 		{
// 			p->matrix[i] = ft_substr(p->start, 0, p->end - p->start);
// 			if (!p->matrix[i])
// 				return (free(backup), free_array(p->matrix), print_error("Map",
						// strerror(errno), ERR_FAIL));
// 			p->start = p->end + 1;
// 		}
// 		else
// 		{
// 			p->matrix[i] = ft_strdup(p->start);
// 			if (!p->matrix[i])
// 				return (free(backup), free_array(p->matrix), print_error("Map",
						// strerror(errno), ERR_FAIL));
// 		}
// 	}
//     return (0);
// }

// bool is_empty_line(char* line)
// {
//     while (*line && *line != '\n')
// 	{
//         if (!isspace(*line))
//             return (false);
//         line++;
//     }
//     return (true);
// }

// bool has_empty_internal_lines_in_string(char* str)
// {
//     static bool found_non_empty_line;
//     static bool found_empty_internal_line;
//     char* line_start;
// 	char *temp;

// 	line_start = str;
//     while (*str)
// 	{
//         if (*str == '\n')
// 		{
//             if (is_empty_line(line_start))
// 			{
//                 if (found_non_empty_line)
// 				{
//                     // Check if there are non-empty lines after an empty line
//                     temp = str + 1;
//                     while (*temp != '\0') {
//                         if (!is_empty_line(temp)) {
//                             found_empty_internal_line = true;
//                             break ;
//                         }
//                         while (*temp != '\0' && *temp != '\n') {
//                             temp++;
//                         }
//                         if (*temp == '\n') {
//                             temp++;
//                         }
//                     }
//                     if (found_empty_internal_line) {
//                         return (true); // Found an empty internal line
//                     }
//                     return (false); // Only trailing empty lines
//                 }
//             } else {
//                 found_non_empty_line = true;
//             }
//             line_start = str + 1; // Move to the next line
//         }
//         str++;
//     }

//     return (false); // No empty internal lines found
// }

// bool isspace_not_nl(char c)
// {
// 	return (c == ' ' || c == '\t' || c == '\f' || c == '\r' || c == '\v');
// }

// bool has_internal_empty_lines(char *str)
// {
//     static bool found_content;
//     static bool last_line_was_empty;
//     bool has_non_space;

//     while (*str)
//     {
//         has_non_space = false;
//         while (*str && *str != '\n')
//             if (!isspace_not_nl(*str++))
//                 has_non_space = true;
//         if (has_non_space)
//         {
//             if (found_content && last_line_was_empty)
//                 return (true);
//             found_content = true;
//             last_line_was_empty = false;
//         }
//         else if (found_content)
//             last_line_was_empty = true;
//         if (*str == '\n')
// 			str++;
//     }
// 	return (false);
// }

// bool has_internal_blank_lines(char *str)
// {
// 	int i;
// 	bool found_non_empty_line;

// 	found_non_empty_line = false;
// 	i = -1;
// 	while (str[++i])
// 	{
// 		while (ft_isspace(str[i]))
// 	}
// }

// int count_lines_str(char *str)
// {
// 	int i;
// 	int lines;

// 	lines = 1;
// 	i = -1;
// 	while (str[++i])
// 	{
// 		if (str[i] == '\n')
// 			lines++;
// 	}
// }

// int	str_to_struct(t_data *data, t_parse *p, char *backup)
// {
// 	(void)p;

// 	if (has_internal_empty_lines(backup))
// 		return (free(backup), print_error("Map", GAP_MSG, ERR_FAIL));

// 	data->map->matrix = ft_split(backup, '\n');

// 	// p->lines = count_lines_str(backup);

// 	// p->matrix = ft_calloc(1, (p->lines + 1) * sizeof(char *));
// 	// if (!p->matrix)
// 	// 	return (free(backup), print_error("Map", strerror(errno), ERR_FAIL));
// 	// p->start = backup;
//     // if (split_incl_nl(p, backup) == ERR_FAIL)
//     //     return (ERR_FAIL);
//     // p->matrix[p->lines] = NULL;
// 	// data->map->matrix = p->matrix;
// 	// p->matrix = NULL;
// 	return (0);
// }
