/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marikhac <marikhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:50:34 by marikhac          #+#    #+#             */
/*   Updated: 2024/04/06 16:58:53 by marikhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

//# include "./libft/libft.h"
# include "libft/libft.h"

# include <unistd.h>
# include <sys/types.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/wait.h>
#include <errno.h>

char	*get_path_envp(char **env);
char	**env_p(char *path);
char	*check_cmd(char *argv_cmd, char *path);


void	free_stuff(char **someth);
void	exit_(void);



#endif
