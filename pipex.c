/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marikhac <marikhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 18:22:27 by marikhac          #+#    #+#             */
/*   Updated: 2024/03/28 16:48:30 by marikhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


int check_of_func(char *str)
{
	if(access());
}

int main(int argc, char **argv, char **shtoto)
{
	int fd[2];
	pid_t pid;
	if(pipe(fd) == -1)
	{
		perror("Error, please open the pipe properly");
		return(1);
	}
	int id = fork();
	pid = getpid();
	if(pid == 0)
	{

	}

}