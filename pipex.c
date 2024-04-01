/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marikhac <marikhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 18:22:27 by marikhac          #+#    #+#             */
/*   Updated: 2024/04/01 16:58:58 by marikhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// int find_path(char **execp)
// {
// 	int
// 	while()
// 	{

// 	}
// 	return();
// }

// void pipex()
// {
// 	pid_t parent;
// 	int fd[2];
// 	if(pipe(fd) == -1)
// 	{
// 		perror("Error, please open the pipe properly");
// 		return(-1);
// 	}
// 	parent = fork();
// 	if(parent < 0)
// 	{
// 		return(0);
// 	}
// 	if(parent == 0)
// 	{
// 		pipex(fd[1], a);
// 	}
// 	else
// 		printf("You are in a child process\n");
// }

int main(int argc, char **argv, char **execp)
{
	if(argc != 5)
		return(0);

	char *path = ft_strnstr();
	char **path_to_cmd = ft_split(path, ':');
    free(path_to_cmd);
    return 0;
}
