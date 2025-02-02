/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_words.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thopgood <thopgood@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 21:46:09 by thopgood          #+#    #+#             */
/*   Updated: 2024/07/11 10:25:56 by thopgood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * Returns number of words in string split by chars defined in set.
 */

int	count_words(char *str, char *set)
{
	int	count;

	count = 0;
	while (*str && ft_strchr(set, *str))
		++str;
	while (*str)
	{
		++count;
		while (*str && !ft_strchr(set, *str))
			++str;
		while (*str && ft_strchr(set, *str))
			++str;
	}
	return (count);
}
