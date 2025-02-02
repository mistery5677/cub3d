/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thopgood <thopgood@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 10:47:02 by thopgood          #+#    #+#             */
/*   Updated: 2024/06/15 00:54:38 by thopgood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * Fills a memory block (b) with a particular value (c) for 'len'.
 * Unsigned char is used because it is (typically) 1 byte.
 */

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*p;

	p = b;
	while (len-- > 0)
		*p++ = (unsigned char)c;
	return (b);
}
