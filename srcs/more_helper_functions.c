/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_helper_functions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoster <mkoster@student.42luxembourg.l    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 17:17:45 by mkoster           #+#    #+#             */
/*   Updated: 2024/06/02 14:17:44 by mkoster          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int	checkrangeofint(char *s)
{
	double	res;
	int		i;

	res = 0;
	i = 0;
	while (s[i])
		res = res * 10 + (s[i++] - '0');
	if (res > 2147483647 || res < -2147483648)
		return (0);
	return (1);
}

int	check_and_init_par(int argc, char **argv, int *server_pid)
{
	int	i;
	int	j;

	if (argc != 3)
		return (0);
	i = 1;
	j = 0;
	while (argv[i][j])
	{
		if (argv[i][j] < '0' || argv[i][j] > '9')
			return (0);
		j++;
	}
	if (!checkrangeofint(argv[1]))
		return (0);
	*server_pid = ft_atoi(argv[i]);
	return (1);
}

char	*conv_char_bit(char c)
{
	char	*conv;
	int		i;
	int		j;

	conv = malloc(sizeof(char) * 9);
	if (conv == NULL)
		return (NULL);
	i = 7;
	j = 0;
	while (i >= 0)
	{
		if (c & (1 << i))
			conv[j++] = '1';
		else
			conv[j++] = '0';
		i--;
	}
	conv[8] = '\0';
	return (conv);
}

char	*conv_str_bits(char *s)
{
	char	*str_bits;
	char	*temp;
	int		len;
	int		i;

	if (s == NULL)
		return (NULL);
	len = (ft_strlen(s) * 8);
	str_bits = malloc(sizeof(char) * (len + 1));
	if (str_bits == NULL)
		return (NULL);
	str_bits[0] = '\0';
	i = -1;
	while (s[++i])
	{
		temp = conv_char_bit(s[i]);
		if (temp == NULL)
		{
			free(str_bits);
			return (NULL);
		}
		ft_stringjoin(str_bits, temp);
	}
	str_bits[len] = '\0';
	return (str_bits);
}
