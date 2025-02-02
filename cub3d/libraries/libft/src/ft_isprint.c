/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thopgood <thopgood@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 21:41:41 by thopgood          #+#    #+#             */
/*   Updated: 2024/06/15 00:45:29 by thopgood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * Returns true if char is printable (between ASCII 32 and 126 incl.)
 */

int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}
