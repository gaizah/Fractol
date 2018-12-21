/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeckers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 16:49:52 by ldeckers          #+#    #+#             */
/*   Updated: 2015/02/17 19:07:15 by ldeckers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t		i;
	char		*ts1;
	char		*ts2;

	i = 0;
	ts1 = (char *)s1;
	ts2 = (char *)s2;
	while (i < n)
	{
		if (ts1[i] != ts2[i])
			return ((unsigned char)ts1[i] - (unsigned char)ts2[i]);
		i++;
	}
	return (0);
}
