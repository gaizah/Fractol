/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeckers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 17:43:05 by ldeckers          #+#    #+#             */
/*   Updated: 2015/04/10 18:15:12 by ldeckers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_check(const char *s1, const char *s2, int i)
{
	int		j;

	j = 0;
	while (s2[j] != '\0')
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

char			*ft_strstr(const char *s1, const char *s2)
{
	int		i;

	if (!*s2)
		return ((char *)s1);
	if (!*s1)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		if (ft_check(s1, s2, i) == 0)
			return ((char *)s1 + i);
		i++;
	}
	return (0);
}
