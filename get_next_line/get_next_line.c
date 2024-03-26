/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marikhac <marikhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:40:45 by marikhac          #+#    #+#             */
/*   Updated: 2024/02/24 16:34:49 by marikhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	static char	*memory;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
		return (NULL);
	if (!memory)
	{
		memory = malloc(1);
		memory[0] = '\0';
	}
	else
	{
		if (ft_memchar(memory, '\n'))
			ft_free_old(&memory);
		else
			return (ft_free_mem(&memory));
	}
	read_line(fd, &memory);
	if (*memory == '\0')
		return (ft_free_mem(&memory));
	return (ft_strdup(memory));
}

// int	main(void)
// {
// 	int		fd;
// 	char *str;
// 	fd = open("file.txt", O_RDONLY);
// 	str = get_next_line(fd);
// 	printf("%s", str);
// 	str = get_next_line(fd);
// 	printf("%s", str);
// 	str = get_next_line(fd);
// 	printf("%s", str);
// 	str = get_next_line(fd);
// 	printf("%s", str);
// 	close(fd);
// 	free(str);
// }
