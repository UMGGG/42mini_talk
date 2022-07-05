/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_bit_se.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyjeon <@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 16:57:56 by jaeyjeon          #+#    #+#             */
/*   Updated: 2022/07/05 18:18:48 by jaeyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	change_dec(char *str)
{
	int	dec;
	int	num;

	dec = 0;
	num = 128;
	while (*str)
	{
		if (*str == '1')
			dec += num;
		num /= 2;
		str++;
	}
	return (dec);
}
