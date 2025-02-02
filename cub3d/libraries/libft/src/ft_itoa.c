/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thopgood <thopgood@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 09:53:42 by thopgood          #+#    #+#             */
/*   Updated: 2024/06/15 00:49:57 by thopgood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
 * Integer to ASCII
 * Returns a mallocated string representing the integer passed as an argument.
 * Returns NULL if allocation fails.
 */

static size_t	ft_numlen(long n)
{
	size_t	len;

	len = 1;
	if (n < 0)
	{
		++len;
		n = ft_abs(n);
	}
	while (n >= 10)
	{
		n /= 10;
		++len;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*res;
	size_t	n_len;
	size_t	i;
	long	n_long;

	n_long = n;
	n_len = ft_numlen(n_long);
	res = malloc(sizeof(char) * (n_len + 1));
	if (res == NULL)
		return (NULL);
	if (n_long < 0)
		res[0] = '-';
	if (n == 0)
		res[0] = '0';
	n_long = ft_abs(n_long);
	i = 0;
	while (n_long != 0)
	{
		res[n_len - 1 - i++] = (n_long % 10) + ('0');
		n_long /= 10;
	}
	res[n_len] = '\0';
	return (res);
}

/* #include <limits.h>

int	main(void)
{
	int n;

	n = INT_MIN;
	ft_printf("%s res\n", ft_itoa(n));
} */