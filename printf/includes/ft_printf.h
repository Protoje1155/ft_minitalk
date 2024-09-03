/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoster <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 15:23:05 by mkoster           #+#    #+#             */
/*   Updated: 2024/03/15 15:23:08 by mkoster          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

int	ft_printf(const char *s, ...);
int	ft_prt_str_len(const char *s);
int	ft_prt_hex_upp_len(unsigned int n);
int	ft_prt_hex_low_len(unsigned int n);
int	ft_prt_num_len(int num);
int	ft_prt_ptr_len(void *p);
int	ft_prt_unsi_len(unsigned int u);

#endif
