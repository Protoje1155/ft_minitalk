/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoster <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:43:00 by mkoster           #+#    #+#             */
/*   Updated: 2024/03/07 15:47:11 by mkoster          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *s, char c)
{
	int	count;
	int	flag;

	flag = 0;
	count = 0;
	if (!(*s))
		return (0);
	while (*s)
	{
		if (*s != c && flag == 0)
		{
			flag = 1;
			count++;
		}
		else if (flag == 1 && *s == c)
			flag = 0;
		s++;
	}
	return (count);
}

static char	*word_dub(const char *s, int start, int end)
{
	char	*p;
	int		i;

	p = (char *)malloc(sizeof(char) * (end - start + 1));
	if (p == NULL)
		return (NULL);
	i = 0;
	while (start < end)
		p[i++] = s[start++];
	p[i] = '\0';
	return (p);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	i;
	size_t	j;
	int		start;

	if (s == NULL)
		return (NULL);
	i = -1;
	j = 0;
	start = -1;
	split = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (split == NULL)
		return (NULL);
	while (++i <= ft_strlen(s))
	{
		if (s[i] != c && start < 0)
			start = i;
		else if (start >= 0 && (s[i] == c || s[i] == '\0'))
		{
			split[j++] = word_dub(s, start, i);
			start = -1;
		}
	}
	split[j] = NULL;
	return (split);
}
