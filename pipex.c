/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marikhac <marikhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 18:22:27 by marikhac          #+#    #+#             */
/*   Updated: 2024/04/04 20:17:38 by marikhac         ###   ########.fr       */
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
	char	**s_cmd;
	char	*path;

	s_cmd = ft_split(cmd, ' ');
	path = get_path(s_cmd[0], env);
	if (execve(path, s_cmd, env) == -1)
	{
		ft_putstr_fd("pipex: command not found: ", 2);
		ft_putendl_fd(s_cmd[0], 2);
		ft_free_tab(s_cmd);
		exit(0);
	}
	free(cmd);
}

void	child_process(int end, char **argv, char *path, int mode)
{
	int file_d;
	char *cmd;
	cmd = _check_(cmd);
	if(!cmd)
		exit_();
	if(mode == 0)
	{
		if(execve(cmd, path) == 0)
			file_d = file_open(file, 0);
		else
			exit();
		dup2(file_d, 0);
		dup2(end, 1);
	}
	else
	{
		if (execve(cmd, path) == 0)
			file_d = file_open(file, 1);
		else
			exit();
		dup2(file_d, 0);
		dup2(end, 0);
	}
	exec(cmd, env);
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
		exit(-1);
	if (!pid)
		child_process(end[0], argv, path, 0);
	parent_process(end[1], argv, path, 1);
	free(path);
	return (1);
}
