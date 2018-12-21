/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeckers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/25 17:13:33 by ldeckers          #+#    #+#             */
/*   Updated: 2015/04/10 18:27:56 by ldeckers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int		size_dst;
	unsigned int		size_src;
	unsigned int		temp_size;

	temp_size = size;
	size_dst = 0;
	size_src = ft_strlen(src);
	while (size != 0 && *dst != '\0')
	{
		size--;
		size_dst++;
		dst++;
	}
	if (size == 0)
		return (size_src + temp_size);
	while (size > 1 && *src != '\0')
	{
		*dst++ = *src++;
		size--;
	}
	*dst = '\0';
	return (size_dst + size_src);
}
