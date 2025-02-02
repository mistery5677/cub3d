/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_map2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thopgood <thopgood@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 12:32:29 by thopgood          #+#    #+#             */
/*   Updated: 2025/02/07 12:32:37 by thopgood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	find_shortest_lead(char **arr)
{
	int	shortest_lead;
	int	i;
	int	j;

	shortest_lead = INT_MAX;
	i = -1;
	while (arr[++i])
	{
		j = 0;
		while (isspace_not_nl(arr[i][j]))
			j++;
		shortest_lead = ft_min(shortest_lead, j);
	}
	return (shortest_lead);
}

char	*trim_chars_from_start(char *str, int num_chars)
{
	int		str_len;
	char	*new_str;

	if (!str)
		return (NULL);
	str_len = ft_strlen(str);
	if (num_chars >= str_len)
		return (NULL);
	new_str = ft_strdup(str + num_chars);
	if (!new_str)
		return (NULL);
	return (new_str);
}

int	find_longest_usable_string(char **arr)
{
	int	longest;
	int	i;

	longest = -1;
	i = -1;
	while (arr[++i])
		longest = ft_max(last_usable_char_index(arr[i]), longest);
	return (longest + 1);
}
