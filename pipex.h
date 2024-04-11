/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marikhac <marikhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:50:34 by marikhac          #+#    #+#             */
/*   Updated: 2024/04/11 20:23:41 by marikhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <unistd.h>

// typedef struct s_pipex{
// 	char 	*path;
// 	char	**argv;
// 	char	**env;
// 	int		pipe[2];
// } t_pipex;

char	*get_path_envp(char **env);
char	**get_env_p(char *path);
char	*check_cmd(char *argv_cmd, char *path, char **env_p);

int		file_open(char *path, int mode);
void	the_exec(char *cmd, char *path, char **env, char **env_p);
void	free_stuff(char **someth);
void	exit_(int mode);

#endif
