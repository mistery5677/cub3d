/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thopgood <thopgood@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 13:52:57 by thopgood          #+#    #+#             */
/*   Updated: 2024/07/13 17:21:18 by thopgood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
 * Places n zero-valued bytes to memory pointed to by s
 */
void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;

	ptr = s;
	while (n-- > 0)
		*ptr++ = 0;
}
