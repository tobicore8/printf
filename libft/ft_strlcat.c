/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkern <tkern@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 12:01:04 by tkern             #+#    #+#             */
/*   Updated: 2026/05/07 11:52:44 by tkern            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dst_i;
	size_t	src_l;
	size_t	len;

	dst_i = ft_strlen(dst);
	src_l = ft_strlen(src);
	i = 0;
	len = dst_i + src_l;
	if (size <= dst_i)
		return (src_l + size);
	while (src[i] != '\0' && dst_i + 1 < size)
	{
		dst[dst_i] = src[i];
		dst_i++;
		i++;
	}
	dst[dst_i] = '\0';
	return (len);
}
