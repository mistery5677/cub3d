/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thopgood <thopgood@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:37:25 by thopgood          #+#    #+#             */
/*   Updated: 2024/06/15 00:44:53 by thopgood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * Converts ASCII to integer. Ignores leading white space. Handles single +/-
 * which determines positive or negative number.
 */

int	ft_atoi(const char *nptr)
{
	int	output;
	int	neg;

	neg = 1;
	output = 0;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			neg *= -1;
		nptr++;
	}
	while (ft_isdigit(*nptr))
	{
		output = (output * 10) + (*nptr - '0');
		nptr++;
	}
	output *= neg;
	return (output);
}
