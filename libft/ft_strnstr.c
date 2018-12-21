/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeckers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/23 17:26:42 by ldeckers          #+#    #+#             */
/*   Updated: 2015/04/10 18:24:14 by ldeckers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_check(const char *s1, const char *s2, size_t i)
{
	size_t		j;

	j = 0;
	while (s2[j])
	{
		if (s2[j] == s1[i])
		{
			j++;
			i++;
		}
		else
			return (1);
	}
	return (0);
}

char			*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t i;

	if (!*s2)
		return ((char *)s1);
	i = 0;
	while (s1[i] != '\0')
	{
		if (ft_check(s1, s2, i) == 0 && i < n)
		{
			if (ft_strlen(s1 + i) < n)
				return ((char *)s1 + i);
			else
				return (NULL);
		}
		i++;
	}
	return (NULL);
}
