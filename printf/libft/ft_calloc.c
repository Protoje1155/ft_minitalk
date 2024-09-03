/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoster <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:25:09 by mkoster           #+#    #+#             */
/*   Updated: 2024/03/01 17:25:13 by mkoster          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;

	if (nmemb == 0 || size == 0)
	{
		nmemb = 1;
		size = 1;
	}
	else if ((nmemb * size) / size != nmemb)
		return (NULL);
	p = (void *)malloc(size * nmemb);
	if (p == NULL)
		return (NULL);
	ft_memset(p, 0, nmemb * size);
	return (p);
}
