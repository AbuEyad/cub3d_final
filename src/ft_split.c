/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habu-zua <habu-zua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:01:32 by habu-zua          #+#    #+#             */
/*   Updated: 2024/05/31 16:34:11 by habu-zua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_word_lengt(char const *s, char c)
{
	int	i;
	int	lengt;

	i = 0;
	lengt = 1;
	while (s[i] && s[i] == c)
		i++;
	while (s[i] && s[i] != c)
	{
		i++;
		lengt++;
	}
	return (lengt);
}

int	ft_word_count(char const *s, char c)
{
	int	len;
	int	i;

	i = 0;
	len = 0;
	while (s[i])
	{
		if (s[i] != c && i == 0)
			len++;
		else if (s[i] != c && s[i - 1] == c)
			len++;
		i++;
	}
	return (len);
}

char	**ft_alloc(char const *s, char c, int word_count, char **words)
{
	int		i;
	int		storage;
	char	*word;

	i = 0;
	storage = 0;
	while (storage < word_count)
	{
		word = (char *)malloc(sizeof(char) * (ft_word_lengt(s + i, c)));
		if (!word)
		{
			while (storage >= 0)
				free(words[storage--]);
			free(words);
			return (NULL);
		}
		words[storage++] = word;
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
			i++;
	}
	words[storage] = 0;
	return (words);
}

char	**ft_create_tab(char const *s, char c, int word_count, char **words)
{
	int		i;
	int		index;
	int		storage;

	i = 0;
	storage = 0;
	while (storage < word_count)
	{
		while (s[i] && s[i] == c)
			i++;
		index = 0;
		while (s[i] && s[i] != c)
		{
			words[storage][index] = s[i];
			index++;
			i++;
		}
		words[storage][index] = '\0';
		storage++;
	}
	words[storage] = 0;
	return (words);
}

char	**ft_split(char const *s, char c)
{
	int		word_count;
	char	**words;

	if (!s)
		return (NULL);
	word_count = ft_word_count(s, c);
	words = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!words)
		return (NULL);
	words = ft_alloc(s, c, word_count, words);
	words = ft_create_tab(s, c, word_count, words);
	return (words);
}
