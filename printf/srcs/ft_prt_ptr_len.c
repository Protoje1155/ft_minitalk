/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prt_ptr_len.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoster <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 15:22:02 by mkoster           #+#    #+#             */
/*   Updated: 2024/03/15 15:22:03 by mkoster          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	prt_num(unsigned long long addr, char *base)
{
	if (addr >= 16)
		prt_num(addr / 16, base);
	write(1, &base[addr % 16], 1);
}

static int	calc_len(unsigned long long num, int baseSize)
{
	int	len;

	len = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		len++;
		num /= baseSize;
	}
	return (len);
}

int	ft_prt_ptr_len(void *p)
{
	int					len;
	unsigned long long	addr;

	len = 0;
	if (p == NULL)
		return (write(1, "(nil)", 5));
	write (1, "0x", 2);
	addr = (unsigned long long)p;
	prt_num(addr, "0123456789abcdef");
	len = calc_len(addr, 16);
	len += 2;
	return (len);
}
