/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoster <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:29:30 by mkoster           #+#    #+#             */
/*   Updated: 2024/03/01 17:29:31 by mkoster          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	write_p(char *p)
{
	p[0] = '-';
	p[1] = '2';
	p[2] = '1';
	p[3] = '4';
	p[4] = '7';
	p[5] = '4';
	p[6] = '8';
	p[7] = '3';
	p[8] = '6';
	p[9] = '4';
	p[10] = '8';
	p[11] = '\0';
}

static void	reverse(char *p)
{
	int		end;
	int		start;
	char	temp;

	end = 0;
	start = 0;
	while (p[end])
		end++;
	end--;
	while (start < end)
	{
		temp = p[start];
		p[start] = p[end];
		p[end] = temp;
		start++;
		end--;
	}
}

static size_t	calc_len(int n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n > 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static void	write_p1(char *p, int n)
{
	int	minus;
	int	i;

	minus = (n < 0);
	i = 0;
	if (minus)
		n = -n;
	if (n == 0)
		p[i++] = '0';
	while (n > 0)
	{
		p[i++] = (n % 10) + '0';
		n /= 10;
	}
	if (minus)
		p[i++] = '-';
	p[i] = '\0';
}

char	*ft_itoa(int n)
{
	char	*p;
	size_t	len;

	if (n == -2147483648)
	{
		p = (char *)malloc(sizeof(char) * (11 + 1));
		if (p == NULL)
			return (NULL);
		write_p(p);
		return (p);
	}
	len = calc_len(n);
	p = (char *)malloc(sizeof(char) * (len + 1));
	if (p == NULL)
		return (NULL);
	write_p1(p, n);
	reverse(p);
	return (p);
}
