/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkern <tkern@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 18:19:20 by tkern             #+#    #+#             */
/*   Updated: 2026/05/21 18:28:50 by tkern            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_format(char specifier, va_list *args)
{
	if (specifier == 'c')
		return (ft_print_char(args));
	if (specifier == 's')
		return (ft_print_str(args));
	if (specifier == 'p')
		return (ft_print_ptr(args));
	if (specifier == 'd' || specifier == 'i')
		return (ft_print_int(args));
	if (specifier == 'u')
		return (ft_print_uint(args));
	if (specifier == 'x' || specifier == 'X')
		return (ft_print_hex(args, specifier));
	if (specifier == '%')
		return (write(1, "%", 1));
	return (0);
}
