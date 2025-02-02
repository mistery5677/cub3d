/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_length.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thopgood <thopgood@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 20:37:21 by thopgood          #+#    #+#             */
/*   Updated: 2025/02/04 20:37:44 by thopgood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/** @brief returns the length of a NULL terminated array.
 */
int	arr_length(char **arr)
{
	int	i;

	i = 0;
	if (!arr || !*arr)
		return (-1);
	while (arr[i])
	{
		i++;
	}
	return (i);
}
