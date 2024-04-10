/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marikhac <marikhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 18:22:27 by marikhac          #+#    #+#             */
/*   Updated: 2024/04/10 19:38:35 by marikhac         ###   ########.fr       */
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
	if(mode == -1)
		exit(-1);
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
		ft_printf("sdk");
		free_stuff(exec_cmd);
		exit(0);
	}
}

void child_process(char **argv, char **env, int *end)
{
	int 	fd;
	char 	*path;

	ft_printf("MASHA");
	fd = file_open(argv[1], 0);

	// path = get_path_envp(env);
	// dup2(fd, STDIN_FILENO);
	// dup2(end[1], STDOUT_FILENO);
	// close(end[0]);
	// // free(path);
	// the_exec(argv[2], path, env);
}

void parent_process(char **argv, char **env, int *end)
{
	ft_printf("MASHA");
	int fd;
	char 	*path;

	// fd = file_open(argv[4], 1);
	// path = get_path_envp(env);
	// dup2(fd, STDOUT_FILENO);
	// dup2(end[0], STDIN_FILENO);
	// close(end[1]);

	// the_exec(argv[3], path, env);
}

int	main(int argc, char *argv[], char *env[])
{
	pid_t	pid;
	int		end[2];

	if (argc != 5)
		return(0);
	if (pipe(end) < 0)
		return(0);
	pid = fork();
	if (pid < 0)
	{
		printf("NO PID");
		exit(-1);
	}
	if (pid == 0)
		child_process(argv, env, end);
	parent_process(argv, env, end);
	return (1);
}
