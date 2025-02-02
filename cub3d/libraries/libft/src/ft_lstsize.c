/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thopgood <thopgood@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 16:45:41 by thopgood          #+#    #+#             */
/*   Updated: 2024/06/15 00:50:10 by thopgood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * Iterates and returns count of list 'lst' size.
 */

int	ft_lstsize(t_list *lst)
{
	int		lst_size;
	t_list	*node;

	lst_size = 0;
	node = lst;
	while (node)
	{
		node = node->next;
		++lst_size;
	}
	return (lst_size);
}
