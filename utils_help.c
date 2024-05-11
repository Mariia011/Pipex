/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_help.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marikhac <marikhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 16:19:03 by marikhac          #+#    #+#             */
/*   Updated: 2024/05/11 17:33:46 by marikhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	first_state_process_helper(int *files, char *const filename)
{
	files[IN] = file_open(filename, READ);
	dup2(files[IN], STDIN_FILENO);
	close(files[IN]);
}

void	second_state_process_helper(int *files, char *const filename)
{
	files[OUT] = file_open(filename, RDWR);
	dup2(files[OUT], STDOUT_FILENO);
	close(files[OUT]);
}

char	**path_helper(char *env[])
{
	char	*path;
	char	**env_p;

	path = get_path_envp(env);
	env_p = get_env_p(path);
	free(path);
	return (env_p);
}
