/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeckers <ldeckers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 14:50:17 by ldeckers          #+#    #+#             */
/*   Updated: 2017/04/19 14:50:20 by ldeckers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <pthread.h>
#include <stdio.h>

void	*ft_four(void *env)
{
	int i;
	int j;
	t_env *e;

	e = env;
	j = 600;
	while (j < 800)
	{
		i = 0;
		while (i < e->mlx->height)
		{
			e->f(e->x1 + j * e->zoomx, e->y1 + i * e->zoomy, e);
			if (e->i < e->it_max)
				put_image(j, i, e, e->i * 0x00001010);
			else
				put_image(j, i, e, 0);
			i++;
		}
		j++;
	}
	pthread_exit(NULL);
	return (NULL);
}

void	*ft_three(void *env)
{
	int i;
	int j;
	t_env *e;

	e = env;
	j = 400;
	while (j < 600)
	{
		i = 0;
		while (i < e->mlx->height)
		{
			e->f(e->x1 + j * e->zoomx, e->y1 + i * e->zoomy, e);
			if (e->i < e->it_max)
				put_image(j, i, e, e->i * 0x00001010);
			else
				put_image(j, i, e, 0);
			i++;
		}
		j++;
	}
	pthread_exit(NULL);
	return (NULL);
}

void	*ft_scnd(void *env)
{
	int i;
	int j;
	t_env *e;

	e = env;
	j = 200;
	while (j < 400)
	{
		i = 0;
		while (i < e->mlx->height)
		{
			e->f(e->x1 + j * e->zoomx, e->y1 + i * e->zoomy, e);
			if (e->i < e->it_max)
				put_image(j, i, e, e->i * 0x00001010);
			else
				put_image(j, i, e, 0);
			i++;
		}
		j++;
	}
	pthread_exit(NULL);
	return (NULL);
}

void	*ft_first(void *env)
{
	int i;
	int j;
	t_env *e;

	e = env;
	j = 0;
	while (j < 200)
	{
		i = 0;
		while (i < e->mlx->height)
		{

			e->f(e->x1 + j * e->zoomx, e->y1 + i * e->zoomy, e);
			if (e->i < e->it_max)
				put_image(j, i, e, e->i * 0x00001010);
			else
				put_image(j, i, e, 0);
			i++;
		}
		j++;
	}
	pthread_exit(NULL);
	return (NULL);
}

void	ft_dup_env(t_env *e, t_env *env)
{
	env->mlx = e->mlx;
	env->a = e->a;
	env->color = e->color;
	env->it_max = e->it_max;
	env->i = e->i;
	env->old_r = e->old_r;
	env->old_i = e->old_i;
	env->mouse = e->mouse;
	env->x1 = e->x1;
	env->y1 = e->y1;
	env->tmp_r = e->tmp_r;
	env->tmp_i = e->tmp_i;
	env->c_r = e->c_r;
	env->c_i = e->c_i;
	env->f = e->f;
	env->zoomx = e->center_x / e->mlx->width;
	env->zoomy = e->center_y / e->mlx->height;
	env->step_x = e->step_x;
	env->step_y = e->step_y;
}
