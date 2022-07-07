/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyjeon <@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 18:19:16 by jaeyjeon          #+#    #+#             */
/*   Updated: 2022/07/07 23:39:10 by jaeyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

// # include "lib/libft/libft.h"
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "lib/libft/libft.h"

typedef struct s_data
{
	char	*pid;
	int		dec;
	char	bit[8];
	int		count;
}			t_data;

t_data	g_data;

int		change_dec(char *str);
int		check_pipe(char chr);
int		check_str_pid(int pid, char *str);
char	*change_bin(int dec);
void	set_data(pid_t pid);
void	sig_usr2(int signum);
void	sig_usr1(int signum);
void	send_end(pid_t pid);
void	send_msg(pid_t pid, char a);

#endif
