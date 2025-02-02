/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thopgood <thopgood@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 18:37:38 by thopgood          #+#    #+#             */
/*   Updated: 2024/06/15 00:04:00 by thopgood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printchar(int c)
{
	return (write(1, &c, 1));
}

int	ft_printstr(char *str)
{
	int	count;

	count = 0;
	if (str == NULL)
	{
		if (write(1, NULL_MSG, ft_strlen(NULL_MSG)) == -1)
			return (-1);
		return (ft_strlen(NULL_MSG));
	}
	while (*str)
	{
		if (ft_printchar((int)*str) == -1)
			return (-1);
		++count;
		++str;
	}
	return (count);
}
