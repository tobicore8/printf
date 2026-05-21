/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_functions_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkern <tkern@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 15:08:53 by tkern             #+#    #+#             */
/*   Updated: 2026/05/21 16:41:04 by tkern            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_uint(va_list *args)
{
	char	*s;
	int		tmp_len;

	s = ft_htoa(va_arg(*args, unsigned int), BASE_DEC);
	if (s == NULL)
		return (-1);
	tmp_len = ft_strlen(s);
	write(1, s, tmp_len);
	free(s);
	return (tmp_len);
}

int	ft_print_hex(va_list *args, char specifier)
{
	char	*s;
	int		tmp_len;

	if (specifier == 'x')
		s = ft_htoa(va_arg(*args, unsigned int), BASE_LOW);
	else
		s = ft_htoa(va_arg(*args, unsigned int), BASE_UPPER);
	if (s == NULL)
		return (-1);
	tmp_len = ft_strlen(s);
	write(1, s, tmp_len);
	free(s);
	return (tmp_len);
}
