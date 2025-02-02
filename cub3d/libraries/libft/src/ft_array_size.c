/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thopgood <thopgood@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 19:28:39 by thopgood          #+#    #+#             */
/*   Updated: 2025/02/04 19:28:43 by thopgood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_array_size(char **array)
{
	int	array_size;

	array_size = 0;
	if (!array)
		return (0);
	while (array[array_size])
		array_size++;
	return (array_size);
}
