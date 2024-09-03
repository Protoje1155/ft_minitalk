/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prt_num_len.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoster <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 15:21:46 by mkoster           #+#    #+#             */
/*   Updated: 2024/03/15 15:21:48 by mkoster          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_calc_digits(int num, int sizeBase)
{
	int	len;

	len = 0;
	if (num <= 0)
		len += 1;
	while (num != 0)
	{
		len += 1;
		num /= sizeBase;
	}
	return (len);
}

int	ft_prt_num_len(int num)
{
	int	len;

	len = 0;
	if (num == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	len = ft_calc_digits(num, 10);
	ft_putnbr_fd(num, 1);
	return (len);
}
