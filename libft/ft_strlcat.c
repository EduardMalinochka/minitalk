/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elukutin <elukutin@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 03:45:45 by elukutin          #+#    #+#             */
/*   Updated: 2022/10/27 12:21:40 by elukutin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	d_len;

	i = 0;
	d_len = 0;
	if (dst)
		d_len = ft_strlen(dst);
	if (d_len >= dstsize)
		d_len = dstsize;
	else if (d_len < dstsize - 1 && dstsize > 0)
	{
		while (src[i] && d_len + i < dstsize - 1)
		{
			dst[d_len + i] = src[i];
			i++;
		}
		dst[d_len + i] = 0;
	}
	return (d_len + ft_strlen(src));
}
