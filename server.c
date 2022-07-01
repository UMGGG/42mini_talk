/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyjeon <@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 16:41:40 by jaeyjeon          #+#    #+#             */
/*   Updated: 2022/07/01 18:03:12 by jaeyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sig_usr1(int signum)
{
	char	a;

	g_data.bit[g_data.count] = '0';
	g_data.count++;
	if (g_data.count == 8)
	{
		g_data.dec = change_dec(g_data.bit);
		a = (char)g_data.dec;
		write(1, &a, 1);
		g_data.count = 0;
	}
}

void	sig_usr2(int signum)
{
	char	a;

	g_data.bit[g_data.count] = '1';
	g_data.count++;
	if (g_data.count == 8)
	{
		g_data.dec = change_dec(g_data.bit);
		a = (char)g_data.dec;
		write(1, &a, 1);
		g_data.count = 0;
	}
}

int	main(void)
{
	set_data(getpid());
	printf("pid : %d\n", g_data.pid);
	signal(SIGUSR1, sig_usr1);
	signal(SIGUSR2, sig_usr2);
	while (1)
	{
		usleep(1);
	}
	return (0);
}
