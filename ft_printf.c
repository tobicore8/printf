/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkern <tkern@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 12:14:29 by tkern             #+#    #+#             */
/*   Updated: 2026/05/20 16:35:38 by tkern            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_htoa(uintptr_t n, char *b)
{
	uintptr_t	tmp;
	int			count;
	char		*str;
	char		*base;
	int			base_len;

	base = b;
	base_len = ft_strlen(b);
	tmp = n;
	count = 0;
	if (n == 0)
		return (ft_strdup("0"));
	while (tmp != 0)
	{
		tmp /= base_len;
		count++;
	}
	str = malloc(count + 1);
	str[count] = '\0';
	while (n != 0)
	{
		count--;
		str[count] = base[n % base_len];
		n /= base_len;
	}
	return (str);
}
int	ft_handle_format(char specifier, va_list *args)
{
	char		c;
	char		*s;
	uintptr_t	tmp;
	int			tmp_len;

	if (specifier == 'c')
	{
		c = (char)va_arg(*args, int);
		write(1, &c, 1);
		return (1);
	}
	if (specifier == 's')
	{
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
	if (specifier == 'p')
	{
		tmp = (uintptr_t)va_arg(*args, void *);
		if (tmp == 0)
			return (write(1, "(nil)", 5));
		s = ft_htoa(tmp, BASE_LOW);
		tmp_len = ft_strlen(s);
		write(1, "0x", 2);
		write(1, s, tmp_len);
		free(s);
		return (tmp_len + 2);
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
		s = ft_htoa(va_arg(*args, unsigned int), BASE_DEC);
		tmp_len = ft_strlen(s);
		write(1, s, tmp_len);
		free(s);
		return (tmp_len);
	}
	if (specifier == 'x')
	{
		s = ft_htoa(va_arg(*args, unsigned int), BASE_LOW);
		tmp_len = ft_strlen(s);
		write(1, s, tmp_len);
		free(s);
		return (tmp_len);
	}
	if (specifier == 'X')
	{
		s = ft_htoa(va_arg(*args, unsigned int), BASE_UPPER);
		tmp_len = ft_strlen(s);
		write(1, s, tmp_len);
		free(s);
		return (tmp_len);
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

