/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marikhac <marikhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 18:30:58 by marikhac          #+#    #+#             */
/*   Updated: 2024/02/24 16:56:24 by marikhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	read_line(int fd, char **memory)
{
	char	buf[BUFFER_SIZE + 1];
	int		char_read;

	buf[BUFFER_SIZE] = '\0';
	while (!ft_memchar(*memory, '\n'))
	{
		char_read = read(fd, buf, BUFFER_SIZE);
		if (!char_read)
			break ;
		buf[char_read] = '\0';
		ft_append(memory, buf);
	}
}

void	*ft_free_mem(char **memory)
{
	free(*memory);
	*memory = NULL;
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*memory[OPEN_MAX];

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
		return (NULL);
	if (!(memory[fd]))
	{
		(memory[fd]) = malloc(1);
		(memory[fd])[0] = '\0';
	}
	else
	{
		if (ft_memchar((memory[fd]), '\n'))
			ft_free_old(&(memory[fd]));
		else
			return (ft_free_mem(&(memory[fd])));
	}
	read_line(fd, &(memory[fd]));
	if (*(memory[fd]) == '\0')
		return (ft_free_mem(&(memory[fd])));
	return (ft_strdup((memory[fd])));
}
