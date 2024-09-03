/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prt_unsi_len.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoster <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 15:22:37 by mkoster           #+#    #+#             */
/*   Updated: 2024/03/15 15:22:38 by mkoster          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	prt_unsi(unsigned int u, char *base)
{
	if (u > 9)
		prt_unsi(u / 10, base);
	write(1, &base[u % 10], 1);
}

static int	calc_len(unsigned int u)
{
	int	i;

	i = 0;
	if (u == 0)
		return (1);
	while (u != 0)
	{
		i++;
		u /= 10;
	}
	return (i);
}

int	ft_prt_unsi_len(unsigned int u)
{
	prt_unsi(u, "0123456789");
	return (calc_len(u));
}
