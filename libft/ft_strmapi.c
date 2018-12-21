/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeckers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/10 18:23:21 by ldeckers          #+#    #+#             */
/*   Updated: 2015/04/10 18:24:37 by ldeckers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	int		len;
	char	*temp;

	i = 0;
	len = ft_strlen(s);
	if (s == NULL)
		return (NULL);
	temp = ft_strnew(len);
	while (s[i])
	{
		temp[i] = f(s[i], i);
		i++;
	}
	temp[i] = '\0';
	return (temp);
}
