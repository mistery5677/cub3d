/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thopgood <thopgood@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:16:00 by thopgood          #+#    #+#             */
/*   Updated: 2024/06/15 00:55:23 by thopgood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * Copies values of n bytes from src to dest.
 * Mutable copies are made (and cast) to ensure byte by byte transfer.
 */

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*dest_cpy;
	const char	*src_cpy;

	if (dest == src)
		return (dest);
	dest_cpy = (char *)dest;
	src_cpy = (const char *)src;
	while (n-- > 0)
		*dest_cpy++ = *src_cpy++;
	return (dest);
}
