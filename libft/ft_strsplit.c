/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeckers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 20:35:36 by ldeckers          #+#    #+#             */
/*   Updated: 2015/04/10 18:22:34 by ldeckers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_string(char const *s, char c)
{
	int		i;
	int		word;

	i = 0;
	word = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			word++;
			while (s[i] && s[i] == c)
				i++;
		}
		else
			i++;
	}
	return (word);
}

static int		ft_nbr(char const *s, char c, int i)
{
	int		nbr;

	nbr = 0;
	while (s[i] && s[i] != c)
	{
		i++;
		nbr++;
	}
	return (nbr);
}

char			**ft_strsplit(char const *s, char c)
{
	int			i;
	int			j;
	int			k;
	char		**tab;

	i = 0;
	j = 0;
	if (!(tab = (char **)malloc(sizeof(char*) * (ft_string(s, c) + 1))))
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			k = 0;
			if (!(tab[j] = (char*)malloc(sizeof(char) * (ft_nbr(s, c, i) + 1))))
				return (NULL);
			while (s[i] != c && s[i] != '\0')
				tab[j][k++] = s[i++];
			tab[j++][k++] = '\0';
		}
		else
			i++;
	}
	tab[j] = (NULL);
	return (tab);
}
