/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyjeon <@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 17:11:04 by jaeyjeon          #+#    #+#             */
/*   Updated: 2022/07/05 23:29:09 by jaeyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	set_data(pid_t pid)
{
	g_data.dec = 0;
	g_data.count = 0;
	g_data.pid = ft_itoa((int)pid);
}

int	check_str_pid(int pid, char *str)
{
	if (pid <= 99 || pid > 100000)
		return (1);
	while (*str)
	{
		if (*str < 0 || *str > 127)
			return (1);
		str++;
	}
	return (0);
}
