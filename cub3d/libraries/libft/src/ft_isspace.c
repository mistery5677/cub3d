/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thopgood <thopgood@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 16:28:19 by thopgood          #+#    #+#             */
/*   Updated: 2025/02/06 10:54:59 by thopgood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * Returns true if char is horizontal tab, line feed, vertical tab, form feed
 * carriage return or space, false otherwise.
 */

int	ft_isspace(char c)
{
	return (('\t' <= c && c <= '\r') || c == ' ');
}
