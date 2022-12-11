/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elukutin <elukutin@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 17:01:21 by elukutin          #+#    #+#             */
/*   Updated: 2022/10/27 13:48:56 by elukutin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long	i;
	long	sign;
	long	res;

	i = 0;
	sign = 1;
	res = 0;
	if (str[i] != '\0')
	{
		while (str[i] >= 9 & str[i] <= 13 || str[i] == 32)
			i++;
		if (str[i] == 43 || str[i] == 45)
			if (str[i++] == 45)
				sign *= -1;
		while (str[i] >= 48 && str[i] <= 57)
		{
			res = res * 10 + (str[i++] - 48) * sign;
			if (res > 2147483647)
				return (-1);
			else if (res < -2147483648)
				return (0);
		}
	}
	return (res);
}
