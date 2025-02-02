/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thopgood <thopgood@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 20:44:18 by thopgood          #+#    #+#             */
/*   Updated: 2024/06/15 00:58:46 by thopgood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * Compares string s1 with string s2 for n bytes or until characters differ.
 * Returns difference between s1 and s2.
 */

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n != 0)
	{
		while (*s1 == *s2 && *s1 && --n)
		{
			s1++;
			s2++;
		}
		return ((unsigned char)(*s1) - (unsigned char)(*s2));
	}
	return (0);
}
