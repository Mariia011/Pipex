/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marikhac <marikhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 14:40:48 by marikhac          #+#    #+#             */
/*   Updated: 2024/05/10 20:17:22 by marikhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	if_script(char *res)
{
	int	i;

	i = 0;
	while (res[i])
	{
		if (res[i] == '/')
		{
			return (1);
		}
		i++;
	}
	return (0);
}

char	*get_path_envp(char **env)
{
	int		i;
	char	*path;
	char	*test;

	i = 0;
	while (env[i])
	{
		test = ft_strnstr(env[i], "PATH=", ft_strlen(env[i]));
		if (test)
		{
			while (*test && *test != '/')
				test++;
			path = ft_strdup(test, 0);
		}
		i++;
	}
	return (path);
}

char	**get_env_p(char *path)
{
	char	**env_p;

	env_p = ft_split(path, ':');
	if (!env_p)
	{
		free(path);
		return (0);
	}
	return (env_p);
}

static char	*cmd_search(char **cmd, char **env_p)
{
	char	*res;
	int		i;
	char	*t;

	i = 0;
	while (env_p[i])
	{
		res = ft_strjoin(env_p[i], "/");
		t = res;
		res = ft_strjoin(res, cmd[0]);
		free(t);
		if (access(res, X_OK | F_OK) == 0)
		{
			free_stuff(cmd);
			return (res);
		}
		i++;
		free(res);
		res = NULL;
	}
	free(res);
	return (0);
}

char	*check_cmd(char *argv_cmd, char **env_p)
{
	char	*res;
	char	**cmd;

	cmd = ft_split(argv_cmd, ' ');
	if (!cmd)
		return (0);
	res = cmd_search(cmd, env_p);
	if (res == 0)
	{
		if (if_script(cmd[0]) && access(cmd[0], F_OK) == 0)
			return (ft_strdup("/bin/bash", '\0'));
		exit_(2);
	}
	return (res);
}
