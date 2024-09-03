/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoster <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 14:20:46 by mkoster           #+#    #+#             */
/*   Updated: 2024/06/02 14:20:49 by mkoster          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	ft_stringjoin(char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (s2 == NULL || s1 == NULL)
		return ;
	while (s1[i])
		i++;
	while (s2[j])
		s1[i++] = s2[j++];
	free(s2);
	s1[i] = '\0';
}

void	cat_char(char *s, char c)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	s[i++] = c;
	s[i] = '\0';
}

void	conv_bits_to_char(char *to_conv, int min, int max, char *new)
{
	char	result;

	result = 0;
	while (min < max)
	{
		result <<= 1;
		if (to_conv[min] == '1')
			result |= 1;
		min++;
	}
	new[0] = result;
}

char	*conv_bits_to_str(char *s)
{
	char	*new;
	int		len;
	int		i;
	int		j;

	len = ft_strlen(s) / 8;
	new = malloc(sizeof(char) * (len + 1));
	if (new == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		conv_bits_to_char(s, i, i + 8, new + j);
		i = i + 8;
		j++;
	}
	new[j] = '\0';
	return (new);
}

char	*trim_received_bits(char *s)
{
	char	*new;
	int		i;
	int		len;

	len = ft_strlen(s) - 24;
	new = malloc(sizeof(char) * (len + 1));
	if (new == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new[i] = s[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
