/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeckers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 17:31:57 by ldeckers          #+#    #+#             */
/*   Updated: 2015/04/03 11:24:23 by ldeckers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_len(int n)
{
	size_t j;

	j = 0;
	while (n != 0)
	{
		j++;
		n /= 10;
	}
	return (j);
}

char	*ft_itoa(int n)
{
	char	*temp;
	int		nbr;
	int		neg;

	if (n == -2147483648 || n == 0)
		return (ft_strdup((n == 0) ? "0" : "-2147483648"));
	neg = 0;
	nbr = ft_len(n);
	if (n < 0)
	{
		neg = 1;
		n *= -1;
	}
	if (neg == 0)
		nbr--;
	if (!(temp = (char*)malloc(sizeof(char) * (nbr + 1))))
		return (NULL);
	while (n > 0)
	{
		temp[nbr--] = (n % 10) + 48;
		n /= 10;
	}
	if (neg > 0)
		temp[0] = '-';
	return (temp);
}
