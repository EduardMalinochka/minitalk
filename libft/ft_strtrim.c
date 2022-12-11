/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elukutin <elukutin@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 13:25:45 by elukutin          #+#    #+#             */
/*   Updated: 2022/11/01 12:23:08 by elukutin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_chr(char const *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	size_t	s;
	size_t	f;
	size_t	i;

	if (!s1)
		return (0);
	s = 0;
	while (s1[s] && check_chr(set, s1[s]))
		s++;
	f = ft_strlen(s1);
	while (f > s && check_chr(set, s1[f - 1]))
		f--;
	res = malloc(f - s + 1);
	if (!res)
		return (0);
	i = 0;
	while (i < f - s)
	{
		res[i] = s1[s + i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
