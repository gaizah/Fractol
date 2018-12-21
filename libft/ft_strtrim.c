/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeckers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/10 18:08:22 by ldeckers          #+#    #+#             */
/*   Updated: 2015/04/10 18:13:17 by ldeckers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_len(char const *s, int i)
{
	int j;

	j = ft_strlen(s) - 1;
	while (ft_isspace(s[i]) == 1)
		i++;
	while (ft_isspace(s[j]) == 1)
		j--;
	if (j < i)
		return (0);
	return (j - i);
}

char			*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	int		len;
	char	*tmp;

	i = 0;
	j = 0;
	len = ft_len(s, i);
	if (!(tmp = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (ft_isspace(s[i]) == 1)
		i++;
	while (len >= 0)
	{
		tmp[j++] = s[i++];
		len--;
	}
	tmp[j] = '\0';
	return (tmp);
}
