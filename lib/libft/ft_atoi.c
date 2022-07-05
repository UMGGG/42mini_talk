/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyjeon <@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 17:37:58 by jaeyjeon          #+#    #+#             */
/*   Updated: 2022/07/05 22:59:29 by jaeyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_whitespace(const char *str)
{
	int	i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
	{
		i++;
	}
	return (i);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	num;
	int	pm;

	num = 0;
	pm = 1;
	i = check_whitespace(str);
	while (str[i] != '\0')
	{
		if (str[i] >= 48 && str[i] <= 57)
		{
			num *= 10;
			num += (int)(str[i] - 48);
		}
		else
			return (0);
		i++;
	}
	return (pm * num);
}
