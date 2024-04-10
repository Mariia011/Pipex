/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marikhac <marikhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:47:07 by marikhac          #+#    #+#             */
/*   Updated: 2024/04/10 18:38:18 by marikhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exit_()
{
	// perror("./pipex infile cmd1 cmd2 outfile\n");
	printf("Chi stacvvvvvum\n");

	exit(-1);
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
	printf("AAAAAAAa\n");
}
