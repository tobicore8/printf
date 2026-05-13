/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkern <tkern@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 15:11:19 by tkern             #+#    #+#             */
/*   Updated: 2026/04/24 14:34:29 by tkern            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	len_little;

	i = 0;
	len_little = ft_strlen(little);
	if (little[0] == '\0')
		return ((char *)big);
	while (i < len && big[i] != '\0' && (len - i >= len_little))
	{
		if (0 == ft_strncmp(big + i, little, len_little))
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}
