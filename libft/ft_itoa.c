/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkern <tkern@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 11:07:07 by tkern             #+#    #+#             */
/*   Updated: 2026/04/29 17:11:31 by tkern            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_digits(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	int		neg;
	int		i;
	int		digits;
	char	*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	neg = (n < 0);
	if (n < 0)
		n = n * -1;
	digits = ft_count_digits(n);
	str = malloc(digits + neg + 1);
	if (str == NULL)
		return (NULL);
	str[digits + neg] = '\0';
	i = digits + neg -1;
	while (i >= neg)
	{
		str[i] = (n % 10) + '0';
		n = n / 10;
		i--;
	}
	if (neg)
		str[0] = '-';
	return (str);
}
