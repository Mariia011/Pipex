/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marikhac <marikhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 18:22:27 by marikhac          #+#    #+#             */
/*   Updated: 2024/04/06 18:16:20 by marikhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int file_open(char *path, int mode)
{
	int fd;

	if(mode == 0)
		fd = open(path, O_RDONLY, 0777);
	if(mode == 1)
		fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	printf("SUKA\n");
	return(fd);
}

void the_exec(char *cmd, char *path, char **env)
{
	char *path_;
	char **exec_cmd;

	exec_cmd = ft_split(cmd, ' ');
	path_ = check_cmd(exec_cmd[0], path);
	if (execve(path_, exec_cmd, env) == -1)
	{
		perror("pipex: command not found: ");
		free_stuff(exec_cmd);
		printf("dfgh");
		exit(0);
	}
}

void child_process()
{

}

void parent_process()
{

}

int	main(int argc, char *argv[], char *env[])
{
	pid_t	pid;
	int		end[2];
	char 	*path;
	if (argc != 5)
		return(0);
	if (pipe(end) < 0)
		return(0);
	pid = fork();
	path = get_path_envp(env);
	if (pid < 0)
	{
		printf("no pid");
		exit(-1);
	}
	if (pid == 0)
		cp_process(end[0], argv, path, 0, env);
	cp_process(end[1], argv, path, 1, env);
	free(path);
	return (1);
}
