/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marikhac <marikhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 18:22:27 by marikhac          #+#    #+#             */
/*   Updated: 2024/04/05 16:20:13 by marikhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "pipex.h"

char	*_check_(char *cmd, char *path)
{
	char	*res;
	char	**env;
	int		i;

	i = 0;
	env = env_p(path);
	while (env[i])
	{
		res = ft_strjoin(env[i], "/");
		res = ft_strjoin(env[i], cmd);
		if (access(res, X_OK | F_OK) == 0)
		{
			printf("%s\n", res);
			free(env);
			return (res);
		}
		i++;
	}
	free(env);
	free(res);
	return (0);
}

int file_open(char *path, int mode)
{
	int fd;

	if(mode == 0)
		fd = open(path, O_RDONLY);
	if(mode == 1)
		fd = open(path, O_WRONLY | O_CREAT);
	if(mode < 0)
		exit_();
	return(fd);
}

void the_exec(char *cmd, char **env)
{
	printf("pi[o[]]");
}

// void child_process()
// {

// }

void	cp_process(int end, char **argv, char *path, int mode, char **env)
{
	int file_d;
	char *cmd;

	// if(!cmd)
	// {
	// 	printf("no cmd");
	// 	exit_();
	// }
	if(mode == 0)
	{
		cmd = _check_(argv[2], path);
		printf("%s", cmd);
		if(execve(cmd, &path, env) == 0)
			file_d = file_open(argv[1], 0);
		else
		{
			printf("cp stop");
			exit_();
		}
		dup2(file_d, 0);
		dup2(end, 1);
	}
	else
	{
		cmd = _check_(argv[3], path);
		printf("%s", cmd);
		if (execve(cmd, &path, env) == 0)
			file_d = file_open(argv[4], 1);
		else
		{
			printf("parent p stop");
			exit_();
		}
		dup2(file_d, 0);
		dup2(end, 0);
	}
	//the_exec(cmd, env);
	close(end);
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
	path = get_paths(env);
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
