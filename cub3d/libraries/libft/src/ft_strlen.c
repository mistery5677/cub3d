/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thopgood <thopgood@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:57:55 by thopgood          #+#    #+#             */
/*   Updated: 2024/06/15 00:59:21 by thopgood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * Returns size_t length of string excl. '\0'
 */

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s++)
		len++;
	return (len);
}
