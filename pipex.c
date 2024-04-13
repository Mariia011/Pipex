/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marikhac <marikhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 18:22:27 by marikhac          #+#    #+#             */
/*   Updated: 2024/04/13 19:10:22 by marikhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parent_process(char **env_p, char *path)
{
	// ft_printf("freeing memory");
	free_stuff(env_p);
	free(path);
	env_p = NULL;
	path = NULL;
}

void	first_state_process(char **argv, char **env, int *end, char *path,
		char **env_p)
{
	int	fd;

	fd = file_open(argv[1], 0);
	dup2(fd, STDIN_FILENO);
	dup2(end[1], STDOUT_FILENO);
	close(end[0]);
	the_exec(argv[2], path, env, env_p);
	// ft_printf("exec failed on %s", );
	free(path);
	// free memory
	exit(EXIT_FAILURE);
}

void	second_state_process(char **argv, char **env, int *end, char *path,
		char **env_p)
{
	int	fd;

	fd = file_open(argv[4], 1);
	// path = get_path_envp(env);
	dup2(fd, STDOUT_FILENO);
	dup2(end[0], STDIN_FILENO);
	close(end[1]);
	the_exec(argv[3], path, env, env_p);
	free(path);
	exit(EXIT_FAILURE);
}

// t_pipex pipe_s(char **argv, char **env, int *end)
// {
// 	t_pipex new_struct;
// 	new_struct = {path, argv, env, pipe};
// 	return(new_struct);
// }

int	main(int argc, char *argv[], char *env[])
{
	pid_t	pid;
	pid_t	pid2;
	int		end[2];
	char	*path;
	char	**env_p;

	int status = 69;

	path = get_path_envp(env);
	env_p = get_env_p(path);

	if (argc != 5)
		exit_(1);
	if (pipe(end) < 0)
		exit(-1);
	pid = fork();
	if (pid < 0)
		exit_(1);
	if (0 == pid)
		first_state_process(argv, env, end, path, env_p);
	pid2 = fork();
	if(pid2 < 0)
		exit(1);
	if (0 == pid)
		second_state_process(argv, env, end, path, env_p); // child nema
	waitpid(pid, NULL, 0);
	waitpid(pid2, &status, 0);
	parent_process(env_p, path);
	return WEXITSTATUS(status);
}
