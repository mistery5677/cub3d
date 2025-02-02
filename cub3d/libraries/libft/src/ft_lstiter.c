/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thopgood <thopgood@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 11:38:05 by thopgood          #+#    #+#             */
/*   Updated: 2024/06/15 00:51:16 by thopgood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * Iterates through list 'lst' and applies function 'f' to each node.
 */

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*curr;

	if (lst == NULL || f == NULL)
		return ;
	curr = lst;
	while (curr != NULL)
	{
		(*f)(curr->content);
		curr = curr->next;
	}
}
