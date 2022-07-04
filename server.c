/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyjeon <@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 16:41:40 by jaeyjeon          #+#    #+#             */
/*   Updated: 2022/07/05 02:09:51 by jaeyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sig_usr1(int signum)
{
	char	a;

	(void)signum;
	g_data.bit[g_data.count] = '0';
	g_data.count++;
	if (g_data.count == 8)
	{
		g_data.dec = change_dec(g_data.bit);
		a = (char)g_data.dec;
		if (a == '\0')
			write(1, "\n", 1);
		else
			write(1, &a, 1);
		g_data.count = 0;
	}
}

void	sig_usr2(int signum)
{
	char	a;

	(void) signum;
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

int	finish_server(void)
{
	free (g_data.pid);
	return (0);
}

int	main(void)
{
	set_data(getpid());
	write(1, "pid : ", 6);
	write(1, g_data.pid, strlen(g_data.pid));
	write(1, "\n", 1);
	signal(SIGUSR1, sig_usr1);
	signal(SIGUSR2, sig_usr2);
	while (1)
		pause();
	free(g_data.pid);
	return (finish_server());
}
