/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marikhac <marikhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 18:22:27 by marikhac          #+#    #+#             */
/*   Updated: 2024/05/08 18:42:57 by marikhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parent_process(char **env_p, char *path, int *end) //freeing all the allocations
{
	free_stuff(env_p);
	free(path);
	close(end[0]);
	close(end[1]);
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
	close(end[1]);
	close(fd);

	the_exec(argv[2], path, env, env_p);
	free(path); //if exec failed
	path = NULL;
	exit(EXIT_FAILURE);
}

void	second_state_process(char **argv, char **env, int *end,
 		char *path,char **env_p)
{
	int	fd;

	fd = file_open(argv[4], 1);
	dup2(fd, STDOUT_FILENO);
	dup2(end[0], STDIN_FILENO);

	close(end[1]);
	close(end[0]);
	close(fd);

	the_exec(argv[3], path, env, env_p);
	free(path);
	path = NULL;
	exit(EXIT_FAILURE);
}

int	esh_main(int argc, char *argv[], char *env[])
{
	pid_t	pid;
	pid_t	pid2;
	int		end[2];
	char	*path;
	char	**env_p;
	// int status = 0;

	path = get_path_envp(env);
	env_p = get_env_p(path);

	if (argc != 5)
		exit_(1);
	if (pipe(end) < 0)
		exit(EXIT_FAILURE);
	pid = fork();
	if (pid < 0)
		exit_(1);
	if (0 == pid)
		first_state_process(argv, env, end, path, env_p);
	pid2 = fork();
	if(pid2 < 0)
		exit(1);
	if (0 == pid2)
		second_state_process(argv, env, end, path, env_p);
	parent_process(env_p, path, end);
	waitpid(pid, NULL, 0);
	waitpid(pid2, NULL, 0);
	return(0);
	// return WEXITSTATUS(status);
}


int main(int ac, char **av, char **env)
{
	esh_main(ac, av, env);
	// system("leaks pipex");
	return 0;
}
