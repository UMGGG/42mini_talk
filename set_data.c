/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyjeon <@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 17:11:04 by jaeyjeon          #+#    #+#             */
/*   Updated: 2022/07/01 18:25:31 by jaeyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	set_data(pid_t pid)
{
	g_data.dec = 0;
	g_data.count = 0;
	g_data.pid = pid;
}

int	check_str(char *str)
{
	while (*str)
	{
		if (*str < 0 && *str > 127)
			return (1);
		str++;
	}
	return (0);
}
