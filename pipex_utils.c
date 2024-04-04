/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marikhac <marikhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:47:07 by marikhac          #+#    #+#             */
/*   Updated: 2024/04/04 20:18:53 by marikhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exit_(void)
{
	perror("./pipex infile cmd1 cmd2 outfile\n");
	exit(-1);
}

char	**env_p(char *path)
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

void free_stuff(char **free)
{


}

char	*get_paths(char **env)
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
