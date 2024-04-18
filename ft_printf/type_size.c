/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marikhac <marikhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 19:54:30 by marikhac          #+#    #+#             */
/*   Updated: 2024/02/26 13:55:41 by marikhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	type_size(va_list argc, char type)
{
	if (type == 'c')
		return (print_char(va_arg(argc, int)));
	else if (type == 's')
		return (print_string(va_arg(argc, char *)));
	else if (type == 'p')
		return (ft_putstr("0x") + print_ptr(va_arg(argc, size_t),
				"0123456789abcdef", ft_strlen("0123456789abcdef")));
	else if (type == 'd' || type == 'i')
		return (print_number(va_arg(argc, int)));
	else if (type == 'x')
		return (print_generic_number(va_arg(argc, int), "0123456789abcdef",
				ft_strlen("0123456789abcdef")));
	else if (type == 'X')
		return (print_generic_number(va_arg(argc, int), "0123456789ABCDEF",
				ft_strlen("0123456789ABCDEF")));
	else if (type == 'u')
		return (print_generic_number(va_arg(argc, unsigned int), "0123456789",
				ft_strlen("0123456789")));
	else if (type == '%')
		return (print_char('%'));
	return (1);
}
