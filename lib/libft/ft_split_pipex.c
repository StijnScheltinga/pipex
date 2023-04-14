/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_pipex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschelti <sschelti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 12:01:30 by sschelti          #+#    #+#             */
/*   Updated: 2023/04/14 15:50:28 by sschelti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static	int	word_count(char const *s, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			word++;
		if (s[i] && (s[i] == '\'' || s[i] == '\"'))
		{
			i++;
			while (s[i] && s[i] != '\'' && s[i] != '\"')
				i++;
		}
		while (s[i] && s[i] != c)
			i++;
	}
	return (word);
}

static	int	ft_len(char const *s, char c, int i)
{
	int	ret;

	ret = 0;
	if (s[i - 1] == '\'' || s[i - 1] == '\"')
	{
		while (s[i] && s[i] != '\'' && s[i] != '\"')
		{
			i++;
			ret++;
		}
	}
	else
	{
		while (s[i] && s[i] != c)
		{
			i++;
			ret++;
		}
	}
	return (ret);
}

static void	ft_free(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
}

char	**ft_split_pipex(char const *s, char c)
{
	char	**ptr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	ptr = malloc((word_count(s, c) + 1) * sizeof(char *));
	if (!ptr)
		return (NULL);
	while (j < word_count(s, c))
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\'' || s[i] == '\"')
			i++;
		ptr[j] = ft_substr(s, i, ft_len(s, c, i));
		if (!ptr[j])
			return (ft_free(ptr), NULL);
		i += ft_len(s, c, i);
		if (s[i] == '\'' || s[i] == '\"')
			i++;
		j++;
	}
	ptr[j] = NULL;
	return (ptr);
}
