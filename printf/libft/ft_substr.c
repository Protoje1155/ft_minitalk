/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoster <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:58:41 by mkoster           #+#    #+#             */
/*   Updated: 2024/03/01 17:58:42 by mkoster          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	calc_sublen(unsigned int s_len, unsigned int start, size_t len)
{
	unsigned int	j;
	unsigned int	i;
	size_t			sub_len;

	i = start;
	j = 0;
	sub_len = 0;
	while (i < s_len && j < len)
	{
		sub_len++;
		j++;
		i++;
	}
	return (sub_len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	s_len;
	size_t			sub_len;
	char			*p;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	sub_len = calc_sublen(s_len, start, len);
	i = start;
	j = 0;
	p = malloc(sizeof(char) * (sub_len + 1));
	if (p == NULL)
		return (NULL);
	while (i < s_len && j < len)
		p[j++] = s[i++];
	p[j] = '\0';
	return (p);
}
