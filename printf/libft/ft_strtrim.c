/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoster <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:57:56 by mkoster           #+#    #+#             */
/*   Updated: 2024/03/01 17:57:58 by mkoster          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	find_idx(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s1[i])
	{
		j = 0;
		while (s1[i] != set[j] && set[j])
			j++;
		if (j == ft_strlen(set))
			return (i);
		i++;
	}
	return (i);
}

static size_t	find_idx2(char const *s1, char const *set, size_t len_s1)
{
	size_t	j;

	while (len_s1 > 0)
	{
		j = 0;
		while (s1[len_s1 - 1] != set[j] && set[j])
			j++;
		if (j == ft_strlen(set))
			return (len_s1 - 1);
		len_s1--;
	}
	return (len_s1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	first_idx;
	size_t	last_idx;
	size_t	len_sub;
	size_t	i;
	char	*p;

	first_idx = find_idx(s1, set);
	last_idx = find_idx2(s1, set, ft_strlen(s1));
	len_sub = last_idx - first_idx + 1;
	if (first_idx > last_idx || ft_strlen(s1) == 0)
		len_sub = 0;
	p = (char *)malloc(sizeof(char) * (len_sub + 1));
	if (p == NULL)
		return (NULL);
	i = 0;
	while (i < len_sub && s1[first_idx])
		p[i++] = s1[first_idx++];
	p[i] = '\0';
	return (p);
}
