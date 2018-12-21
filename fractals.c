/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeckers <ldeckers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 18:12:26 by ldeckers          #+#    #+#             */
/*   Updated: 2017/03/16 18:40:58 by ldeckers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		mandelbrot(double r, double i, t_env *e)
{
	double	c_r;
	double	c_i;

	c_r = r + e->c_r;
	c_i = i + e->c_i;
	e->i = 0;
	while (e->i < e->it_max && (r * r + i * i < 4))
	{
		e->tmp_r = (r * r - i * i) + c_r;
		e->tmp_i = (2 * r * i) + c_i;
		r = e->tmp_r;
		i = e->tmp_i;
		e->i++;
	}
}

void		julia(double r, double i, t_env *e)
{
	double	c_r;
	double	c_i;

	c_r = -0.7 + e->c_r;
	c_i = 0.27015 + e->c_i;
	e->i = 0;
	while (e->i < e->it_max && (r * r + i * i < 4))
	{
		e->tmp_r = (r * r - i * i) + c_r;
		e->tmp_i = (2 * r * i) + c_i;
		r = e->tmp_r;
		i = e->tmp_i;
		e->i++;
	}
}

void		uterus(double r, double i, t_env *e)
{
	double	c_r;
	double	c_i;

	c_r = i + e->c_r;
	c_i = r + e->c_i;
	e->i = 0;
	while (e->i < e->it_max && (r * r + i * i < 4))
	{
		e->tmp_r = sin(r * r - i * i) + c_r;
		e->tmp_i = (2 * r * i) + c_i;
		r = e->tmp_r;
		i = e->tmp_i;
		e->i++;
	}
}

void		storm(double r, double i, t_env *e)
{
	double	c_r;
	double	c_i;

	c_r = -1 / 2 + e->c_r;
	c_i = 0.5 + e->c_i;
	e->i = 0;
	while (e->i < e->it_max && (r * r + i * i < 4))
	{
		e->tmp_r = sin(r * r - i * i) + c_r;
		e->tmp_i = (4 * r * i) + c_i;
		r = e->tmp_r;
		i = e->tmp_i;
		e->i++;
	}
}
