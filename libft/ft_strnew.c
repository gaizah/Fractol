/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeckers <ldeckers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 17:23:21 by ldeckers          #+#    #+#             */
/*   Updated: 2017/02/14 10:54:35 by ldeckers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;
	int		n;

	n = (int)size;
	str = malloc(size);
	if (str == NULL)
		return (NULL);
	while (n < (int)size - 1)
	{
		str[n] = '\0';
		n++;
	}
	return (str);
}
