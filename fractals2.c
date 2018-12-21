/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeckers <ldeckers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 15:03:27 by ldeckers          #+#    #+#             */
/*   Updated: 2017/04/12 15:03:31 by ldeckers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		lustre(double r, double i, t_env *e)
{
	double	c_r;
	double	c_i;

	c_r = i + e->c_r;
	c_i = r + e->c_i;
	e->i = 0;
	while (e->i < e->it_max && (r * r + i * i < 4))
	{
		e->tmp_r = fabs(r * r - i * i) + c_r;
		e->tmp_i = (3 * r * i) + c_i;
		r = e->tmp_r;
		i = e->tmp_i;
		e->i++;
	}
}

void		ferie(double r, double i, t_env *e)
{
	double	c_r;
	double	c_i;

	c_r = i + e->c_r;
	c_i = r + e->c_i;
	e->i = 0;
	while (e->i < e->it_max && (r * r + i * i < 4))
	{
		e->tmp_r = fabs(r * r - i * i) + c_r;
		e->tmp_i = sin(15 * r * i) + c_i;
		r = e->tmp_r;
		i = e->tmp_i;
		e->i++;
	}
}

void		burning_ship(double r, double i, t_env *e)
{
	double	c_r;
	double	c_i;

	c_r = r + e->c_r;
	c_i = i + e->c_i;
	e->i = 0;
	while (e->i < e->it_max && (r * r + i * i < 4))
	{
		e->tmp_r = (r * r - i * i) + c_r;
		e->tmp_i = (2 * fabs(r) * fabs(i)) + c_i;
		r = e->tmp_r;
		i = e->tmp_i;
		e->i++;
	}
}
