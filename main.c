/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyjeon <@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 17:12:52 by jaeyjeon          #+#    #+#             */
/*   Updated: 2022/06/22 17:51:12 by jaeyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	sig_handler_usr1(int signo)
{
	printf ("signal!!!!!!!\n");
	exit (0);
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	printf("server pid : %d\n", pid);
	signal(SIGINT, sig_handler_usr1);
	while (1)
		sleep(1);
	return (0);
}
