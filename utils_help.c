/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_help.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 16:19:03 by marikhac          #+#    #+#             */
/*   Updated: 2024/05/11 16:44:01 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	first_state_process_helper(int *files, char *const filename)
{
	files[IN] = file_open(filename, READ);
	dup2(files[IN], STDIN_FILENO);
}

void	second_state_process_helper(int *files, char *const filename)
{
	files[OUT] = file_open(filename, RDWR);
	dup2(files[OUT], STDOUT_FILENO);
}

void	close_files(int *files, const int size)
{
	int	i;

	i = 0;
	while (i < size)
		close(files[i++]);
}
