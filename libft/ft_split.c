/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkern <tkern@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 15:48:52 by tkern             #+#    #+#             */
/*   Updated: 2026/04/30 18:46:46 by tkern            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *s, char c)
{
	int	i;
	int	cou;

	cou = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (i == 0 || s[i -1] == c))
			cou++;
		i++;
	}
	return (cou);
}

static char	*ft_get_word(char const *s, char c, int start)
{
	size_t	i;

	i = start;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
	}
	i = i - start;
	return (ft_substr(s, start, i));
}

static void	ft_free_result(char **result, int count)
{
	while (count > 0)
	{
		count--;
		free(result[count]);
	}
	free(result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		i;
	int		x;

	i = 0;
	x = 0;
	result = malloc((ft_count_words(s, c) + 1) * sizeof(char *));
	if (result == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] != c && (i == 0 || s[i -1] == c))
		{
			result[x] = ft_get_word(s, c, i);
			if (result[x] == NULL)
			{
				ft_free_result(result, x);
				return (NULL);
			}
			x++;
		}
		i++;
	}
	result[x] = NULL;
	return (result);
}
