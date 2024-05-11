/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marikhac <marikhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 18:22:27 by marikhac          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/05/11 17:25:45 by marikhac         ###   ########.fr       */
=======
/*   Updated: 2024/05/11 17:15:29 by aamirkha         ###   ########.fr       */
>>>>>>> 889660c840e9b1a03711f4606dc8c32ba9677b54
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	parent_process(char **env_p, int *end)
{
	free_stuff(env_p);
	close(end[0]);
	close(end[1]);
	env_p = NULL;
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


int	main(int argc, char *argv[], char *env[])
{
	pid_t	pids[2];
	int		end[2];
	int		files[FILES_SIZE];
	char	**env_p;

	env_p = path_helper(env);
	if (argc != 5)
		exit_(1);
	if (pipe(end) < 0)
		exit(EXIT_FAILURE);
	first_state_process_helper(files, argv[1]);
	do_fork(&pids[0]);
	if (0 == pids[0])
		first_state_process(argv, env, end, env_p);
	second_state_process_helper(files, argv[4]);
	do_fork(&pids[1]);
	if (0 == pids[1])
		second_state_process(argv, env, end, env_p);
	parent_process(env_p, end);
	return (EXIT_SUCCESS);
}
