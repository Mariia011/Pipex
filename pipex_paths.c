/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_paths.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marikhac <marikhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 14:40:48 by marikhac          #+#    #+#             */
/*   Updated: 2024/04/11 20:23:45 by marikhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

char	*check_cmd(char *argv_cmd, char *path, char **env_p)
{
	char	*res;
	char	**cmd;
	int		i;

	// char	**env;
	i = 0;
	cmd = ft_split(argv_cmd, ' ');
	if (!cmd)
		return (0);
	// env = env_p(path);
	while (env_p[i])
	{
		res = ft_strjoin(env_p[i], "/");
		res = ft_strjoin(env_p[i], cmd[0]);
		if (access(res, X_OK | F_OK) == 0)
		{
			ft_printf("%s\n", res);
			// free_stuff(env_p);
			free_stuff(cmd);
			return (res);
		}
		i++;
		free(res);
		res = NULL;
	}
	// free_stuff(env);
	free(res);
	return (0);
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
