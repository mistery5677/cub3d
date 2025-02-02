/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thopgood <thopgood@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:29:31 by thopgood          #+#    #+#             */
/*   Updated: 2025/02/10 12:24:46 by thopgood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	print_error(char *prefix, char *msg, int code)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putstr_fd("cub3D", STDERR_FILENO);
	if (prefix)
	{
		ft_putstr_fd(": ", STDERR_FILENO);
		ft_putstr_fd(prefix, STDERR_FILENO);
	}
	if (msg)
	{
		ft_putstr_fd(": ", STDERR_FILENO);
		ft_putstr_fd(msg, STDERR_FILENO);
	}
	ft_putstr_fd("\n", STDERR_FILENO);
	return (code);
}
