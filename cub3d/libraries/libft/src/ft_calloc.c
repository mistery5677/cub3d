/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thopgood <thopgood@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 11:57:52 by thopgood          #+#    #+#             */
/*   Updated: 2024/06/15 00:48:40 by thopgood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * Contiguous allocation. Allocates and initialises memory, set to zero,
 * for an array of elements (nitems) of 'size' size.
 * Returns a pointer to the allocated memory.
 */

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*mem;
	size_t	total_size;

	total_size = nitems * size;
	if (nitems > 0 && size > UINT_MAX / nitems)
		return (NULL);
	mem = malloc(total_size);
	if (mem == NULL)
		return (NULL);
	mem = ft_memset(mem, 0, total_size);
	return (mem);
}

/* #include <stdio.h>
#include <limits.h>
#include <string.h>

// ! overflow not being properly handled. leak with int_min

int	main(void)
{
	// checks for integer overflow
	void *p = ft_calloc(0, 5);
	void *p2 = calloc(0, 5);
	ft_printf("%p mine\n", p);
	ft_printf("%p theirs\n", p2);
	free(p);
	free(p2);

	p = ft_calloc(SIZE_MAX, SIZE_MAX);
	p2 = calloc(SIZE_MAX, SIZE_MAX);
	ft_printf("%p mine\n", p);
	ft_printf("%p theirs\n", p2);
	free(p);
	free(p2);

	p = ft_calloc(-5, -5);
	p2 = calloc(-5, -5);
	ft_printf("%p mine\n", p);
	ft_printf("%p theirs\n", p2);
	free(p);
	free(p2);

	p = ft_calloc(INT_MIN, INT_MIN);
	p2 = calloc(INT_MIN, INT_MIN);
	ft_printf("%p mine\n", p);
	ft_printf("%p theirs\n", p2);
	free(p);
	free(p2);

	p = ft_calloc(-5, 3);
	p2 = calloc(-5, 3);
	ft_printf("%p mine\n", p);
	ft_printf("%p theirs\n", p2);
	free(p);
	free(p2);

	p = ft_calloc(3, -5);
	p2 = calloc(3, -5);
	ft_printf("%p mine\n", p);
	ft_printf("%p theirs\n", p2);
	free(p);
	free(p2);
} */