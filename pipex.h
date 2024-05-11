/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marikhac <marikhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:50:34 by marikhac          #+#    #+#             */
/*   Updated: 2024/05/11 16:30:55 by marikhac         ###   ########.fr       */
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

#define READ 0
#define RDWR 1
#define IN 0
#define OUT 1
#define FILES_SIZE 2
#define arg_count_error 1
#define arg_order_error 0
#define cmd_not_found_error 2
#define file_not_found_error 3
#define pipe_error -1

char	*get_path_envp(char **env);
char	**get_env_p(char *path);
char	*check_cmd(char *argv_cmd, char **env_p);

int		file_open(char *path, int mode);
void	the_exec(char *cmd, char **env, char **env_p);
void	free_stuff(char **someth);
void	exit_(int mode);
void first_state_process_helper(int *files, char * const filename);
void second_state_process_helper(int *files, char * const filename);
void close_files(int *files, const int size);

int		if_script(char *res);

#endif // PIPEX_H
