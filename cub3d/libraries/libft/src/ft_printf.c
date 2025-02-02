/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thopgood <thopgood@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 18:28:33 by thopgood          #+#    #+#             */
/*   Updated: 2024/06/15 00:24:45 by thopgood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_format_specifier(char specifier, va_list *args)
{
	if (specifier == 'c')
		return (ft_printchar(va_arg(*args, int)));
	else if (specifier == 's')
		return (ft_printstr(va_arg(*args, char *)));
	else if (specifier == 'd' || specifier == 'i')
		return (ft_printdec((va_arg(*args, int))));
	else if (specifier == 'u')
		return (ft_printdec(va_arg(*args, unsigned int)));
	else if (specifier == 'x' || specifier == 'X')
		return (ft_printhex((va_arg(*args, unsigned int)), specifier));
	else if (specifier == 'p')
		return (ft_printptr(va_arg(*args, unsigned long long)));
	else if (specifier == '%')
		return (ft_printchar('%'));
	else
		return (-1);
}

int	ft_process_format(const char *format, va_list *args)
{
	int	return_length;
	int	temp_length;

	return_length = 0;
	while (*format)
	{
		if (*format == '%')
		{
			temp_length = ft_format_specifier(*(++format), args);
			if (temp_length == -1)
				return (-1);
			return_length += temp_length;
		}
		else
		{
			if (write(1, format, 1) == -1)
				return (-1);
			return_length += 1;
		}
		++format;
	}
	return (return_length);
}

int	ft_printf(const char *format, ...)
{
	int		return_length;
	va_list	args;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	return_length = ft_process_format(format, &args);
	va_end(args);
	return (return_length);
}
