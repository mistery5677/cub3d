/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thopgood <thopgood@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 19:29:04 by thopgood          #+#    #+#             */
/*   Updated: 2025/02/04 19:29:05 by thopgood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_dformat_specifier(int fd, char specifier, va_list *args)
{
	if (specifier == 'c')
		return (ft_dprintchar(fd, va_arg(*args, int)));
	else if (specifier == 's')
		return (ft_dprintstr(fd, va_arg(*args, char *)));
	else if (specifier == 'd' || specifier == 'i')
		return (ft_dprintdec(fd, va_arg(*args, int)));
	else if (specifier == 'u')
		return (ft_dprintdec(fd, va_arg(*args, unsigned int)));
	else if (specifier == 'x' || specifier == 'X')
		return (ft_dprinthex(fd, (va_arg(*args, unsigned int)), specifier));
	else if (specifier == 'p')
		return (ft_dprintptr(fd, va_arg(*args, unsigned long long)));
	else if (specifier == '%')
		return (ft_dprintchar(fd, '%'));
	return (-1);
}

int	ft_dprocess_format(int fd, const char *format, va_list *args)
{
	int	return_length;
	int	temp_length;

	return_length = 0;
	while (*format)
	{
		if (*format == '%')
		{
			temp_length = ft_dformat_specifier(fd, *(++format), args);
			if (temp_length == -1)
				return (-1);
			return_length += temp_length;
		}
		else
		{
			if (write(fd, format, 1) == -1)
				return (-1);
			return_length += 1;
		}
		++format;
	}
	return (return_length);
}

int	ft_dprintf(int fd, const char *format, ...)
{
	int		return_length;
	va_list	args;

	if (format == NULL || fd < 0)
		return (-1);
	va_start(args, format);
	return_length = ft_dprocess_format(fd, format, &args);
	va_end(args);
	return (return_length);
}
