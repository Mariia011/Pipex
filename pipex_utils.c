/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marikhac <marikhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:47:07 by marikhac          #+#    #+#             */
/*   Updated: 2024/04/11 20:23:49 by marikhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	file_open(char *path, int mode)
{
	int	fd;

	if (mode == 0)
		fd = open(path, O_RDONLY, 0777);
	if (mode == 1)
		fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (mode == -1)
		exit(-1);
	ft_printf("%d", fd);
	return (fd);
}

void	the_exec(char *cmd, char *path, char **env, char **env_p)
{
	char	*path_;
	char	**exec_cmd;

	exec_cmd = ft_split(cmd, ' ');
	path_ = check_cmd(exec_cmd[0], path, env_p);
	if (execve(path_, exec_cmd, env) == -1)
	{
		ft_printf("exec failed on %s", cmd);
		free_stuff(exec_cmd);
		exit(0);
	}
}

void	exit_(int mode)
{
	// perror("./pipex infile cmd1 cmd2 outfile\n");
	if (-1 == mode)
		ft_printf("pid was built wrong, try again");
	if (0 == mode)
		ft_printf("./pipex infile cmd1 cmd2 outfile\n");
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
	ft_printf("the variable is freed\n");
}
