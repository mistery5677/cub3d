/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_free_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thopgood <thopgood@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 19:35:23 by thopgood          #+#    #+#             */
/*   Updated: 2025/02/04 19:35:36 by thopgood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * If array exists, frees all elements in it and then the pointer
 * to the array. Sets the pointer to the array to NULL.
 */
void	safe_free_array(char ***arr)
{
	int	i;

	if (!arr || !*arr)
		return ;
	i = 0;
	while ((*arr)[i])
	{
		safe_free(&(*arr)[i]);
		i++;
	}
	free(*arr);
	*arr = NULL;
}
