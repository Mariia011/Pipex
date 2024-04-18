/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marikhac <marikhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 14:07:53 by marikhac          #+#    #+#             */
/*   Updated: 2024/02/26 13:55:51 by marikhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_ptr(size_t const nbr, char const *const base, size_t base_len)
{
	if (nbr < base_len)
	{
		return (print_char(base[nbr]));
	}
	return (print_ptr(nbr / base_len, base, base_len) + print_ptr(nbr
			% base_len, base, base_len));
}
