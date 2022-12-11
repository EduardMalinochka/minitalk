/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elukutin <elukutin@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 16:20:43 by elukutin          #+#    #+#             */
/*   Updated: 2022/10/26 19:18:01 by elukutin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*buf;

	if (lst && *lst && del)
	{
		while (*lst)
		{
			buf = (*lst)->next;
			ft_lstdelone(*lst, del);
			*lst = buf;
		}
	}
}
