/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkern <tkern@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 18:20:19 by tkern             #+#    #+#             */
/*   Updated: 2026/05/21 18:24:14 by tkern            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count_digits(uintptr_t n, int base_len)
{
	int	count;

	count = 0;
	while (n != 0)
	{
		n /= base_len;
		count++;
	}
	return (count);
}

char	*ft_htoa(uintptr_t n, char *b)
{
	int		count;
	char	*str;
	int		base_len;

	if (n == 0)
		return (ft_strdup("0"));
	base_len = ft_strlen(b);
	count = ft_count_digits(n, base_len);
	str = malloc(count + 1);
	if (str == NULL)
		return (NULL);
	str[count] = '\0';
	while (n != 0)
	{
		count--;
		str[count] = b[n % base_len];
		n /= base_len;
	}
	return (str);
}
