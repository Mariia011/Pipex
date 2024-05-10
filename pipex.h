/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marikhac <marikhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:50:34 by marikhac          #+#    #+#             */
/*   Updated: 2024/05/10 20:32:20 by marikhac         ###   ########.fr       */
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

char	*get_path_envp(char **env);
char	**get_env_p(char *path);
char	*check_cmd(char *argv_cmd, char **env_p);

int		file_open(char *path, int mode);
void	the_exec(char *cmd, char **env, char **env_p);
void	free_stuff(char **someth);
void	exit_(int mode);

int		if_script(char *res);

#endif
