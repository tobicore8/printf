/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkern <tkern@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 15:05:54 by tkern             #+#    #+#             */
/*   Updated: 2026/05/21 16:43:11 by tkern            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(va_list *args)
{
	char	c;

	c = (char)va_arg(*args, int);
	write(1, &c, 1);
	return (1);
}

int	ft_print_str(va_list *args)
{
	char	*s;
	int		tmp_len;

	s = va_arg(*args, char *);
	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	tmp_len = ft_strlen(s);
	write(1, s, tmp_len);
	return (tmp_len);
}

int	ft_print_ptr(va_list *args)
{
	char		*s;
	int			tmp_len;
	uintptr_t	tmp;

	tmp = (uintptr_t)va_arg(*args, void *);
	if (tmp == 0)
		return (write(1, "(nil)", 5));
	s = ft_htoa(tmp, BASE_LOW);
	if (s == NULL)
		return (-1);
	tmp_len = ft_strlen(s);
	write(1, "0x", 2);
	write(1, s, tmp_len);
	free(s);
	return (tmp_len + 2);
}

int	ft_print_int(va_list *args)
{
	char	*s;
	int		tmp_len;

	s = ft_itoa(va_arg(*args, int));
	if (s == NULL)
		return (-1);
	tmp_len = ft_strlen(s);
	write(1, s, tmp_len);
	free(s);
	return (tmp_len);
}
