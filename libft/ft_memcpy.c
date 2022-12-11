/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elukutin <elukutin@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 19:47:13 by elukutin          #+#    #+#             */
/*   Updated: 2022/10/27 10:07:03 by elukutin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*d;
	char	*s;
	int		t;

	if (!dst && !src)
		return (0);
	if (!n)
		return (dst);
	d = (char *)dst;
	s = (char *)src;
	t = 0;
	while (n--)
	{
		*d++ = *s++;
		if (t)
			return (dst);
	}
	return (dst);
}
