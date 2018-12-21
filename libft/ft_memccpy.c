/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeckers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 14:55:14 by ldeckers          #+#    #+#             */
/*   Updated: 2014/11/21 21:23:12 by ldeckers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	d;
	unsigned char	*tdst;
	unsigned char	*tsrc;

	d = (unsigned char)c;
	tdst = (unsigned char *)dst;
	tsrc = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		tdst[i] = tsrc[i];
		if (tsrc[i] == d)
			return ((void *)&tdst[i + 1]);
		i++;
	}
	return (NULL);
}
