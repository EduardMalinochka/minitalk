/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elukutin <elukutin@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 15:09:43 by elukutin          #+#    #+#             */
/*   Updated: 2022/11/01 12:23:47 by elukutin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	size(char const *s, char c)
{
	size_t	i;
	size_t	rtn;

	i = 0;
	rtn = 0;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != 0)
			rtn++;
		i++;
	}
	if (s[0] != c)
		rtn++;
	return (rtn);
}

static void	to_split(char **res, char const *s, char c, size_t items)
{
	char	*buf;
	size_t	res_i;
	size_t	i;
	size_t	sep;

	res_i = 0;
	i = 0;
	sep = 0;
	while (res_i < items)
	{
		if (s[i] == c || s[i] == '\0')
		{
			if (sep != 0)
			{
				buf = ft_calloc(sep + 1, sizeof(char));
				ft_memcpy(buf, s + i - sep, sep);
				res[res_i] = buf;
				res_i++;
			}
			sep = 0;
		}
		else
			sep++;
		i++;
	}
}

char	**ft_split(char const *s, char c)
{
	size_t	items;
	char	**res;

	if (!s)
		return (0);
	items = size(s, c);
	if (!*s || !items)
	{
		res = malloc(sizeof(char *) * 1);
		res[0] = NULL;
		return (res);
	}
	items = size(s, c);
	res = malloc(sizeof(char *) * (items + 1));
	if (!res)
		return (0);
	to_split(res, s, c, items);
	res[items] = 0;
	return (res);
}
