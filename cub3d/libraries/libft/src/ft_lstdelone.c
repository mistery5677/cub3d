/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thopgood <thopgood@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 17:32:05 by thopgood          #+#    #+#             */
/*   Updated: 2024/06/15 00:51:42 by thopgood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * Takes node *lst as parameter and frees its contents using the function 'del'.
 * Then frees the node itself.
 */

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst == NULL || del == NULL)
		return ;
	(*del)(lst->content);
	free(lst);
}
