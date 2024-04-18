/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_generic_number.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marikhac <marikhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 17:41:50 by marikhac          #+#    #+#             */
/*   Updated: 2024/02/26 13:53:57 by marikhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_generic_number(unsigned int n, char const *base, size_t base_len)
{
	if (n < base_len)
		return (print_char(base[n]));
	return (print_generic_number(n / base_len, base, base_len)
		+ print_generic_number(n % base_len, base, base_len));
}
