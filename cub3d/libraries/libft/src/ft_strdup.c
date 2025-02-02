/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thopgood <thopgood@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 16:55:45 by thopgood          #+#    #+#             */
/*   Updated: 2024/06/15 01:01:10 by thopgood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * String duplication. Allocates memory using malloc for new string and copies
 * contents of original string incl. null termination.
 */

char	*ft_strdup(const char *s)
{
	char	*dup_s;
	size_t	i;

	dup_s = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (dup_s == NULL)
		return (NULL);
	i = -1;
	while (s[++i])
		dup_s[i] = s[i];
	dup_s[i] = '\0';
	return (dup_s);
}
