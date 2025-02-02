/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thopgood <thopgood@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:56:54 by thopgood          #+#    #+#             */
/*   Updated: 2024/06/15 00:54:54 by thopgood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * Copies data from back or front of src to dest depending on whether
 * dest is before or after src in memory. To account for potential overlaps.
 */

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	char		*dest_copy;
	const char	*src_copy;

	dest_copy = dest;
	src_copy = src;
	if (dest_copy < src_copy)
		while (len--)
			*dest_copy++ = *src_copy++;
	else if (dest_copy > src_copy)
	{
		dest_copy += len;
		src_copy += len;
		while (len--)
			*(--dest_copy) = *(--src_copy);
	}
	return (dest);
}
