/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeckers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 23:42:57 by ldeckers          #+#    #+#             */
/*   Updated: 2015/04/10 18:14:05 by ldeckers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	char		*temp;

	i = start + len;
	if (s == NULL)
		return (NULL);
	if (i > ft_strlen(s))
		return (NULL);
	temp = (char*)malloc(sizeof(char) * len + 1);
	i = 0;
	while (i < len)
	{
		temp[i] = s[start++];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}
