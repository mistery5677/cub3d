/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thopgood <thopgood@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 16:52:24 by thopgood          #+#    #+#             */
/*   Updated: 2024/06/15 00:56:08 by thopgood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 *returns the absolute value of a long
 */

long	ft_abs(long n)
{
	long	n_long;

	n_long = n;
	return (n_long *= ((n_long > 0) - (n_long < 0)));
}
