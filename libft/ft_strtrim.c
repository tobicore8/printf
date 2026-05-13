/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkern <tkern@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 14:11:21 by tkern             #+#    #+#             */
/*   Updated: 2026/04/28 15:41:02 by tkern            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	e;

	i = 0;
	e = ft_strlen(s1);
	while (i < e && ft_strchr(set, s1[i]))
		i++;
	while (e > 0 && ft_strchr(set, s1[e -1]))
		e--;
	return (ft_substr(s1, i, e - i));
}
