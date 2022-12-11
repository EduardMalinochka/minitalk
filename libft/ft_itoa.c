/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elukutin <elukutin@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 13:31:34 by elukutin          #+#    #+#             */
/*   Updated: 2022/10/27 00:55:52 by elukutin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	length(long int i)
{
	int	res;

	res = 0;
	if (i == 0)
		return (1);
	if (i < 0)
	{
		i *= -1;
		res++;
	}
	while (i > 0)
	{
		res++;
		i = i / 10;
	}
	return (res);
}

static char	*ft_itoa_malloc(long int i, int len)
{
	char	*res;

	res = malloc(len + 1);
	if (!res)
		return (0);
	res[len] = '\0';
	if (i == 0)
	{
		res[0] = '0';
		return (res);
	}
	if (i < 0)
	{
		res[0] = '-';
		i *= -1;
	}
	while (i > 0)
	{
		len--;
		res[len] = (i % 10) + '0';
		i = i / 10;
	}
	return (res);
}

char	*ft_itoa(int n)
{
	char		*res;
	long int	i;
	int			len;

	i = n;
	len = length(i);
	res = ft_itoa_malloc(i, len);
	return (res);
}
