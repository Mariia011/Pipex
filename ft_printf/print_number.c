/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marikhac <marikhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 17:09:32 by marikhac          #+#    #+#             */
/*   Updated: 2024/02/26 13:55:19 by marikhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_number(int n)
{
	if (n < 0)
		return (print_char('-') + print_generic_number(-n, "0123456789",
				ft_strlen("0123456789")));
	return (print_generic_number(n, "0123456789", ft_strlen("0123456789")));
}
