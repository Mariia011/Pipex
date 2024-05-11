/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marikhac <marikhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:50:34 by marikhac          #+#    #+#             */
/*   Updated: 2024/05/11 17:26:04 by marikhac         ###   ########.fr       */
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

# define READ 0
# define RDWR 1
# define IN 0
# define OUT 1
# define FILES_SIZE 2
# define ARG_COUNT_ERROR 1
# define ARG_ORDER_ERROR 0
# define CMD_NOT_FOUND_ERROR 2
# define FILE_NOT_FOUND_ERROR 3
# define PIPE_NOT_FOUND_ERROR -1

char	*get_path_envp(char **env);
char	**get_env_p(char *path);
char	*check_cmd(char *argv_cmd, char **env_p);

int		file_open(char *path, int mode);
void	the_exec(char *cmd, char **env, char **env_p);
void	free_stuff(char **someth);
void	exit_(int mode);
void	first_state_process_helper(int *files, char *const filename);
void	second_state_process_helper(int *files, char *const filename);
char 	**path_helper(char *env[]);
int		if_script(char *res);

#endif
