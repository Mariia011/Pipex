/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marikhac <marikhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 12:34:03 by marikhac          #+#    #+#             */
/*   Updated: 2024/02/24 16:49:54 by marikhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s, char const c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	if (s[i] != '\0')
		i++;
	return (i);
}

void	ft_free_old(char **memory)
{
	int		i;
	int		len_free;
	char	*tmp;

	len_free = ft_strlen(*memory, '\n');
	tmp = malloc(ft_strlen(*memory, 0) - len_free + 1);
	i = 0;
	while ((*memory)[len_free] != '\0')
		tmp[i++] = (*memory)[len_free++];
	tmp[i] = '\0';
	free(*memory);
	*memory = tmp;
}

char	*ft_strdup(char const *const memory)
{
	int		len;
	int		i;
	char	*str;

	len = ft_strlen(memory, '\n');
	i = 0;
	str = malloc(len + 1);
	while (i < len)
	{
		str[i] = memory[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

void	ft_append(char **memory, char *buffer)
{
	int		i;
	int		t;
	int		d;
	char	*tmp;

	tmp = malloc(ft_strlen(*memory, 0) + ft_strlen(buffer, 0) + 1);
	i = 0;
	d = 0;
	t = 0;
	while ((*memory)[i] || buffer[d])
	{
		if ((*memory)[i])
			tmp[t++] = (*memory)[i++];
		else
			tmp[t++] = buffer[d++];
	}
	tmp[t] = '\0';
	free(*memory);
	*memory = tmp;
}

char	*ft_memchar(char *str, char c)
{
	while (*str)
	{
		if (*str == c)
			return (str);
		str++;
	}
	return (NULL);
}
