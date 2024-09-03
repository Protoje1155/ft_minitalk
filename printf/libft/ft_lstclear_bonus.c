/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoster <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 17:51:59 by mkoster           #+#    #+#             */
/*   Updated: 2024/03/05 17:52:02 by mkoster          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*str;

	if (!del || !lst)
		return ;
	str = *lst;
	while (str)
	{
		tmp = str->next;
		del(str->content);
		free(str);
		str = tmp;
	}
	*lst = NULL;
}
