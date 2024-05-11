/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 18:22:27 by marikhac          #+#    #+#             */
/*   Updated: 2024/05/11 16:44:08 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parent_process(int *files, char **env_p, int *end)
{
	free_stuff(env_p);
	close(end[0]);
	close(end[1]);
	env_p = NULL;
	close_files(files, FILES_SIZE);
	while (-1 != wait(NULL))
		(void)end;
}

static void	first_state_process(char **argv, char **env, int *end, char **env_p)
{
	dup2(end[1], STDOUT_FILENO);
	close(end[0]);
	close(end[1]);
	the_exec(argv[2], env, env_p);
	exit(EXIT_FAILURE);
}

static void	second_state_process(char **argv, char **env, int *end,
		char **env_p)
{
	dup2(end[0], STDIN_FILENO);
	close(end[1]);
	close(end[0]);
	the_exec(argv[3], env, env_p);
	exit(EXIT_FAILURE);
}

static void	do_fork(pid_t *pid)
{
	(*pid) = fork();
	if ((*pid) < 0)
		exit_(1);
}

int	esh_main(int argc, char *argv[], char *env[])
{
	pid_t	pid;
	pid_t	pid2;
	int		end[2];
	int		files[FILES_SIZE];
	char	*path;
	char	**env_p;

	path = get_path_envp(env);
	env_p = get_env_p(path);
	free(path);
	if (argc != 5)
		exit_(1);
	if (pipe(end) < 0)
		exit(EXIT_FAILURE);
	first_state_process_helper(files, argv[1]);
	do_fork(&pid);
	if (0 == pid)
	{
		close(files[IN]);
		first_state_process(argv, env, end, env_p);
	}
	second_state_process_helper(files, argv[4]);
	do_fork(&pid2);
	if (0 == pid2)
	{
		close(files[OUT]);
		second_state_process(argv, env, end, env_p);
	}
	parent_process(files, env_p, end);
	return (EXIT_SUCCESS);
}

int	main(int ac, char **av, char **env)
{
	esh_main(ac, av, env);
	// system("leaks pipex");
}
