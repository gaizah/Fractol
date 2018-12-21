/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeckers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 16:34:08 by ldeckers          #+#    #+#             */
/*   Updated: 2015/04/10 19:28:00 by ldeckers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memalloc(size_t size)
{
	void	*memory;
	char	*explorer;

	if (!size || !(memory = (void *)malloc(size)))
		return (NULL);
	explorer = (char *)memory;
	while (size--)
		*explorer++ = '\0';
	return (memory);
}
