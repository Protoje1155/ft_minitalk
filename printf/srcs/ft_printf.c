/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoster <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 15:35:28 by mkoster           #+#    #+#             */
/*   Updated: 2024/03/15 15:19:53 by mkoster          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	format_func(char format, va_list args, int *len)
{
	if (format == 'c')
	{
		ft_putchar_fd(va_arg(args, int), 1);
		*len += 1;
	}
	else if (format == 's')
		*len += ft_prt_str_len(va_arg(args, char *));
	else if (format == 'd' || format == 'i')
		*len += ft_prt_num_len(va_arg(args, int));
	else if (format == '%')
		*len += write(1, "%", 1);
	else if (format == 'p')
		*len += ft_prt_ptr_len(va_arg(args, void *));
	else if (format == 'u')
		*len += ft_prt_unsi_len(va_arg(args, unsigned int));
	else if (format == 'x')
		*len += ft_prt_hex_low_len(va_arg(args, unsigned int));
	else if (format == 'X')
		*len += ft_prt_hex_upp_len(va_arg(args, unsigned int));
	else
		return ;
}

int	ft_printf(const char *s, ...)
{
	int		len;
	int		i;
	va_list	args;

	va_start(args, s);
	i = 0;
	len = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			format_func(s[i], args, &len);
		}
		else
			len += write(1, &s[i], 1);
		i++;
	}
	va_end(args);
	return (len);
}
