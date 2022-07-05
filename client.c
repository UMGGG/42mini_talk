/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyjeon <@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 18:18:11 by jaeyjeon          #+#    #+#             */
/*   Updated: 2022/07/05 23:23:56 by jaeyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_end(pid_t pid)
{
	int	i;

	i = 0;
	while (i != 8)
	{
		kill(pid, SIGUSR1);
		i++;
		usleep(200);
	}
	return ;
}

void	send_msg(pid_t pid, char a)
{
	if (a == '0')
		kill(pid, SIGUSR1);
	else if (a == '1')
		kill(pid, SIGUSR2);
}

int	main(int argc, char **argv)
{
	char	*str;
	char	*save;

	if (argc != 3)
		return (0);
	if (check_str_pid(ft_atoi(argv[1]), argv[2]))
		return (0);
	while (*argv[2])
	{
		str = change_bin((int)*argv[2]);
		if (str == 0)
			return (0);
		save = str;
		while (*str)
		{
			send_msg(ft_atoi(argv[1]), *str);
			str++;
			usleep(200);
		}
		argv[2]++;
		free(save);
	}
	send_end(ft_atoi(argv[1]));
	exit(0);
	return (0);
}
