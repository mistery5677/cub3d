/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thopgood <thopgood@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 19:28:56 by thopgood          #+#    #+#             */
/*   Updated: 2025/02/04 19:28:58 by thopgood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_dprintchar(int fd, int c)
{
	return (write(fd, &c, 1));
}

int	ft_dprintstr(int fd, char *str)
{
	int	count;

	count = 0;
	if (str == NULL)
	{
		if (write(fd, NULL_MSG, ft_strlen(NULL_MSG)) == -1)
			return (-1);
		return (ft_strlen(NULL_MSG));
	}
	while (*str)
	{
		if (ft_dprintchar(fd, (int)*str) == -1)
			return (-1);
		++count;
		++str;
	}
	return (count);
}
