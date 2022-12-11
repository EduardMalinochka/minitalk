/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elukutin <elukutin@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 15:27:58 by elukutin          #+#    #+#             */
/*   Updated: 2022/10/24 10:18:57 by elukutin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t size)
{
	char		*d;
	const char	*s;

	d = (char *)dst;
	s = (const char *)src;
	if (!dst && !src)
		return (0);
	if (d < s)
	{
		while (size--)
			*d++ = *s++;
	}
	else
	{
		d += size;
		s += size;
		while (size--)
		{
			*--d = *--s;
		}
	}
	return (dst);
}
