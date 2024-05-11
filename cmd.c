/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marikhac <marikhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:47:07 by marikhac          #+#    #+#             */
/*   Updated: 2024/05/11 17:29:10 by marikhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	file_open(char *path, int mode)
{
	int	fd;

	if (mode == 0)
		fd = open(path, O_RDONLY);
	if (mode == 1)
		fd = open(path, O_RDWR | O_CREAT | O_TRUNC, 0777);
	if (fd == -1)
		exit_(3);
	return (fd);
}

static void	exec_helper(char ***exec_cmd)
{
	char	**t;
	int		i;

	t = NULL;
	i = 0;
	while ((*exec_cmd)[i])
		i++;
	t = malloc(sizeof(char *) * (i + 2));
	t[0] = ft_strdup("/bin/bash", '\0');
	i = 0;
	while ((*exec_cmd)[i])
	{
		t[i + 1] = (*exec_cmd)[i];
		i++;
	}
	t[i + 1] = NULL;
	free((*exec_cmd));
	(*exec_cmd) = t;
}

void	the_exec(char *cmd, char **env, char **env_p)
{
	char	*path_;
	char	**exec_cmd;

	exec_cmd = ft_split(cmd, ' ');
	path_ = check_cmd(exec_cmd[0], env_p);
	if (path_ != NULL)
	{
		if (!ft_strncmp(path_, "/bin/bash", ft_strlen(path_)))
		{
			exec_helper(&exec_cmd);
		}
		execve(path_, exec_cmd, env);
	}
	ft_putstr_fd("pipex: command not found: ", 2);
	ft_putendl_fd(exec_cmd[0], 2);
	free_stuff(exec_cmd);
	free(path_);
	exit(EXIT_FAILURE);
}

void	exit_(int mode)
{
	if (ARG_COUNT_ERROR == mode || ARG_ORDER_ERROR == mode)
		ft_putstr_fd("./pipex: infile cmd1 cmd2 outfile\n", STDERR_FILENO);
	else if (mode == CMD_NOT_FOUND_ERROR)
		ft_putstr_fd("./pipex: command not found \n", STDERR_FILENO);
	else if (mode == FILE_NOT_FOUND_ERROR || PIPE_NOT_FOUND_ERROR == mode)
		perror("./pipex: ");
	exit(EXIT_FAILURE);
}

void	free_stuff(char **someth)
{
	int	i;

	i = 0;
	while (someth[i])
	{
		free(someth[i]);
		i++;
	}
	free(someth);
	someth = NULL;
}
