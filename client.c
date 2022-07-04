/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyjeon <@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 18:18:11 by jaeyjeon          #+#    #+#             */
/*   Updated: 2022/07/01 18:29:17 by jaeyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char **argv)
{
	char	*str;

	if (argc != 3)
		return (0);
	printf("%s\n", argv[2]);
	if (check_str(argv[2]))
		return (0);
	printf("%s\n", argv[2]);
	while (*argv[2])
	{
		str = change_bin((int)*argv[2]);
		if (str == 0)
			return (0);
		while (*str)
		{
			if (*str == '0')
				kill(ft_atoi(argv[1]), SIGUSR1);
			else if (*str == '1')
				kill(ft_atoi(argv[1]), SIGUSR2);
			str++;
			usleep(20);
		}
		argv[2]++;
	}
	return (0);
}
