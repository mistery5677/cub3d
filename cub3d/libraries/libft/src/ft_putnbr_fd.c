/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thopgood <thopgood@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 14:03:04 by thopgood          #+#    #+#             */
/*   Updated: 2024/06/15 00:53:24 by thopgood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * Outputs integer 'n' to given file descriptor.
 */

void	ft_putnbr_fd(int n, int fd)
{
	char const	*base;

	base = "0123456789";
	ft_putbase_fd(n, base, fd);
}
