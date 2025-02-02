/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_no_oflow.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thopgood <thopgood@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 10:55:36 by thopgood          #+#    #+#             */
/*   Updated: 2025/02/10 12:27:19 by thopgood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

/** @brief Helper ft_atoi_no_oflow function to process digits and check next
 *  iteration won't be out of range.
 */
static long long	atoi_process_digits(const char *nptr, int sign,
		bool *out_of_range)
{
	long long	output;

	output = 0;
	while (ft_isdigit(*nptr))
	{
		if (sign == -1 && output == (-(INT_MIN + 1) / 10) && (*nptr
				- '0') == (-(INT_MIN % 10)))
		{
			output = output * 10 + (*nptr - '0');
			nptr++;
			break ;
		}
		if (output > (INT_MAX - (*nptr - '0')) / 10)
		{
			if (out_of_range)
				*out_of_range = true;
			if (sign == 1)
				return (INT_MAX);
			else
				return (INT_MIN);
		}
		output = (output * 10) + (*nptr - '0');
		nptr++;
	}
	return (output);
}

/** @brief Modified atoi function to handle long long and set out_of_range to
 *  true if resulting value is < INT_MIN or > INT_MAX
 */
int	ft_atoi_no_oflow(const char *nptr, bool *out_of_range)
{
	int	output;
	int	sign;

	sign = 1;
	if (out_of_range)
		*out_of_range = false;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	output = atoi_process_digits(nptr, sign, out_of_range);
	return (output * sign);
}
