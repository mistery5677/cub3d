/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thopgood <thopgood@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 12:23:45 by thopgood          #+#    #+#             */
/*   Updated: 2024/06/15 01:00:55 by thopgood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * Applies function f to each character (passed by ptr) of string s.
 * f takes character's index as first argument and ptr to char as second.
 */

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if (s == NULL)
		return ;
	i = 0;
	while (s[i])
	{
		(*f)(i, s + i);
		i++;
	}
}
