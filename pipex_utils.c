/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marikhac <marikhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:47:07 by marikhac          #+#    #+#             */
/*   Updated: 2024/04/13 18:48:55 by marikhac         ###   ########.fr       */
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
	if (fd == -1 && mode == 0)
		exit(0);
	if (fd == -1 && mode == 1)
		exit(1);
	return (fd);
}

// in exit argument there can be EXIT_FAILURE

void	the_exec(char *cmd, char *path, char **env, char **env_p)
{
	char	*path_;
	char	**exec_cmd;

	exec_cmd = ft_split(cmd, ' ');
	path_ = check_cmd(exec_cmd[0], path, env_p);
	execve(path_, exec_cmd, 0);
	free_stuff(exec_cmd);
	exit(EXIT_FAILURE);
}

void	exit_(int mode)
{
	if(1 == mode)
	{
		perror("Not enough arguments\n");
		exit(EXIT_FAILURE);
	}
	// perror("./pipex infile cmd1 cmd2 outfile\n");
	if (-1 == mode)
		ft_putendl_fd("pid was built wrong, try again", 2);
	if (0 == mode)
		ft_putendl_fd("./pipex infile cmd1 cmd2 outfile\n", 2);
	exit(-1);
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
