/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyjeon <@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 18:19:16 by jaeyjeon          #+#    #+#             */
/*   Updated: 2022/07/01 17:55:35 by jaeyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

// # include "lib/libft/libft.h"
# include <signal.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "lib/libft/libft.h"

typedef struct s_data
{
	pid_t	pid;
	int		dec;
	char	bit[8];
	char	count;
}			t_data;

t_data	g_data;

int		change_dec(char *str);
int		check_pipe(char chr);
char	*change_bin(int dec);
void	set_data(pid_t pid);
void	sig_usr2(int signum);
void	sig_usr1(int signum);

#endif
