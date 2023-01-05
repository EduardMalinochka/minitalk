/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elukutin <elukutin@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 19:30:51 by elukutin          #+#    #+#             */
/*   Updated: 2022/12/18 12:04:32 by elukutin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	power(int i)
{
	if (i == 1)
		return (1);
	if (i == 2)
		return (2);
	if (i == 3)
		return (4);
	if (i == 4)
		return (8);
	if (i == 5)
		return (16);
	if (i == 6)
		return (32);
	if (i == 7)
		return (64);
	if (i == 8)
		return (128);
	return (0);
}

void	handler(int signal)
{
	static int				deg;
	static unsigned char	c;

	if (!deg)
		deg = 8;
	if (deg != 0)
	{
		if (signal == SIGUSR2)
			c += power(deg);
		deg--;
	}
	if (deg == 0)
	{
		write(1, &c, 1);
		deg = 8;
		c = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_putnbr_fd(pid, 1);
	while (1)
	{
		signal(SIGUSR1, handler);
		signal(SIGUSR2, handler);
		pause();
	}
}
