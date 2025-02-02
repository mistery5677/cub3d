/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbase_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thopgood <thopgood@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 16:47:12 by thopgood          #+#    #+#             */
/*   Updated: 2024/06/15 00:54:04 by thopgood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * outputs int n in base to file fd
 */

void	ft_putbase_fd(int n, const char *base, int fd)
{
	int		base_len;
	long	n_long;

	base_len = ft_strlen(base);
	if (n < 0)
		ft_putchar_fd('-', fd);
	n_long = ft_abs(n);
	if (n_long > (base_len - 1))
		ft_putbase_fd(n_long / base_len, base, fd);
	ft_putchar_fd(*(base + (n_long % base_len)), fd);
}
