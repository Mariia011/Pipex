/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marikhac <marikhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:27:21 by marikhac          #+#    #+#             */
/*   Updated: 2024/04/03 14:24:31 by marikhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src, int c)
{
	char	*null_term;
	char	*tmp;
	if(!src)
		return(0);
	null_term = malloc(ft_strlen(src) + 1);
	if (!null_term)
		return (NULL);
	tmp = null_term;
	while (*src != '\0' && *src != c)
	{
		*tmp = *src;
		src++;
		tmp++;
	}
	*tmp = *src;
	return (null_term);
}
