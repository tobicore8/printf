/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkern <tkern@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 12:14:29 by tkern             #+#    #+#             */
/*   Updated: 2026/05/21 18:20:06 by tkern            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_dispatch(const char *fmt, size_t *i, va_list *a, int *l)
{
	int	ret;

	ret = ft_handle_format(fmt[*i + 1], a);
	if (ret == -1)
		return (-1);
	*l += ret;
	(*i)++;
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	i;
	int		len;
	int		err;

	len = 0;
	i = 0;
	err = 0;
	va_start(args, format);
	while (!err && format[i] != '\0')
	{
		if (format[i] == '%')
			err = ft_dispatch(format, &i, &args, &len);
		else
		{
			write(1, &format[i], 1);
			len++;
		}
		i++;
	}
	va_end(args);
	if (err)
		return (-1);
	return (len);
}
