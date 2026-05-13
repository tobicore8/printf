/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkern <tkern@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 10:32:57 by tkern             #+#    #+#             */
/*   Updated: 2026/04/28 12:00:45 by tkern            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs;
	size_t	i;
	size_t	real_len;

	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	real_len = ft_strlen(s + start);
	if (real_len > len)
		real_len = len;
	subs = malloc(real_len + 1);
	if (subs == NULL)
		return (NULL);
	s = s + start;
	i = 0;
	while (i < real_len && *s != '\0')
	{
		subs[i] = *s;
		i++;
		s++;
	}
	subs[i] = '\0';
	return (subs);
}
