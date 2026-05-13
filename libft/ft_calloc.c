/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkern <tkern@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 12:11:08 by tkern             #+#    #+#             */
/*   Updated: 2026/05/06 11:20:21 by tkern            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	cal;
	void	*mal;

	cal = nmemb * size;
	if (nmemb != 0 && cal / nmemb != size)
		return (NULL);
	mal = malloc(cal);
	if (mal == NULL)
		return (NULL);
	ft_memset(mal, 0, cal);
	return (mal);
}
