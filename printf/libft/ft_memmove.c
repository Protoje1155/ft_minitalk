/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoster <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:37:59 by mkoster           #+#    #+#             */
/*   Updated: 2024/03/01 17:38:00 by mkoster          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*p_dest;
	unsigned char	*p_src;

	p_dest = (unsigned char *)dest;
	p_src = (unsigned char *)src;
	if (dest == NULL && src == NULL)
		return (0);
	if (p_src < p_dest)
	{
		while (n != 0)
		{
			p_dest[n - 1] = p_src[n - 1];
			n--;
		}
	}
	else
		ft_memcpy(p_dest, p_src, n);
	return (dest);
}
