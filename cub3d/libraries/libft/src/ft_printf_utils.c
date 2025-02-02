/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thopgood <thopgood@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 18:34:55 by thopgood          #+#    #+#             */
/*   Updated: 2024/06/15 00:03:55 by thopgood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printdigit(long n, const char *base)
{
	int		count;
	size_t	base_len;

	base_len = ft_strlen(base);
	if (n < 0)
	{
		if (ft_printchar('-') == -1)
			return (-1);
		return (ft_printdigit(-n, base) + 1);
	}
	else if (n >= (int)base_len)
	{
		count = ft_printdigit(n / base_len, base);
		if (count == -1)
			return (-1);
		return (count + ft_printdigit(n % base_len, base));
	}
	return (ft_printchar(base[n]));
}

int	ft_printudigit(unsigned long long n, const char *base)
{
	int		count;
	size_t	base_len;

	base_len = ft_strlen(base);
	if (n >= (unsigned long long)base_len)
	{
		count = ft_printudigit(n / base_len, base);
		if (count == -1)
			return (-1);
		return (count + ft_printudigit(n % base_len, base));
	}
	else
		return (ft_printchar(base[n]));
}

int	ft_printhex(unsigned long long n, char c)
{
	const char	*base;

	if (c == 'x')
		base = HEXLOWER_BASE;
	else if (c == 'X')
		base = HEXUPPER_BASE;
	return (ft_printudigit(n, base));
}

int	ft_printptr(unsigned long long ptr)
{
	if (ptr == 0)
	{
		if (write(1, NIL_MSG, ft_strlen(NIL_MSG)) == -1)
			return (-1);
		return (ft_strlen(NIL_MSG));
	}
	if (write(1, HEX_PREF, ft_strlen(HEX_PREF)) == -1)
		return (-1);
	return (ft_printhex(ptr, 'x') + ft_strlen(HEX_PREF));
}

int	ft_printdec(long n)
{
	const char	*base;

	base = DEC_BASE;
	return (ft_printdigit(n, base));
}
