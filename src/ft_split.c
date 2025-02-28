/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masmar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 12:38:34 by masmar            #+#    #+#             */
/*   Updated: 2024/08/06 12:38:36 by masmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Frees a dynamically allocated array of strings and returns NULL
void	*ft_free(char **strs)
{
	int	i;

	if (!strs || !*strs)
		return (NULL);
	i = 0;
	while (strs[i] != NULL)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (NULL);
}

// Counts the number of substrings in the string s
// separated by the delimiter character c
int	count_strings(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		if (s[i] != '\0')
			count++;
		while (s[i] != '\0' && s[i] != c)
			i++;
	}
	return (count);
}

// Returns the length of the first substring in s
// up to the delimiter character c or the end of string
int	ft_strlen_sep(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	return (i);
}

// Creates and returns a new string that contains
// the first substring from s up to delimiter e
char	*ft_word(char const *s, char c)
{
	char	*word;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen_sep(s, c);
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (word == NULL)
		return (NULL);
	while (i < len)
	{
		word[i] = s [i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

// Splits the string s into an array of substrings, separated by
// the delimiter c, and return a pointer to teh array of strings
char	**ft_split(char const *s, char c)
{
	char	**strings;
	size_t	i;

	if (!s)
		return (NULL);
	strings = (char **)malloc(sizeof(char *) * (count_strings(s, c) + 1));
	if (!strings)
		return (NULL);
	i = 0;
	while (*s != '\0')
	{
		while (*s != '\0' && *s == c)
			s++;
		if (*s != '\0')
		{
			strings[i] = ft_word(s, c);
			if (!strings[i])
				return (ft_free(strings));
			i++;
		}
		while (*s != '\0' && *s != c)
			s++;
	}
	strings[i] = 0;
	return (strings);
}
