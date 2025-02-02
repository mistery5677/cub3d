/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thopgood <thopgood@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 00:31:03 by thopgood          #+#    #+#             */
/*   Updated: 2024/08/11 16:29:40 by thopgood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

int		ft_clean_buffer(char *buffer);
size_t	ft_strlen_gnl(char *s);
char	*ft_strjoin_gnl(char *s1, char *s2);

/*
 * Checks for negative (or zero) BUFFER_SIZE. Then performs read fail check
 * Clears pertinent fd and returns NULL if read returns error (-1).
 * Reads from buffer and returns new line.
 * EDIT: GNL now modifies the line sent as an argument to allow the return of
 * error codes. 1 = read success, 0 = EOF, -1 = error.
 */

int	get_next_line(int fd, char **line)
{
	static char	buffer[FOPEN_MAX][BUFFER_SIZE + 1];

	if (BUFFER_SIZE <= 0)
		return (-1);
	if (read(fd, 0, 0) < 0)
	{
		if (fd < 0 || fd >= FOPEN_MAX)
			return (-1);
		buffer[fd][0] = '\0';
		return (-1);
	}
	*line = NULL;
	while ((buffer[fd][0] || read(fd, buffer[fd], BUFFER_SIZE) > 0))
	{
		*line = ft_strjoin_gnl(*line, buffer[fd]);
		if (ft_clean_buffer(buffer[fd]) == 1)
			break ;
	}
	if (*line == NULL)
		return (0);
	return (1);
}

/*
 * Iterates over buffer and sets each char to 0 until newline is encountered.
 * Then copies each char after nl to beginning of buffer until '\0'.
 */

int	ft_clean_buffer(char *buffer)
{
	int	i;
	int	j;
	int	is_newline;

	i = 0;
	j = 0;
	is_newline = 0;
	while (buffer[i])
	{
		if (is_newline == 1)
			buffer[j++] = buffer[i];
		if (buffer[i] == '\n')
			is_newline = 1;
		buffer[i] = 0;
		i++;
	}
	return (is_newline);
}
/*
 * ft_strlen_gnl edited to return length of string to either '\n' incl or '\0'.
 * Returns 0 if str doesn't exist.
 */

size_t	ft_strlen_gnl(char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

/*
 * Allocates memory for length of line + length of buffer until nl (if exists).
 * If allocation fails, frees s1 (since line is being reassigned in GNL).
 * While s1 exists & s1[0] has data, string is copied to res. Then s1 is freed.
 * If s1 (line) doesn't exist (is NULL) i.e. on first pass, i is reset to 0.
 * While chars exist on s2, they are copied to res, from res[0] if !s1 and from
 * the end of
 */

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*res;
	size_t	i;

	res = malloc((ft_strlen_gnl(s1) + ft_strlen_gnl(s2)) + 1);
	if (!res)
		return (free(s1), NULL);
	i = 0;
	while (s1 && s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	free(s1);
	while (*s2)
	{
		res[i++] = *s2;
		if (*s2++ == '\n')
			break ;
	}
	res[i] = '\0';
	return (res);
}
