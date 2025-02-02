/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thopgood <thopgood@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 19:17:24 by thopgood          #+#    #+#             */
/*   Updated: 2024/06/15 00:58:30 by thopgood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * Needle in haystack. Locates little string within big string if found within
 * first len bytes.
 * Returns:
 * - Pointer to first occurrence
 * - NULL if not found
 * - Pointer to big if little == 0
 */

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	len_little;

	if (big == NULL && len == 0)
		return (NULL);
	len_little = ft_strlen(little);
	if (len_little == 0)
		return ((char *)big);
	i = 0;
	while (big[i] && i + len_little <= len)
	{
		if (ft_strncmp(big + i, little, len_little) == 0)
			return ((char *)(big + i));
		++i;
	}
	return (NULL);
}

/* #include <stdio.h>
#include <string.h>

int	main(void)
{
	// null pointer and length of zero should not crash
	ft_strnstr(((void *)0), "fake", 0);
	strnstr(((void *)0), "fake", 0);

	//should seg fault
	ft_strnstr(((void *)0), "fake", 3);
	strnstr(((void *)0), "fake", 3);
}
 */