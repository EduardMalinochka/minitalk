/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elukutin <elukutin@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 19:30:44 by elukutin          #+#    #+#             */
/*   Updated: 2022/12/18 12:01:00 by elukutin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	g_receiver = 1;

void	received(int signal)
{
	if (g_receiver == 1 && signal == SIGUSR1)
	{
		ft_putstr_fd("Message was received by the server", 1);
		g_receiver = 0;
	}
}

void	bit_print(unsigned char c, int pid)
{
	if (c != 1 && c != 0)
	{
		bit_print(c / 2, pid);
		bit_print(c % 2, pid);
	}
	if (c == 1)
		kill(pid, SIGUSR2);
	if (c == 0)
		kill(pid, SIGUSR1);
	signal(SIGUSR1, received);
	usleep(100);
}

int	pre_bit(unsigned char c)
{
	if (c < 2)
		return (7);
	if (c < 4)
		return (6);
	if (c < 8)
		return (5);
	if (c < 16)
		return (4);
	if (c < 32)
		return (3);
	if (c < 64)
		return (2);
	if (c < 128)
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;
	int	c;

	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		i = 0;
		while (av[2][i])
		{
			c = pre_bit(av[2][i]);
			while (c != 0)
			{
				kill(pid, SIGUSR1);
				signal(SIGUSR1, received);
				c--;
				usleep(100);
			}
			bit_print(av[2][i], pid);
			i++;
		}
	}
	else
		ft_putstr_fd("Invalid amount of arguments, bruh", 1);
	g_receiver = 1;
}
