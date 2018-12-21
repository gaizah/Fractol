/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeckers <ldeckers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 17:06:17 by ldeckers          #+#    #+#             */
/*   Updated: 2017/03/08 19:48:56 by ldeckers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

void	ft_error(int e)
{
	if (e == 1)
		write(2, ARGUMENT_ERROR, sizeof(ARGUMENT_ERROR) - 1);
	if (e == 2)
		write(2, MALLOC_ERROR, sizeof(MALLOC_ERROR) - 1);
	if (e == 3)
	{
		ft_putendl("");
		ft_putendl("Usage: ./fractol [number of fractal]");
		ft_putendl("	1 - mandelbrot");
		ft_putendl("	2 - julia");
		ft_putendl("	3 - uterus");
		ft_putendl("	4 - storm");
		ft_putendl("	5 - lustre");
		ft_putendl("	6 - ferie");
		ft_putendl("	7 - burning_ship");
		ft_putendl("");
	}
	exit(0);
}
