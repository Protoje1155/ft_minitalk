/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prt_hex_low_len.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoster <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 15:21:06 by mkoster           #+#    #+#             */
/*   Updated: 2024/03/15 15:21:08 by mkoster          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	prt_num(unsigned int n, char *base)
{
	if (n >= 16)
		prt_num((n / 16), base);
	write(1, &base[n % 16], 1);
}

static int	calc_len(unsigned int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		i++;
		n /= 16;
	}
	return (i);
}

int	ft_prt_hex_low_len(unsigned int n)
{
	prt_num(n, "0123456789abcdef");
	return (calc_len(n));
}
