/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkern <tkern@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 12:14:29 by tkern             #+#    #+#             */
/*   Updated: 2026/05/13 16:23:37 by tkern            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	i;
	int		len;
	char	c;

	len = 0;
	i = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == 'c')
			{
				c = (char)va_arg(args, int);
				write(1, &c, 1);
				len++;
			}
			if (format[i + 1] == 'i' || format[i + 1] == 'd')
			{
				char *s = ft_itoa(va_arg(args, int));
				len += ft_strlen(s);
				write(1, s, ft_strlen(s));
				free(s);
				i++
			}
		}
		else
		{ 
		write(1, &format[i], 1);
		}
		i++;
		len++
	}
	va_end(args);
}

