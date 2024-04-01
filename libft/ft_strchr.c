/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marikhac <marikhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:24:39 by marikhac          #+#    #+#             */
/*   Updated: 2024/04/01 17:15:54 by marikhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char		c_char;
	const unsigned char	*str;
	size_t				i;

	c_char = (unsigned char)c;
	str = (const unsigned char *)s;
	if (!n)
		return (NULL);
	i = 0;
	while (i < n)
	{
		if (str[i] == c_char)
		{
			return ((void *)str + i);
		}
		i++;
	}
	return (NULL);
}


char	*ft_strchr(const char *s, int c)
{
	return ((char *)ft_memchr(s, c, ft_strlen(s) + 1));
}
