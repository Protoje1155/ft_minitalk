/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoster <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:41:35 by mkoster           #+#    #+#             */
/*   Updated: 2024/03/01 17:41:37 by mkoster          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	reverse(char *buff)
{
	char	temp;
	int		start;
	int		end;

	end = 0;
	start = 0;
	while (buff[end])
		end++;
	end--;
	while (start < end)
	{
		temp = buff[start];
		buff[start] = buff[end];
		buff[end] = temp;
		start++;
		end--;
	}
}

static void	store_reversed(char *buff, int n, int minus)
{
	int	i;

	i = 0;
	if (minus)
		n = -n;
	if (n != 0)
	{
		while (n > 0)
		{
			buff[i++] = (n % 10) + '0';
			n /= 10;
		}
		if (minus)
			buff[i++] = '-';
	}
	else if (n == 0)
		buff[i++] = '0';
	buff[i] = '\0';
}

void	ft_putnbr_fd(int n, int fd)
{
	int		minus;
	char	buff[12];

	minus = (n < 0);
	if (fd < 0)
		return ;
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	store_reversed(buff, n, minus);
	reverse(buff);
	ft_putstr_fd(buff, fd);
}
