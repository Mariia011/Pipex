/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marikhac <marikhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:42:52 by marikhac          #+#    #+#             */
/*   Updated: 2024/04/11 15:03:35 by marikhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>

int	type_size(va_list argc, char type);
int	print_char(char c);
int	ft_putstr(char const *str);
int	ft_printf(const char *str, ...);
int	print_string(char *str);
int	print_number(int n);
int	print_generic_number(unsigned int n, char const *base, size_t base_len);
int	print_ptr(size_t const nbr, char const *const base, size_t base_len);

#endif
