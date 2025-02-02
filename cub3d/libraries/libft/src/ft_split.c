/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thopgood <thopgood@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:34:02 by thopgood          #+#    #+#             */
/*   Updated: 2024/07/30 17:08:20 by thopgood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * Splits string 's' by delimiter char 'c' and mallocs array of new strings.
 * Returns array terminated with NULL pointer. NULL if fails
 */
static size_t	ft_countwords(char const *str, char const *set)
{
	size_t	word_count;
	size_t	in_word;

	word_count = 0;
	in_word = 0;
	while (*str)
	{
		if (!(ft_strchr(set, *str)) && !in_word)
		{
			in_word = 1;
			word_count++;
		}
		else if (ft_strchr(set, *str))
			in_word = 0;
		str++;
	}
	return (word_count);
}

static void	*free_words(char **words, size_t count)
{
	size_t	i;

	i = 0;
	while (i <= count)
		free(words[i++]);
	free(words);
	return (NULL);
}

static char	**ft_splitstring(char const *str, char const *set, char **words)
{
	size_t	i;
	size_t	words_index;
	size_t	word_start;

	i = 0;
	words_index = 0;
	word_start = 0;
	while (str[i])
	{
		while (ft_strchr(set, str[i]) && str[i])
			++i;
		if (!str[i])
			break ;
		word_start = i;
		while (!(ft_strchr(set, str[i])) && (str[i]))
			++i;
		words[words_index] = ft_substr(str, word_start, i - word_start);
		if (words[words_index] == NULL)
			return (free_words(words, words_index), NULL);
		++words_index;
	}
	return (words);
}

char	**ft_split(char const *s, char c)
{
	char	**words;
	size_t	word_count;
	char	char_string[2];

	if (s == NULL)
		return (NULL);
	char_string[0] = c;
	char_string[1] = '\0';
	word_count = ft_countwords(s, char_string);
	words = malloc(sizeof(char *) * (word_count + 1));
	if (words == NULL)
		return (NULL);
	words = ft_splitstring(s, char_string, words);
	if (words == NULL)
		return (NULL);
	words[word_count] = NULL;
	return (words);
}

/*
#include <stdio.h>

int	main(void)
{
	char const	*str;
	char		c;
	char		**words;

	str = " ";;
	c = ' ';
	words = ft_split(str, c);
	ft_printf(":%s:\n", words[0]);
	ft_printf(":%s:\n", words[1]);
	ft_printf(":%s:\n", words[2]);
	ft_printf(":%s:\n", words[3]);
	ft_printf(":%s:\n", words[4]);
	ft_printf(":%s:\n", words[5]);
}
*/
