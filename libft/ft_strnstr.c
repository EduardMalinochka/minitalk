/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elukutin <elukutin@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 02:57:09 by elukutin          #+#    #+#             */
/*   Updated: 2022/10/23 19:35:16 by elukutin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!*needle)
		return ((char *)haystack);
	while (i < len && *(haystack + i))
	{
		j = 0;
		while (*(needle + j) && i + j < len && *(needle + j) == *(haystack + i
				+ j))
			j++;
		if (!*(needle + j))
			return ((char *)(haystack + i));
		i++;
	}
	return (0);
}
