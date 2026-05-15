/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkern <tkern@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 12:14:29 by tkern             #+#    #+#             */
/*   Updated: 2026/05/15 15:51:00 by tkern            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_htoa(uintptr_t s)
{
	int		i;
	int		count;
	char	*str;

	i = 0;
	count = 0;


	jay! len = write(1, str, ft_strlen(str))
}

int	ft_handle_format(char specifier, va_list *args)
{
	char	c;
	char	*s;
	int		tmp_len;

	if (specifier == 'c')
	{
		c = (char)va_arg(*args, int);
		write(1, &c, 1);
		return (1);
	}
	if (specifier == 's')
	{
		s = (char)va_arg(*args, char);
		if (s == NULL)
		{
			write(1, "(null)", 6);
			return (6);
		}
		tmp_len = ft_strlen(s);
		write(1, s, tmp_len);
		return (tmp_len);
	}
	if (specifier == 'p')
	{
		s = ft_htoa(va_arg(*args, void *));
		tmp_len = ft_strlen(s);
		write(1, s, tmp_len);
		free(s);
		return (tmp_len);
	}
	if (specifier == 'd' || specifier == 'i')
	{
		s = ft_itoa(va_arg(*args, int));
		tmp_len = ft_strlen(s);
		write(1, s, tmp_len);
		free(s);
		return (tmp_len);
	}
	if (specifier == 'u')
	{
		s = ft_itoa(va_arg(*args, unsigned int));
		tmp_len = ft_strlen(s);
		write(1, s, tmp_len);
		free(s);
		return (tmp_len);
	}
	if (specifier == 'x')
	{
		// ...
	}
	if (specifier == 'X')
	{
		// ...
	}
	if (specifier == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	i;
	int		len;

	len = 0;
	i = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			len += ft_handle_format(format[i + 1], &args);
			i++;
		}
		else
		{
			write(1, &format[i], 1);
			len++;
		}
		i++;
	}
	va_end(args);
	return (len);
}

