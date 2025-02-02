/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thopgood <thopgood@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 16:56:16 by thopgood          #+#    #+#             */
/*   Updated: 2024/06/15 00:51:00 by thopgood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * Returns last node of list 'lst'.
 */

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*node;

	if (lst == NULL)
		return (NULL);
	node = lst;
	while (node->next != NULL)
		node = node->next;
	return (node);
}
