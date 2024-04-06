/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marikhac <marikhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:47:07 by marikhac          #+#    #+#             */
/*   Updated: 2024/04/06 16:43:50 by marikhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exit_()
{
	// perror("./pipex infile cmd1 cmd2 outfile\n");
	perror("Chi stacvum\n");

	exit(0);
}

void free_stuff(char **someth)
{
	int i;

	i = 0;
	while(someth[i])
	{
		free(someth[i]);
		i++;
	}
	free(someth);
	someth = NULL;
	printf("FREED MEMORY\n");
}
