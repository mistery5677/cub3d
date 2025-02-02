/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_var.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thopgood <thopgood@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 14:18:30 by thopgood          #+#    #+#             */
/*   Updated: 2025/01/27 19:49:09 by thopgood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/** @brief returns allocated string from variable number of un-allocated strings
 */
char	*join_var(int count, ...)
{
	va_list	args;
	char	*result;
	char	*next_str;
	char	*new_result;

	result = ft_strdup("");
	va_start(args, count);
	while (count-- > 0)
	{
		next_str = va_arg(args, char *);
		new_result = ft_strjoin(result, next_str);
		free(result);
		result = new_result;
		if (!result)
		{
			va_end(args);
			return (NULL);
		}
	}
	va_end(args);
	return (result);
}
