/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thopgood <thopgood@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 19:28:47 by thopgood          #+#    #+#             */
/*   Updated: 2025/02/04 19:28:49 by thopgood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_dprintdigit(int fd, long n, const char *base)
{
	int		count;
	size_t	base_len;

	base_len = ft_strlen(base);
	if (n < 0)
	{
		if (ft_dprintchar(fd, '-') == -1)
			return (-1);
		return (ft_dprintdigit(fd, -n, base) + 1);
	}
	else if (n >= (int)base_len)
	{
		count = ft_dprintdigit(fd, n / base_len, base);
		if (count == -1)
			return (-1);
		return (count + ft_dprintdigit(fd, n % base_len, base));
	}
	return (ft_dprintchar(fd, base[n]));
}

int	ft_dprintudigit(int fd, unsigned long long n, const char *base)
{
	int		count;
	size_t	base_len;

	base_len = ft_strlen(base);
	if (n >= (unsigned long long)base_len)
	{
		count = ft_dprintudigit(fd, n / base_len, base);
		if (count == -1)
			return (-1);
		return (count + ft_dprintudigit(fd, n % base_len, base));
	}
	else
		return (ft_dprintchar(fd, base[n]));
}

int	ft_dprinthex(int fd, unsigned long long n, char c)
{
	const char	*base;

	if (c == 'x')
		base = HEXLOWER_BASE;
	else if (c == 'X')
		base = HEXUPPER_BASE;
	return (ft_dprintudigit(fd, n, base));
}

int	ft_dprintptr(int fd, unsigned long long ptr)
{
	if (ptr == 0)
	{
		if (write(fd, NIL_MSG, ft_strlen(NIL_MSG)) == -1)
			return (-1);
		return (ft_strlen(NIL_MSG));
	}
	if (write(fd, HEX_PREF, ft_strlen(HEX_PREF)) == -1)
		return (-1);
	return (ft_dprinthex(fd, ptr, 'x') + ft_strlen(HEX_PREF));
}

int	ft_dprintdec(int fd, long n)
{
	const char	*base;

	base = DEC_BASE;
	return (ft_dprintdigit(fd, n, base));
}
