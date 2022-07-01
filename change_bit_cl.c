/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_bit_cl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyjeon <@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 16:39:04 by jaeyjeon          #+#    #+#             */
/*   Updated: 2022/07/01 17:02:57 by jaeyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*change_bin(int dec)
{
	char	*bin;
	int		num;
	int		i;

	bin = malloc((sizeof(char)) * 9);
	if (bin == 0)
		return (0);
	i = 7;
	num = 0;
	bin[8] = '\0';
	while (i >= 0)
	{
		if (dec != 0)
		{
			num = dec % 2;
			dec = dec / 2;
		}
		else
			num = 0;
		bin[i] = '0' + num;
		i--;
	}
	return (bin);
}
